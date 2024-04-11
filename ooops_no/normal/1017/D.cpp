#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define ld long double
#define ll long long

mt19937 rnd(51);

const int N = (1 << 12) + 5;
vector<pair<int,int>> pr[N];
int w[N], cnt[N], res[N];

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, q;
    cin >> n >> m >> q;
    for (int i = 0; i < n; i++) {
        cin >> w[i];
    }
    for (int i = 0; i < (1 << n); i++) {
        for (int j = 0; j < n; j++) {
            if (!(i & (1 << j))) {
                res[i] += w[j];
            }
        }
    }
    for (int i = 0; i < m; i++) {
        int val = 0;
        string s;
        cin >> s;
        for (int j = 0; j < n; j++) {
            if ((s[j] - '0') == 1) {
                val += (1 << j);
            }
        }
        cnt[val]++;
    }
    for (int i = 0; i < (1 << n); ++i) {
        for (int j = 0; j < (1 << n); ++j) {
            pr[i].emplace_back(res[i ^ j], cnt[j]);
        }
        sort(pr[i].begin(), pr[i].end());
        for (int j = 1; j < pr[i].size(); ++j) {
            pr[i][j].second += pr[i][j - 1].second;
        }
    }
    for (int i = 0; i < q; i++) {
        int val = 0;
        string s;
        cin >> s;
        for (int j = 0; j < n; j++) {
            if ((s[j] - '0') == 1) {
                val += (1 << j);
            }
        }
        int k;
        cin >> k;
        int l = 0, r = pr[val].size();
        while (r - l > 1) {
            int mid = (r + l) / 2;
            if (pr[val][mid].first <= k) {
                l = mid;
            } else {
                r = mid;
            }
        }
        cout << pr[val][l].second << '\n';
    }
    return 0;
}