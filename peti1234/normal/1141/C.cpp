#include <bits/stdc++.h>

using namespace std;
long long n, sum, ert, t[200005];
vector<long long> ans;
set<long long> s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<n; i++) {
        cin >> t[i];
        sum+=(n-i)*t[i];
    }
    ert=(n*(n+1)/2-sum)/n;
    for (int i=1; i<=n; i++) {
        ans.push_back(ert);
        s.insert(ert);
        if (ert<1 || ert>n) {
            cout << -1 << "\n";
            return 0;
        }
        ert+=t[i];
    }
    if (s.size()!=n) {
        cout << -1 << "\n";
        return 0;
    }
    for (auto x:ans) {
        cout << x << " ";
    }
    cout << "\n";
    return 0;
}