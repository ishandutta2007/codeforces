#include <bits/stdc++.h>

using namespace std;
const int c=300002;
long long n, h[c], b[c], dp[c], ans=-1e9;
multiset<long long> f;
vector<int> s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> h[i];
    }
    for (int i=1; i<=n; i++) {
        cin >> b[i];
    }
    for (int i=1; i<=n; i++) {
        long long maxi=dp[i-1];
        while (s.size()>0 && h[i]<h[s.back()]) {
            int ert=s.back();
            f.erase(f.find(-dp[ert]));
            s.pop_back();
            maxi=max(maxi, dp[ert]);
            if (b[ert]<0) {
                maxi=max(maxi, dp[ert]-b[ert]);
            }
        }
        maxi=max(maxi, -*f.begin());
        dp[i]=maxi+b[i];
        f.insert(-dp[i]);
        s.push_back(i);
    }
    /*
    for (int i=1; i<=n; i++) {
        cout << dp[i] << " ";
    }
    cout << "\n";
    */
    for (int i:s) {
        ans=max(ans, dp[i]);
    }
    cout << ans << "\n";
    return 0;
}
/*
3
1 2 3
1 -2 3
*/