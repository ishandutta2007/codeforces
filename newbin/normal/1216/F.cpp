#include<bits/stdc++.h>
#define ll long long
#define lowbit(x) ((x)&(-(x)))
#define mid ((l+r)>>1)
#define lson rt<<1, l, mid
#define rson rt<<1|1, mid+1, r
using namespace std;
const int maxn = 2e5 + 50;
int n, k;
char s[maxn];
multiset<ll> s1, s2;//s1dps2dp
vector<ll> del[maxn];//s2
ll dp[maxn];//dp[i][1,i]
int main()
{
    cin>>n>>k;
    scanf("%s", s+1);
    dp[0] = 0;
    s1.insert(dp[0]);
    for(int i = 1; i <= n; ++i){
        dp[i] = dp[i-1] + i;//
        if(i-k-2 >= 0) s1.erase( s1.find(dp[i-k-2]) );
        for(int j = 0; j < del[i].size(); ++j) s2.erase( s2.find(del[i][j]) );//s1s2

        if( s2.size() ) dp[i] = min(dp[i], *s2.begin());
        if(s[i] == '1'){
            ll val;//
            if(s1.size()) val = *s1.begin() + i;
            else val = i;
            dp[i] = min(dp[i], val);

            s2.insert(val);
            if(i+k+1 <= n) del[i+k+1].push_back(val);//i+kvaldp
        }
        s1.insert(dp[i]);
    }
    cout<<dp[n]<<endl;
}