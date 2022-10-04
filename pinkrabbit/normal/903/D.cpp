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
#include<iomanip>
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
int a[200001],b[200001],I[200001],buk[400010];
ll sum[200001];
bool ff;
long long Ans1,Ans2;
inline bool cmp(int p1,int p2){return a[p1]<a[p2];}
int main(){
	scanf("%d",&n);
	F(i,1,n) scanf("%d",a+i), I[i]=i;
	F(i,1,n) sum[i]=sum[i-1]+a[i];
	sort(I+1,I+n+1,cmp);
	int lst=-1, lst2=-1;
	F(i,1,n){
		b[I[i]]=a[I[i]]>lst?(a[I[i]]>lst+1?lst2+2:lst2+1):lst2;
		lst=a[I[i]]; lst2=b[I[i]];
	}
	F(i,1,n){
		if(ff==0){
			Ans2+=1ll*(i-1)*a[i]-sum[i-1]+buk[b[i]+1]-buk[b[i]-1];
			if(Ans2>=1000000000000000000ll) Ans2-=1000000000000000000ll, ++Ans1;
			if(Ans2<0) Ans2=1000000000000000000ll+Ans2, --Ans1;
			if(Ans1<0) ff=1, Ans1=0, Ans2=1000000000000000000ll-Ans2;
		}
		else{
			Ans2-=1ll*(i-1)*a[i]-sum[i-1]+buk[b[i]+1]-buk[b[i]-1];
			if(Ans2>=1000000000000000000ll) Ans2-=1000000000000000000ll, ++Ans1;
			if(Ans2<0) Ans2=1000000000000000000ll+Ans2, --Ans1;
			if(Ans1<0) ff=0, Ans1=0, Ans2=1000000000000000000ll-Ans2;
		}
		++buk[b[i]];
	}
	if(ff&&(Ans1||Ans2)) putchar('-');
	if(Ans1) printf("%I64d%018I64d",Ans1,Ans2);
	else printf("%I64d",Ans2);
	return 0;
}