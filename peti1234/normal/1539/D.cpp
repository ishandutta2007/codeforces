#include <bits/stdc++.h>

using namespace std;
long long n, sum, sum2, maxi, ans;
vector<pair<long long, long long> > sz;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {
        long long a, b;
        cin >> a >> b;
        sz.push_back({b, a});
        sum+=a;
    }
    sort(sz.begin(), sz.end());
    ans=2*sum;
    for (auto x:sz) {
        maxi=max(maxi, x.first-sum2);
        sum2+=x.second;
        ans=min(ans, max(sum+maxi, 2*sum-sum2));
    }
    cout << ans << "\n";
    return 0;
}
/*
3
3 4
1 3
1 5
*/