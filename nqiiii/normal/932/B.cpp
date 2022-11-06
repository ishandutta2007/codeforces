#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1000000;
int f[maxn+10],g[maxn+10],sum[maxn+10][10],q;
int main(){
	f[0]=1;
	for(int i=1;i<=maxn;++i){
		f[i]=f[i/10]*max(i%10,1);
		g[i]=i<10?i:g[f[i]];
		sum[i][g[i]]=1;
		for(int j=1;j<=9;++j) sum[i][j]+=sum[i-1][j];
	}
	scanf("%d",&q);
	for(;q--;){
		int l,r,k; scanf("%d%d%d",&l,&r,&k);
		printf("%d\n",sum[r][k]-sum[l-1][k]);
	}
}