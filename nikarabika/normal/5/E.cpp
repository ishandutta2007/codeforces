//sobskdrbhvk
//remember...
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef long double LD;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define smin(x, y) (x) = min((x), (y))
#define smax(x, y) (x) = max((x), (y))
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<int> all;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        all.PB(a[i]);
    }
    sort(all(all));
    all.resize(unique(all(all)) - all.begin());
    for (int i = 0; i < n; i++)
        a[i] = lower_bound(all(all), a[i]) - all.begin();
    {
        int pos = max_element(a, a + n) - a;
        rotate(a, a + pos, a + n);
    }
    vector<int> vec[sz(all)];
    set<int> s;
    for (int i = 0; i < n; i++)
        vec[a[i]].PB(i);
    LL ans = 0;
    {
        int mxval = sz(all) - 1;
        ans += 1LL * sz(vec[mxval]) * (sz(vec[mxval]) - 1) / 2;
        for (auto pos: vec[mxval])
            s.insert(pos);
    }
    s.insert(n);
    for (int val = sz(all) - 2; val >= 0; val--) {
        for (int p = 0, q = 0; p < sz(vec[val]); p = q) {
            while (q < sz(vec[val]) and s.lower_bound(vec[val][q]) == s.lower_bound(vec[val][p]))
                q++;
            int len = q - p;
            ans += 1LL * len * (len - 1) / 2;
        }
        for (auto pos: vec[val])
            s.insert(pos);
    }
    ans += 2 * (n - sz(vec[sz(all) - 1]));
    if (sz(vec[sz(all) - 1]) == 1)
        ans -= sz(vec[sz(all) - 2]);
    cout << ans << '\n';
    return 0;
}