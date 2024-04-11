#include <bits/stdc++.h>
using namespace std;

#define chkmin(a, b) a = min(a, b);
#define chkmax(a, b) a = max(a, b)
#define int long long
#define size(a) (int)a.size()
#define all(a) a.begin(), a.end()
#define pii pair<int, int>
#define fi first
#define se second
#define mp make_pair

const int inf = 1e9 + 7, mod = 1e9 + 7;
const int max_n = 1e6 + 5;

int n;
int a[max_n], lc[max_n], rc[max_n];
int d1[max_n], d2[max_n], d3[max_n];

void scan() {
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    deque<int> so;
    for (int i = 0; i < n; ++i) {
        while (size(so) && a[so.back()] >= a[i]) so.pop_back();
        if (size(so)) lc[i] = i - so.back() - 1;
        else lc[i] = i;
        so.emplace_back(i);
    }
    so.clear();
    for (int i = n - 1; i >= 0; --i) {
        while(size(so) && a[so.back()] > a[i]) so.pop_back();
        rc[i] = (size(so) ? so.back() : n) - i - 1;
        so.emplace_back(i);
    }
}

void add1(int l, int r, int x) {
    d1[l] += x;
    d1[r + 1] -= x * (r - l + 2);
    d1[r + 2] += x * (r - l + 1);
}

void add2(int l, int r, int x) {
    d2[r] += x;
    if (l) d2[l - 1] -= x * (r - l + 2);
    if (l >= 2) d2[l - 2] += x * (r - l + 1);
}

void add3(int l, int r, int x) {
    d3[l] += x;
    d3[r + 1] -= x;
}

void run() {
    scan();

    for (int i = 0; i < n; ++i) {
        int l1 = lc[i], l2 = rc[i];
        //cout << l1 << " " << l2 << endl;
        if (l1 > l2) swap(l1, l2);
        add1(1, l1, a[i]);
        add3(l1 + 1, l1 + 1 + l2 - l1, (l1 + 1) * a[i]);
        add2(l1 + 2 + l2 - l1, l1 + l2 + 1, a[i]);
    }

    for (int i = 1; i <= n; ++i)
        d1[i] += d1[i - 1];
    for (int i = 1; i <= n; ++i)
        d1[i] += d1[i - 1];
    for (int i = n; i >= 0; --i)
        d2[i] += d2[i + 1];
    for (int i = n; i >= 0; --i)
        d2[i] += d2[i + 1];
    for (int i = 1; i <= n; ++i)
        d3[i] += d3[i - 1];

    int k;
    cin >> k;
    while (k--) {
        int v;
        cin >> v;
        cout << (long double)(d1[v] + d2[v] + d3[v]) / (n - v + 1) << '\n';
    }
}

signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.precision(15);
#ifdef ahahaha
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    run();
}