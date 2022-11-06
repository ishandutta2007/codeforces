#include<bits/stdc++.h>
#define LL long long
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
using namespace std;
inline int read(){
	int v=0,f=1;
	char c=getchar();
	while (c<'0' || c>'9'){
		if (c=='-') f=-1;
		c=getchar();
	}
	while (c>='0' && c<='9'){
		v=v*10+c-'0';
		c=getchar();
	}
	return v*f;
}
const int Maxn=85;
int n,k;
int w[Maxn][Maxn];
int c[Maxn];
int dp[Maxn][15];
int main(){
	scanf("%d %d",&n,&k);
	srand(time(0));
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++) scanf("%d",&w[i][j]);
	}
	int Mn=2e9;
	for (int _=0;_<=7000;_++){
		for (int i=1;i<=n;i++) c[i]=rand()%2;
		for (int i=1;i<=n;i++){
			for (int j=0;j<=k;j++) dp[i][j]=2e9;
		}
		dp[1][0]=0;
		for (int i=0;i<k;i++){
			for (int j=1;j<=n;j++){
				if (dp[j][i]!=2e9){
					for (int k=1;k<=n;k++){
						if (c[j]!=c[k]){
							dp[k][i+1]=min(dp[k][i+1],dp[j][i]+w[j][k]);
						}
					}
				}
			}
		}
		Mn=min(Mn,dp[1][k]);
	}
	printf("%d\n",Mn);
	return 0;
}