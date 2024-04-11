#include <iostream>
#include <stack>
#include <string>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cassert>

using namespace std;
typedef long long ll;

const ll mod = 998244353;

int dp[500002];

void solve()
{
    int n; cin >> n;
    string s; cin >> s;
    int r = 0, b = 0;
    for(int i=0;i<n;i++)
    {
        if(s[i] == 'R') r++;
        else b++;
    }
    if(r > b) cout << "Alice\n";
    else if(r < b) cout << "Bob\n";
    else
    {
        int ans = 0, now = 1;
        for(int i=1;i<n;i++)
        {
            if(s[i] == s[i-1])
            {
                ans ^= dp[now];
                now = 1;
            }
            else now++;
        }
        ans ^= dp[now];
        
        if(ans == 0) cout << "Bob\n";
        else cout << "Alice\n";
    }
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    dp[0] = dp[1] = 0;
    for(int i=2;i<=200;i++)
    {
        int cnt[32];
        for(int j=0;j<=30;j++) cnt[j] = 0;
        for(int j=0;j<=i-2;j++) cnt[dp[j]^dp[i-j-2]] = 1;
        for(int j=0;j<=30;j++) if(cnt[j] == 0)
        {
            dp[i] = j;
            break;
        }
    }
    for(int i=201;i<=500000;i++) dp[i] = dp[i-34];
    int t; cin >> t;
    while(t--)
    {
        solve();
    }
}