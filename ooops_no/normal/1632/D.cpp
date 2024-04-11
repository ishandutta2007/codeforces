#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define ld long double
#define int long long
#define ll long long

mt19937 rnd(51);

const int N = 2e5 + 10;
int po[20][N], lg[N];

int gcd(int a, int b) {
    if (b == 0) return a;
    else return gcd(b, a % b);
}

int get(int l, int r) {
    int d = lg[r - l + 1];
    return gcd(po[d][l], po[d][r - (1 << d) + 1]);
}

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios::sync_with_stdio(0);
    cin.tie(0);
    for (int i = 0; i < 20; i++) {
        if ((1 << i) < N) {
            lg[(1 << i)] = i;
        }
    }
    for (int i = 1; i < N; i++) {
        lg[i] = max(lg[i - 1], lg[i]);
    }
    int n;
    cin >> n;
    vector<int> a(n);
    vector<vector<int>> need(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        po[0][i] = a[i];
    }
    for (int i = 1; i < 20; i++) {
        for (int j = 0; j < n; j++) {
            if (j + (1 << i) > n) continue;
            po[i][j] = gcd(po[i - 1][j], po[i - 1][j + (1 << (i - 1))]);
        }
    }
    for (int i = 0; i < n; i++) {
        int g = a[i], last = i - 1;
        while (last < n - 1) {
            int l = last + 1, r = n;
            while (r - l > 1) {
                int mid = (r + l) / 2;
                if (get(i, mid) == g) {
                    l = mid;
                } else {
                    r = mid;
                }
            }
            if (i + g - 1 > last && i + g - 1 < r) {
                need[i + g - 1].pb(i);
            }
            if (r < n) g = get(i, r);
            last = l;
        }
    }
    int mx = -1, ans = 0;
    for (int i = 0; i < n; i++) {
        bool ok = 1;
        for (auto to : need[i]) {
            if (to > mx) {
                ok = 0;
            }
        }
        if (!ok) {
            mx = i;
            ans++;
        }
        cout << ans << ' ';
    }
    cout << endl;
    return 0;
}