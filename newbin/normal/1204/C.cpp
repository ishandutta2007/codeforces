#include<bits/stdc++.h>
#define ll long long
#define lowbit(x) ((x)&(-(x)))
using namespace std;
const int maxn = 1e6 + 50;
int n;
int p[maxn];
char mp[150][150];
int g[150][150];
int dp[maxn];
int pre[maxn];
void floyed(){
    for(int k = 1; k <= n; ++k){
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= n; ++j){
                if(i == j) continue;
                g[i][j] = min(g[i][j], g[i][k]+g[k][j]);
            }
        }
    }
}
stack<int> ans;
int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i){
        scanf("%s", mp[i]+1);
        for(int j = 1; j <= n; ++j) {
            if(mp[i][j] == '1') g[i][j] = 1;
            else g[i][j] = 0x3f3f3f3f;
        }
        dp[i] = maxn;
	}
	int m;scanf("%d", &m);
	for(int i = 1; i <= m; ++i){
        scanf("%d", &p[i]);
	}
	memset(dp, 0x3f, sizeof dp);
	dp[1] = 1;
	floyed();
	for(int i = 2; i <= m; ++i){
        for(int j = 1; j < i&&j <= 100; ++j){
            if(j == g[p[i-j]][p[i]]) {
                //dp[i] = min(dp[i], dp[i-j]+1);
                if(dp[i] > dp[i-j]+1){
                    dp[i] = dp[i-j]+1;
                    pre[i] = i-j;
                }
            }
        }
	}
	int t = m;
	while(ans.size()) ans.pop();
	while(t!=1){
        ans.push(p[t]); t = pre[t];
	}ans.push(p[1]);
	cout<<dp[m]<<endl;
	printf("%d", ans.top()); ans.pop();
    while(ans.size()){
        printf(" %d", ans.top()); ans.pop();
    }printf("\n");
}