#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<iomanip>
#include<cstdlib>
#include<ctime>
#define _t putchar(32)
#define _e putchar(10)
#define inf 2147483647
#define ine -2147483647
#define lb(x) (x)&(-x)
using namespace std;
typedef long long ll;
bool o;
char ch,ssss[1<<17],*A=ssss,*B=ssss;
inline char gc(){
    return A==B&&(B=(A=ssss)+fread(ssss,1,1<<17,stdin),A==B)?EOF:*A++;
}
template <typename _Tp> inline void rd(_Tp &x);
template <typename _Tp> inline void wr(_Tp x);
template <typename _Tp> inline _Tp mx(_Tp x,_Tp y);
template <typename _Tp> inline _Tp mn(_Tp x,_Tp y);
int n,m;
int a[100001],t[100001];
string k;
map<string,int>q;
map<string,int>::iterator it;
int tp,s,x[100001],ts,f[2000001],p,fr,ans;
bool ok[41][41],c;
int ban[41];
inline void dfs(int i){
	if(i>ts){
		f[tp]=p;
		return;
	}
	tp<<=1;
	dfs(i+1);
	if(!ban[a[i]]){
		tp++,p++;
		for(int j=a[i]+1;j<=ts;j++)
		if(ok[a[i]][j]) ban[j]++;
		dfs(i+1);
		for(int j=a[i]+1;j<=ts;j++)
		if(ok[a[i]][j]) ban[j]--;
		p--;
	}
	tp>>=1;
}
inline void fix(int i){
	for(int j=1;j<i;j<<=1)
	if(i&j) f[i]=mx(f[i],f[i-j]);
}
inline void find_ans(){
	tp=0;
	for(int i=1;i<=ts;i++){
		tp<<=1;
		if(!ban[a[i]]) tp++;
	}
	ans=mx(ans,f[tp]+p);
}
inline void find(int i){
	if(i==ts){
		find_ans();
		return;
	}
	find(i-1);
	if(!ban[a[i]]){
		p++;
		for(int j=a[i]-1;j;j--)
		if(ok[a[i]][j]) ban[j]++;
		find(i-1);
		for(int j=a[i]-1;j;j--)
		if(ok[a[i]][j]) ban[j]--;
		p--;
	}
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]^1){
			std::cin>>k;
			it=q.find(k);
			if(it==q.end()) q[k]=++s;
			t[i]=q[k];
		}
	}
	for(int i=1;i<=n;){
		if(a[i]==1){
			i++;
			continue;
		}
		x[x[0]=1]=t[i];
		for(i++;i<=n&&a[i]==2;i++)
		x[++x[0]]=t[i];
		sort(x+1,x+1+x[0]);
		x[0]=unique(x+1,x+1+x[0])-x-1;
		for(int j=1;j<x[0];j++)
		for(int k=j+1;k<=x[0];k++)
		ok[x[j]][x[k]]=ok[x[k]][x[j]]=1;
	}
	s=0;
	for(int i=1;i<=m;i++){
		c=1;
		for(int j=1;j<=m&&c;j++)
		if(ok[i][j]) c=0;
		if(c) fr++;
		else a[++s]=i;
	}
	ts=s>>1;
	dfs(1);
	for(int i=1;i<(1<<ts);i++)
	if(!f[i]) fix(i);
	find(s);
	wr(ans+fr);
}
template <typename _Tp>
    inline void rd(_Tp &x){
    	o=0;
        x=0;
      	while (ch^45&&(ch<48||ch>57)) ch=gc();
      	if(ch==45)o=1,ch=gc();
        while(ch>47&&ch<58){
            x=(x<<1)+(x<<3)+(ch^48);
            ch=gc();
        }
      	if(o) x=-x;
 	}
template <typename _Tp>
    inline void wr(_Tp x){
        if(x<0) x=-x,putchar(45);
        if(x<10){
            putchar(x+48);
            return;
        }
        wr(x/10);
        putchar(x%10+48);
    }
template <typename _Tp>
    inline _Tp mx(_Tp x,_Tp y){
        return x>y?x:y;
    }
template <typename _Tp>
    inline _Tp mn(_Tp x,_Tp y){
        return x<y?x:y;
    }
template <typename _Tp>
    inline _Tp sp(_Tp &x,_Tp &y){
        _Tp t=x;
        x=y;
        y=t;
    }