#include <bits/stdc++.h>

using namespace std;
long long a, b, c, n, sum, db;
vector<pair<int, int> > sz;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> a >> b >> c >> n;
    for (int i=1; i<=n; i++) {
        int x;
        string s;
        cin >> x >> s;
        sz.push_back({x, (s=="USB" ? 0 : 1)});
    }
    sort(sz.begin(), sz.end());
    for (auto x:sz) {
        long long p=x.first;
        bool f=x.second;
        if (f==0) {
            if (a) {
                db++, a--;
                sum+=p;
            } else if (c) {
                db++, c--;
                sum+=p;
            }
        } else {
            if (b) {
                db++, b--;
                sum+=p;
            } else if (c) {
                db++, c--;
                sum+=p;
            }
        }
    }
    cout << db << " " << sum << "\n";
    return 0;
}