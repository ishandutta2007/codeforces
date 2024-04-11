#include <bits/stdc++.h>

using namespace std;
vector<pair<long long, long long> > t;
int n, m;
int main()
{
    cin >> n;
    for (int i=1; i<=n; i++) {
        long long a, b;
        cin >> a >> b;
        t.push_back({a, b});
    }
    cin >> m;
    for (int i=1; i<=m; i++) {
        long long a, b;
        cin >> a >> b;
        t.push_back({a, b});
    }
    sort(t.begin(), t.end());
    t.push_back({0, 0});
    long long s=0;
    for (int i=0; i<n+m; i++) {
        if (t[i].first!=t[i+1].first) {
            s+=t[i].second;
        }
    }
    cout << s << endl;
    return 0;
}