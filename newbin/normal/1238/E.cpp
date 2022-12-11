#include<bits/stdc++.h>
#define ll long long
#define lowbit(x) ((x)&(-(x)))
#define mid ((l+r)>>1)
#define lson rt<<1, l, mid
#define rson rt<<1|1, mid+1, r
using namespace std;
int dp[1<<20];
int d[20][20];
const int maxn = 1e5 + 50;
char s[maxn];
int p[1<<20];
const int inf = 0x3f3f3f3f;
int main()
{
	int n, m;cin>>n>>m;
	p[0] = 0;
	for(int i = 1; i < (1<<m); ++i) p[i] = p[i-lowbit(i)] + 1;
	scanf("%s",s);
	for(int i = 1 ; i < n; ++i){
        int x = s[i]-'a';
        int y = s[i-1]-'a';
        d[x][y]++;
        d[y][x]++;
	}
	dp[0] = 0;
	for(int mask = 1; mask < (1<<m); ++mask){
        dp[mask] = inf;
        int x = p[mask];
        for(int i = 0; i < m; ++i){
            if((mask>>i)&1){
                int cur = 0;
                for(int k = 0; k < m; ++k){
                    if(k == i) continue;
                    if((mask>>k)&1){
                        cur += d[i][k]*(x);
                    }
                    else cur += d[i][k]*(-x);
                }
                dp[mask] = min(dp[mask],dp[mask^(1<<i)] + cur);
            }
        }
        //cout<<"mask:"<<mask<<" dp:"<<dp[mask]<<endl;
	}
	cout<<dp[(1<<m)-1]<<endl;
}