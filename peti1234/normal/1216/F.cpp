#include <bits/stdc++.h>

using namespace std;
long long n, k, o=0, dp[200002];
deque<pair<long long, int> > q;
string s;
int main()
{
    cin >> n >> k >> s;
    for (int i=1; i<=n; i++) {
        dp[i]=dp[i-1]+i;
        if (q.size() && q.front().second<i) q.pop_front();
        if (s[i-1]=='1') {
            long long p=min(dp[max(o, i-k-1)], dp[i-1])+i, f=i+k;
            while (q.size() && p<q.back().first) q.pop_back();
            q.push_back({p, f});
        }
        if (q.size()) dp[i]=min(dp[i], q.front().first);
    }
    cout << dp[n] << "\n";
    return 0;
}