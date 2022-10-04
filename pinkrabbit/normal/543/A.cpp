#include<bits/stdc++.h>
#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define F2(i,a,b) for(int i=(a);i<(b);++i)
#define dF(i,a,b) for(int i=(a);i>=(b);--i)
#define dF2(i,a,b) for(int i=(a);i>(b);--i)
#define dF3(i,a,b) for(int i=(a)-1;i>=(b);--i)
using namespace std;typedef long long ll;typedef double ld;int INF=0x3f3f3f3f;int INF2=0x7fffffff;ll LNF=0x3f3f3f3f3f3f3f3f;ll LNF2=0x7fffffffffffffff;

int n,m,b,Mod;
int a[501],Ans;
int f[501][501];
int g[501][501];

int main(){
	scanf("%d%d%d%d",&n,&m,&b,&Mod);
	for(int i=1;i<=n;++i) scanf("%d",a+i);
	f[0][0]=1%Mod;
	for(int i=1;i<=n;++i){
		for(int j=0;j<=m;++j)
			for(int k=0;k<=b;++k){
				g[j][k]=f[j][k];
				if(j-1>=0&&k-a[i]>=0) g[j][k]=(g[j][k]+g[j-1][k-a[i]])%Mod;
			}
		for(int j=0;j<=m;++j)
			for(int k=0;k<=b;++k)
				f[j][k]=g[j][k];
	}
	for(int k=0;k<=b;++k) Ans=(Ans+f[m][k])%Mod;
	printf("%d",Ans);
	return 0;
}