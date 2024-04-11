#include <bits/stdc++.h>
#define pb emplace_back
#define mp make_pair
#define int long long

using namespace std;

bool poss(std::vector<int>& a, int n, int h) {
    if (n & 1)
        for (int i = 0; i < n; i += 2) {
            h -= a[i];
        }
    else
        for (int i = 1; i < n; i += 2) {
            h -= a[i];
        }
    return (h >= 0);
}

int32_t main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
    int n; cin >> n;
    int h; cin >> h;
    vector<int> a(n); for (int o = 0; o < n; o++) { cin >> a[o]; }
    int s = 0, e = n;
    while (s < e) {
        int m = (s + e + 1) >> 1;   
        std::vector<int> v(a.begin(), a.begin() + m);
        sort(v.begin(), v.end());
        if (poss(v, m, h)) {
            s = m;
        } else {
            e = m - 1;
        }
    }
    cout << s;
}