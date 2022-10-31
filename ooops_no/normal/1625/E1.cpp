#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define ld long double
#define int long long

mt19937 rnd(51);

const int N = 3e5 + 10;
pair<int,int> po[20][N];

int len(pair<int,int> a) {
    return a.second - a.first + 1;
}

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    vector<int> go(n, -1), res(n);
    vector<pair<int,int>> u;
    deque<int> q;
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            q.pb(i);
        } else {
            if (q.size() > 0) {
                go[q.back()] = i;
                q.pop_back();
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (go[i] != -1) {
            u.pb({i, go[i]});
        }
    }
    sort(u.begin(), u.end(), [&] (pair<int,int> a, pair<int,int> b) {return len(a) < len(b);});
    for (auto to : u) {
        if (len(to) == 2) {
            res[to.first] = 1;
        } else {
            int i = to.first + 1, cnt = 0, sum = 1;
            while (i < n && s[i] == '(') {
                sum += res[i];
                i = go[i] + 1;
                cnt++;
            }
            res[to.first] = cnt * (cnt - 1) / 2 + sum;
        }
    }
    for (int i = 0; i < n; i++) {
        if (go[i] == -1) {
            po[0][i] = {n, 0};
        } else {
            po[0][i] = {go[i] + 1, res[i]};
        }
    }
    po[0][n] = {n, 0};
    for (int i = 1; i < 20; i++) {
        for (int j = 0; j <= n; j++) {
            po[i][j] = {po[i - 1][po[i - 1][j].first].first, po[i - 1][j].second + po[i - 1][po[i - 1][j].first].second};
        }
    }
    for (int i = 0; i < m; i++) {
        int t, l, r;
        cin >> t >> l >> r;
        l--;
        int sum = 0, v = l, cnt = 0;
        for (int j = 19; j >= 0; j--) {
            if (po[j][v].first < r) {
                sum += po[j][v].second;
                v = po[j][v].first;
                cnt += (1 << j);
            }
        }
        cnt++, sum += po[0][v].second;
        cout << sum + cnt * (cnt - 1) / 2 << endl;
    }
    return 0;
}