#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;

#define N 2100
#define LL long long

const int mod=1000000007,BASE=129;
int ans,n,m,pow[N],hsh1[N],hsh2[N],hash1[3][N],hash2[3][N],fl[3][N][N],fr[3][N][N],gl[3][N][N],gr[3][N][N],dp[3][N][N];
char s[3][N],ss[N];

int main(){
	scanf("%s%s%s",s[1]+1,s[2]+1,ss+1);
	n=strlen(s[1]+1); m=strlen(ss+1);
	if (m==1){
		for (int i=1;i<=2;i++)
			for (int j=1;j<=n;j++)
				if (s[i][j]==ss[1]) ans++;
		printf("%d\n",ans);
		return 0;
	}
	if (m==2){
		for (int i=1;i<=2;i++)
			for (int j=1;j<=n;j++)
				if (s[i][j]==ss[1]){
					if (s[3-i][j]==ss[2]) ans++;
					if (j<n && s[i][j+1]==ss[2]) ans++;
					if (j>1 && s[i][j-1]==ss[2]) ans++;
				}
		printf("%d\n",ans);
		return 0;
	}
	pow[0]=1;
	for (int i=1;i<=n;i++){
		pow[i]=(LL)pow[i-1]*BASE%mod;
		hash1[1][i]=((LL)hash1[1][i-1]*BASE+s[1][i])%mod;
		hash1[2][i]=((LL)hash1[2][i-1]*BASE+s[2][i])%mod;
	}
	for (int i=n;i>=1;i--){
		hash2[1][i]=((LL)hash2[1][i+1]*BASE+s[1][i])%mod;
		hash2[2][i]=((LL)hash2[2][i+1]*BASE+s[2][i])%mod;
	}
	for (int i=1;i<=m;i++) hsh1[i]=((LL)hsh1[i-1]*BASE+ss[i])%mod;
	for (int i=m;i>=1;i--) hsh2[i]=((LL)hsh2[i+1]*BASE+ss[i])%mod;
	fl[1][0][0]=fl[2][0][0]=gl[1][0][0]=gl[2][0][0]=1;
	for (int i=1;i<=2;i++)
		for (int j=1;j<=n;j++){
			fl[i][j][0]=gl[i][j][0]=1;
			for (int k=2;k<=j;k++){
				int tmp=((hash2[3-i][j-k+1]-(LL)hash2[3-i][j+1]*pow[k])%mod+mod)%mod;
				tmp=(((LL)tmp*pow[k]+hash1[i][j]-(LL)hash1[i][j-k]*pow[k])%mod+mod)%mod;
				if (k*2<=m && tmp==hsh1[k*2]) fl[i][j][k*2]=1; if (k*2<=m && tmp==hsh2[m-k*2+1]) gl[i][j][k*2]=1;
			}
		}
	fr[1][n+1][0]=fr[2][n+1][0]=gr[1][n+1][0]=gr[2][n+1][0]=1;
	for (int i=1;i<=2;i++)
		for (int j=1;j<=n;j++){
			fr[i][j][0]=gr[i][j][0]=1;
			for (int k=2;k<=n-j+1;k++){
				int tmp=((hash1[3-i][j+k-1]-(LL)hash1[3-i][j-1]*pow[k])%mod+mod)%mod;
				tmp=(((LL)tmp*pow[k]+hash2[i][j]-(LL)hash2[i][j+k]*pow[k])%mod+mod)%mod;
				if (k*2<=m && tmp==hsh1[k*2]) fr[i][j][k*2]=1; if (k*2<=m && tmp==hsh2[m-k*2+1]) gr[i][j][k*2]=1;
			}
		}
	for (int i=1;i<=2;i++)
		for (int j=0;j<=n+1;j++)
			dp[i][j][0]=1;
	for (int k=1;k<=m;k++)
		for (int i=1;i<=2;i++)
			for (int j=1;j<=n;j++){
				dp[i][j][k]=fl[i][j][k];
				if (s[i][j]==ss[k]) (dp[i][j][k]+=dp[i][j-1][k-1])%=mod;
				if (k>=2 && s[i][j]==ss[k] && dp[3-i][j][k-1]>0) (dp[i][j][k]+=dp[3-i][j-1][k-2])%=mod;
				(ans+=dp[i][j][k]*gr[i][j+1][m-k])%=mod;
			}
	for (int k=1;k<=m;k++)
		for (int i=1;i<=2;i++)
			for (int j=n;j>=1;j--){
				dp[i][j][k]=fr[i][j][k];
				if (s[i][j]==ss[k]) (dp[i][j][k]+=dp[i][j+1][k-1])%=mod;
				if (k>=2 && s[i][j]==ss[k] && dp[3-i][j][k-1]>0) (dp[i][j][k]+=dp[3-i][j+1][k-2])%=mod;
				(ans+=dp[i][j][k]*gl[i][j-1][m-k])%=mod;
			}
	printf("%d\n",ans);
	
	return 0;
}