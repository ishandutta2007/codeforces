#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;

#define N 5100
#define LL long long
#define INF 0x3f3f3f3f
#define min(x,y) ((x)<(y)?(x):(y))

const int mod=1000000007;

int n,ans,tmp,a[N],pre[N],pow[N],f[N][N],sumf[N][N],g[N][N],ming[N][N],lcp[N][N];
char s[N];

bool check(int x,int y,int z){
	if (x-y>y-z) return 1; if (x-y<y-z) return 0;
	int i=lcp[y+1][z+1];
	if (i>=(x-y) || a[y+1+i]>a[z+1+i]) return 1;
	return 0;
}

int main(){
	scanf("%s",s+1); int n=strlen(s+1);
	pow[0]=1;
	for (int i=1;i<=n;i++){
		a[i]=s[i]-'0';
		pre[i]=(pre[i-1]*2+a[i])%mod;
		pow[i]=pow[i-1]*2%mod;
	}
	for (int i=n;i>=1;i--)
		for (int j=n;j>=1;j-- )
			if (i==j) lcp[i][j]=n-i+1;
			else
				if (a[i]==a[j]) lcp[i][j]=lcp[i+1][j+1]+1; else lcp[i][j]=0;
	for (int i=1;i<=n;i++){
		f[i][0]=sumf[i][0]=1; g[i][0]=ming[i][0]=1;
		for (int j=1;j<i;j++){
			g[i][j]=ming[i][j]=INF;
			if (a[j+1]==1){
				int k=j-(i-j);
				f[i][j]=(f[i][j]+sumf[j][k+1>0?k+1:0])%mod;
				g[i][j]=min(g[i][j],ming[j][k+1>0?k+1:0]+1);
				if (k+1>0 && a[k+1]==1 && check(i,j,k)){
					f[i][j]=(f[i][j]+f[j][k])%mod;
					g[i][j]=min(g[i][j],g[j][k]+1);
				}
				sumf[i][j]=(sumf[i][j]+f[i][j])%mod;
				ming[i][j]=min(ming[i][j],g[i][j]);
			}
		}
		ming[i][i]=INF;
		for (int j=i-1;j>=0;j--){
			sumf[i][j]=(sumf[i][j]+sumf[i][j+1])%mod;
			ming[i][j]=min(ming[i][j],ming[i][j+1]);
		}
	}
	ans=INF;
	for (int i=1;i<=min(15,n);i++){
		tmp=((pre[n]-(LL)pre[n-i]*pow[i])%mod+mod)%mod;
		ans=min(ans,g[n][n-i]+tmp);
	}
	if (ans==INF)
		for (int i=16;i<=n;i++)
			if (g[n][n-i]!=INF){
				tmp=((pre[n]-(LL)pre[n-i]*pow[i])%mod+mod)%mod;
				ans=(g[n][n-i]+tmp)%mod;
				break;
			}
	printf("%d\n%d\n",sumf[n][0],ans);
	
	return 0;
}