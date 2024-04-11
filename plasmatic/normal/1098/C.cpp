// ./c-construct-a-tree.yml
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
const ll INF = 0x3f3f3f3f, LLINF = 0x3f3f3f3f3f3f3f3f;

const int MN = 1e5 + 1;
int N;
ll S;

int reqDep[MN], dep[MN];

bool check(int branch) {
    // init req
    iota(dep, dep+N+1, 0);
    int ptr = 1;
    ll cnt = 1;
    for (auto i = 1; ; i++) {
        for (auto j = 0; j < cnt; j++) {
            reqDep[ptr++] = i;
            if (ptr > N) break;
        }
        if (ptr > N) break;
        cnt *= branch;
    }

    ll left = ll(N)*(N+1)/2 - S;
    int used = 0;
    for (auto i = 1; i <= N; i++) {
        dep[i] -= used;
        int sub = N-i+1;
        if (left >= sub && dep[i] > reqDep[i]) {
            used++;
            dep[i]--;
            left -= sub;
        }
    }

    return left == 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> S;

    if (S < 2*N-1 || S > ll(N)*(N+1)/2)
        return cout << "No\n", 0;

    int l = 0, r = N-1;
    while (l + 1 < r) {
        int mid = (l + r) / 2;
        if (check(mid)) r = mid;
        else l = mid;
    }

    check(r);
    vector<vector<int>> idx(N+1);
    int mxdep = 0;
    for (auto i = 1; i <= N; i++) {
        idx[dep[i]].push_back(i);
        mxdep = max(mxdep, dep[i]);
    }

    cout << "Yes\n";
    vector<int> par(N+1);
    for (auto i = 2; i <= mxdep; i++) {
        for (auto j = 0; j < idx[i].size(); j++)
            par[idx[i][j]] = idx[i-1][j % idx[i-1].size()];
    }
    for (auto i = 2; i <= N; i++) cout << par[i] << ' ';
    cout << '\n';

    return 0;
}