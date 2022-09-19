#include <bits/stdc++.h>

using namespace std;
long long n, m, sum, db;
vector<int> sz;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        int a, b;
        cin >> a >> b;
        sum+=b;
        sz.push_back(a-b);
    }
    if (sum>m) {
        cout << -1 << "\n";
        return 0;
    }
    sort(sz.begin(), sz.end());
    for (auto x:sz) {
        if (sum+x<=m) {
            db++;
            sum+=x;
        }
    }
    cout << n-db << "\n";
    return 0;
}