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
inline int Abs(int X){return X<0?-X:X;}
inline int Gcd(int X,int Y){return Y?Gcd(Y,X%Y):X;}
inline ll Gcd(ll X,ll Y){return Y?Gcd(Y,X%Y):X;}
inline int Max(int X,int Y){return X<Y?Y:X;}
inline int Min(int X,int Y){return X<Y?X:Y;}
inline ll Max(ll X,ll Y){return X<Y?Y:X;}
inline ll Min(ll X,ll Y){return X<Y?X:Y;}
inline int Pow(int base,ll exp,int _mod){int _ans=1;for(;exp;exp>>=1,base=(ll)base*base%_mod)exp&1?_ans=(ll)_ans*base%_mod:0;return _ans;}
inline ll Pow(ll base,ll exp,ll _mod){ll _ans=1;for(;exp;exp>>=1,base=base*base%_mod)exp&1?_ans=_ans*base%_mod:0;return _ans;}
int n,q,Ans;
int a[100001],b[100001];
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		Ans=0;
		scanf("%d%d",&n,&q);
		F(i,1,q) scanf("%d",a+i);
		F(i,1,n){
			int k=999999999;
			F(j,1,q){
				k=Min(k,Abs(i-a[j]));
			}
			Ans=Max(Ans,k);
		}
		printf("%d\n",Ans+1);
	}
	return 0;
}