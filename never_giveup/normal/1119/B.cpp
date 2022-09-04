#include <bits/stdc++.h>
#define fr first
#define sc second
#define m_p make_pair
using namespace std;

typedef long long ll;

const ll llinf = 1e18;

const int maxn = 1e6 + 100, inf = 1e9 + 100;

int main() {
    #ifdef ONPC
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    #endif // ONPC
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, h;
    cin >> n >> h;
    vector<int> a(n);
    vector<int> b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int l = 0, r = n + 1;
    while (r - l > 1) {
        int k = (l + r) / 2;
        for (int i = 0; i < k; i++)
            b[i] = a[i];
        sort(b.begin(), b.begin() + k);
        reverse(b.begin(), b.begin() + k);
        int w = h;
        for (int i = 0; i < k && w >= 0; i += 2) {
            w -= b[i];
        }
        if (w >= 0)
            l = k;
        else
            r = k;
    }
    cout << l;
}