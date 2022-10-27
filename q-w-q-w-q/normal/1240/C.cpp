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
#define _t putchar(32)
#define _e putchar(10)
#define inf 2147483647
#define ine -2147483647
#define lb(x) ((x)&(-x))
#define sp(x,y) x^=y^=x^=y
using namespace std;
typedef long long ll;
bool o;
char chh,ss[1<<17],*A=ss,*B=ss;
inline char gc(){
	return A==B&&(B=(A=ss)+fread(ss,1,1<<17,stdin),A==B)?EOF:*A++;
}
template <typename _Tp> inline void rd(_Tp &x);
template <typename _Tp> inline void wr(_Tp x);
template <typename _Tp> inline _Tp mx(_Tp x,_Tp y);
template <typename _Tp> inline _Tp mn(_Tp x,_Tp y);
int t,n,kk,x,y,z,cnt;
int f[500001],to[1000001],ne[1000001],v[1000001],d[500001];
ll dp[500001][2],qwq[500001];
int qwqwq[500001],l[500001],r[500001];
inline bool cmp(int i,int j){
	return qwq[i]>qwq[j];
}
inline void link(int x,int y,int z,int k){
	to[k]=y;
	v[k]=z;
	ne[k]=f[x];
	f[x]=k;
}
inline void dfs(int i,int fa){
	if(i==1){
		l[i]=1,r[i]=d[1];
		cnt=d[1];
	}
	else{
		l[i]=cnt+1,r[i]=cnt+d[i]-1;
		cnt+=d[i]-1;
	}
	int tp=0;
	dp[i][0]=dp[i][1]=0;
	for(int k=f[i];k;k=ne[k]){
		if(to[k]==fa) continue;
		dfs(to[k],i);
		qwq[to[k]]=dp[to[k]][0]+v[k]-dp[to[k]][1];
		qwqwq[tp+l[i]]=to[k];
		tp++;
	}
	sort(qwqwq+l[i],qwqwq+1+r[i],cmp);
	for(tp=1;tp<=kk&&l[i]+tp-1<=r[i]&&qwq[qwqwq[tp+l[i]-1]]>0;tp++)
	dp[i][1]+=qwq[qwqwq[tp+l[i]-1]]+dp[qwqwq[tp+l[i]-1]][1];
	while(tp+l[i]-1<=r[i]){
		dp[i][1]+=dp[qwqwq[tp+l[i]-1]][1];
		tp++;
	}
	for(tp=1;tp<kk&&l[i]+tp-1<=r[i]&&qwq[qwqwq[tp+l[i]-1]]>0;tp++)
	dp[i][0]+=qwq[qwqwq[tp+l[i]-1]]+dp[qwqwq[tp+l[i]-1]][1];
	while(tp+l[i]-1<=r[i]){
		dp[i][0]+=dp[qwqwq[tp+l[i]-1]][1];
		tp++;
	}
}
int main(){
	rd(t);
	while(t--){
		rd(n);
		rd(kk);
		for(int i=1;i<n;i++){
			rd(x);
			rd(y);
			rd(z);
			link(x,y,z,(i<<1)-1);
			link(y,x,z,i<<1);
			d[x]++,d[y]++;
		}
		dfs(1,0);
		wr(mx(dp[1][0],dp[1][1])),_e;
		for(int i=1;i<=n;i++)
		f[i]=d[i]=0;
	}
}
template <typename _Tp>
    inline void rd(_Tp &x){
    	o=0;
        x=0;
      	while (chh^45&&(chh<48||chh>57)) chh=gc();
      	if(chh==45)o=1,chh=gc();
        while(chh>47&&chh<58){
			x=(x<<1)+(x<<3)+(chh^48);
			chh=gc();
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