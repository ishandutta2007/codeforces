#include "bits/stdc++.h"
#define puba push_back
#define mapa make_pair
#define ff first
#define ss second
#define bend(_x) (_x).begin(), (_x).end()
#define szof(_x) ((int) (_x).size())

using namespace std;
typedef long long LL;
typedef pair <int, int> pii;
const int MAXN = 2e5 + 5;

int n;
vector <int> inp;
vector <pii > v;
vector <pii > res;

int dsu[MAXN];
pii lr[MAXN];

int get_root(int v) {
    return dsu[v] == v ? v : dsu[v] = get_root(dsu[v]);
}

bool used[MAXN];

int main() {    
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);

    cin >> n;

    for (int i = 0; i < n; ++i) {
        dsu[i] = i;
        lr[i] = mapa(i, i);
    }

    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        inp.puba(num);
        v.puba(mapa(num, i));
    }

    sort(bend(v));
    reverse(bend(v));

    for (int i = 0; i < n; ++i) {
        int pos = v[i].ss;
        used[pos] = true;
        int num = v[i].ff;
        int l = 0;
        int nl = pos;
        int rt1 = -1;
        if (pos > 0 && used[pos - 1]) {
            rt1 = get_root(pos - 1);
            nl = lr[rt1].ff;
        }
        int nr = pos;
        int rt2 = -1;
        if (pos < n - 1 && used[pos + 1]) {
            rt2 = get_root(pos + 1);
            nr = lr[rt2].ss;
        }
        l = nr - nl + 1;
        res.puba(mapa(l, num));
        if (rt1 != -1) {
            dsu[rt1] = pos;
        }
        if (rt2 != -1) {
            dsu[rt2] = pos;
        }
        lr[pos] = mapa(nl, nr);
    }

    sort(bend(res));
    reverse(bend(res));

    vector <int> ans;

    int c = 0;
    int now = -1;
    for (int i = n; i >= 1; --i) {
        while (c < szof(res) && res[c].ff >= i) {
            now = max(now, res[c].ss);
            ++c;
        }
        ans.puba(now);
    }
    
    reverse(bend(ans));

    for (int i = 0; i < n; ++i) {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}