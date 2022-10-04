#include<cstdio>
#include<cstring>
#include<algorithm>
#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define F2(i,a,b) for(int i=(a);i<(b);++i)
#define dF(i,a,b) for(int i=(a);i>=(b);--i)
#define dF2(i,a,b) for(int i=(a);i>(b);--i)
#include<cmath>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<set>
#include<map>
#define ll long long
#define eF(i,u) for(int i=h[u];i;i=nxt[i])
using namespace std;
const int INF=0x3f3f3f3f;
inline int Gcd(int X,int Y){return Y?Gcd(Y,X%Y):X;}
inline ll Gcd(ll X,ll Y){return Y?Gcd(Y,X%Y):X;}
inline int Max(int X,int Y){return X<Y?Y:X;}
inline int Min(int X,int Y){return X<Y?X:Y;}
inline ll Max(ll X,ll Y){return X<Y?Y:X;}
inline ll Min(ll X,ll Y){return X<Y?X:Y;}
inline int Pow(int base,ll exp,int _mod){int _ans=1;for(;exp;exp>>=1,base=(ll)base*base%_mod)exp&1?_ans=(ll)_ans*base%_mod:0;return _ans;}
inline ll Pow(ll base,ll exp,ll _mod){ll _ans=1;for(;exp;exp>>=1,base=base*base%_mod)exp&1?_ans=_ans*base%_mod:0;return _ans;}
int n,q;
int l[100001],r[100001],Ans[10001];
int que[100001],L,R;
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		L=1, R=0;
		scanf("%d",&n);
		memset(Ans,0,sizeof Ans);
		F(i,1,n) scanf("%d%d",l+i,r+i);
		int i=1;
		F(t,1,5000){
			while(l[i]==t) que[++R]=i, ++i;
			while(L<=R&&r[que[L]]<t) ++L;
			if(L<=R) Ans[que[L++]]=t;
		}
		F(j,1,n) printf("%d ",Ans[j]); puts("");
	}
	return 0;
}