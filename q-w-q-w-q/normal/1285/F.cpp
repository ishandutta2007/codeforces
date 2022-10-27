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
char ch,ss[1<<17],*A=ss,*B=ss;
inline char gc(){
	return A==B&&(B=(A=ss)+fread(ss,1,1<<17,stdin),A==B)?EOF:*A++;
}
template <typename _Tp> inline void rd(_Tp &x);
template <typename _Tq> inline void wr(_Tq x);
template <typename _Tp> inline _Tp mx(_Tp x,_Tp y);
template <typename _Tp> inline _Tp mn(_Tp x,_Tp y);
int n,x,k,tp;
int p[1000001],s,mobius[1000001];
int cnt[1000001];
vector<int>qwq[1000001];
bool a[1000001],ok[1000001];
int st[1000001],top;
ll ans;
inline void del(int x){
	for(int j=qwq[x].size()-1;~j;j--) cnt[qwq[x][j]]--;
}
inline int gcd(int a,int b){
	while(a%b){
		tp=b;
		b=a%b;
		a=tp;
	}
	return b;
}
int main(){
	rd(n);
	for(int i=1;i<=n;i++)
	rd(x),a[x]=1;
	for(int i=1000000;i;i--){
		for(int j=100000/i*i;j;j-=i){
			if(a[j]) a[i]=1,qwq[j].push_back(i);
		}
	}
	mobius[1]=1;
	for(int i=2;i<=1000000;i++){
		if(!ok[i]) p[++s]=i,mobius[i]=-1;
		for(int j=1;j<=s&&i*p[j]<=1000000;j++){
			ok[i*p[j]]=1;
			if(i%p[j]==0){
				mobius[i*p[j]]=0;
				break;
			}
			mobius[i*p[j]]=-mobius[i];
		}
	}
	for(int i=1000000;i;i--){
		if(!a[i]) continue;
		ans=mx(ans,0ll+i);
		k=0;
		for(int j=qwq[i].size()-1;~j;j--){
			k+=mobius[qwq[i][j]]*cnt[qwq[i][j]];
			cnt[qwq[i][j]]++;
		}
		while(k){
			if(gcd(st[top],i)==1) ans=mx(ans,1ll*st[top]*i),k--;
			del(st[top--]);
		}
		st[++top]=i;
	}
	wr(ans);
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