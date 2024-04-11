#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pi;

ll curL = 0, curR = 0, answer = 0;
int c[1000001];
int sq;

bool comp (const pair<pi, int> &a, const pair<pi, int> &b) {
    if (a.first.first/sq != b.first.first/sq)
        return a.first.first/sq < b.first.first/sq;
    return a.first.second < b.first.second;
}

void add(int x) {
    c[x] += 1;
    answer -= (ll)(c[x]-1) * (c[x]-1) * x;
    answer += (ll)c[x] * c[x] * x;
}

void remove(int x) {
    c[x] -= 1;
    answer -= (ll)(c[x]+1) * (c[x]+1) * x;
    answer += (ll)c[x] * c[x] * x;
}

int main() {
    ios::sync_with_stdio(false);

    memset(c, 0, sizeof(c));

    int n, t;
    cin >> n >> t;

    vi a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    sq = ceil(sqrt(n));
    vector<pair<pi, int>> queries(sq + 1);
    vector<ll> ans(t);

    for (int i = 0; i < t; i++) {
        int l, r;
        cin >> l >> r;
        queries.push_back({{l-1, r-1}, i});
    }

    sort(all(queries), comp);

    add(a[0]);

    for (auto &x : queries) {
        while (curL < x.first.first) {
            remove(a[curL]);
            curL += 1;
        }
        while (curL > x.first.first) {
            curL -= 1;
            add(a[curL]);
        }
        while (curR < x.first.second) {
            curR += 1;
            add(a[curR]);
        }
        while (curR > x.first.second) {
            remove(a[curR]);
            curR -= 1;
        }
        ans[x.second] = answer;
    }

    for (int i = 0; i < t; i++) {
        cout << ans[i] << "\n";
    }
    return 0;
}