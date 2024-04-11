#include<cstdio>
#include<algorithm> // lgv
using namespace std;
#define Mod 1000000007
#define LL unsigned long long
int n,m,k;
LL c[500001];
int S[500001],T[500001];
LL X[500001],P[500001];
bool cmp(int i,int j){return X[i]<X[j];}
int f[500001];
int ff(int x){return f[x]?f[x]=ff(f[x]):x;}
int Ans;
int qPow(int b,int e){int a=1;for(;e;e>>=1,b=(LL)b*b%Mod)if(e&1)a=(LL)a*b%Mod;return a;}
int main(){
	scanf("%d%d%d",&n,&m,&k);
	int _2n=qPow(2,n);
	for(int i=1;i<=n;++i) scanf("%lld",c+i);
	for(int i=1;i<=m;++i) scanf("%d%d",S+i,T+i);
	for(int i=1;i<=m;++i) X[i]=c[S[i]]^c[T[i]], P[i]=i;
	Ans=(LL)(1ll<<k)%Mod*_2n%Mod;
	sort(P+1,P+m+1,cmp);
	for(int i=1;i<=m;){
		int j=i, cnt=n;
		f[S[P[i]]]=T[P[i]]; --cnt;
		while(j<m&&X[P[j+1]]==X[P[j]]){
			++j;
			if(ff(S[P[j]])!=ff(T[P[j]])){
				f[ff(S[P[j]])]=ff(T[P[j]]);
				--cnt;
			}
		}
		Ans=((LL)Ans-_2n+qPow(2,cnt)+Mod)%Mod;
		while(i<=j) f[S[P[i]]]=f[T[P[i]]]=0, ++i;
	} printf("%d",Ans);
	return 0;
}