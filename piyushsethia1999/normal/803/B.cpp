#include <bits/stdc++.h>
#define pb emplace_back
#define mp make_pair

using namespace std;

int32_t main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
    int n; cin >> n;
    vector<int> a(n); for (int o = 0; o < n; o++) { cin >> a[o]; }
    int in = -10000000;
    std::vector<int> d(n, 1000000);
    for (int i = 0; i < n; ++i) {
        if (a[i] == 0)
            in = i;
        d[i] = min(d[i], i - in);
    }
    in = 10000000;
    for (int i = n - 1; i >= 0; --i) {
        if (a[i] == 0)
            in = i;
        d[i] = min(d[i], in - i);
    }
    for (int i = 0; i < n; ++i) cout << d[i] << " ";
}