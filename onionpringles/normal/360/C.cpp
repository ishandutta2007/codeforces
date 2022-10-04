#include <bits/stdc++.h>
using namespace std;
const int mod=1000000007;
#define mul(x,y) ((long long)(x)*(y)%mod)
const int N=2010;
int d[N][N],e[N][N];
char b[N];
int main(){
	int n,k;scanf("%d%d",&n,&k);
	scanf("%s",b+1);
	d[0][0]=e[0][0]=1;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=k;j++){
			d[i][j]=mul(b[i]-'a',e[i-1][j]);
			for(int t=1;t<=i;t++){
				int nj=j-(n+1-i)*t;
				if(nj<0)break;
				d[i][j]+=mul('z'-b[i],d[i-t][nj]);
				if(d[i][j]>=mod)d[i][j]-=mod;
			}
			e[i][j]=e[i-1][j]+d[i][j];
			if(e[i][j]>=mod)e[i][j]-=mod;
		}
	}
	int ans=0;
	for(int i=0;i<=n;i++)ans=(ans+d[i][k])%mod;
	printf("%d\n",ans);
}