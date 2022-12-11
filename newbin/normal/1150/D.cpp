#include<iostream>
using namespace std; 
const int maxn = 1e5 + 50;
int dp[255][255][255];
char s[maxn];
int nxt[maxn][27];
int len[4];
char c[4][maxn];
int n,q;
int main(){
	cin>>n>>q;
	scanf("%s",s+1);
	for(int i = 0;i < 27;++i) nxt[n][i] = nxt[n+1][i] = n + 1;
	for(int i = n-1;i >= 0;--i){
		for(int j = 0;j < 26;++j) nxt[i][j] = nxt[i+1][j];
		nxt[i][s[i+1]-'a'] = i + 1;
	}
	while(q--){
		char t[2];
		int x;
		scanf("%s%d",t,&x);
		if(t[0] == '-'){
			len[x]--;
		}
		else {
			scanf("%s",t);
			len[x]++;
			c[x][len[x]] = t[0];
			for(int i = (x==1)?len[1]:0;i <= len[1];++i){
				for(int j = (x == 2)?len[2]:0;j <= len[2];++j){
					for(int k = (x == 3)?len[3]:0;k <= len[3];++k){
						if(i+j+k == 0) continue;
						dp[i][j][k] = n+1;
						if(i) dp[i][j][k] = min(nxt[dp[i-1][j][k]][c[1][i]-'a'],dp[i][j][k]);
						if(j) dp[i][j][k] = min(nxt[dp[i][j-1][k]][c[2][j]-'a'],dp[i][j][k]);
						if(k) dp[i][j][k] = min(nxt[dp[i][j][k-1]][c[3][k]-'a'],dp[i][j][k]);
					}
				}
			}
		}
		if(dp[len[1]][len[2]][len[3]] <= n) printf("YES\n");
		else printf("NO\n");
	}
}