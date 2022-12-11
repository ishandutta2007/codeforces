#include<bits/stdc++.h>
#define ll long long
#define lowbit(x) ((x)&(-(x)))
#define mid ((l+r)>>1)
#define lson rt<<1, l, mid
#define rson rt<<1|1, mid+1, r
using namespace std;
ll s[21][21];
ll dp[1<<20];
const ll inf = 0x3f3f3f3f3f3f3f3f;
int cnt[21];
int n;
int main()
{
	cin>>n;
	for(int i = 0; i < n; ++i){
        int x; scanf("%d", &x);
        x--;
        cnt[x]++;
        for(int j = 0; j < 20; ++j) if(j != x) s[x][j] += cnt[j];
	}
	for(int mask = 1; mask < (1<<20); ++mask){
        if(mask == lowbit(mask)) continue;
        dp[mask] = inf;
        for(int v = 0; v < 20; ++v){
            if((mask>>v)&1){
                ll temp = dp[mask^(1<<v)];
                for(int i = 0; i < 20; ++i){
                    if(i == v) continue;
                    if((mask>>i)&1) temp += s[i][v];
                }
                dp[mask] = min(dp[mask], temp);
            }
        }
	}
	cout<<dp[(1<<20)-1]<<endl;
}
/*
10
1 1 1 1 1 1 1 2 2 1
*/