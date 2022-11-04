#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
// 92

using namespace std;

const ll MAXVAL = (ll) 1e18;

int v[20];

vector <int> v1, v0;

const int MAXN = (int) 1e6 + 10;

ll vals[2][2 * MAXN + 1];

inline void solve(int lvl, vector <int> a, int &sz, ll prd, ll val, bool t) {
    if(lvl == a.size()) {
        vals[t][++sz] = prd;
    }
    else {
        for(; prd <= val; prd *= a[lvl]) {
            solve(lvl + 1, a, sz, prd, val, t);
            if(val / a[lvl] < prd)
                break;
        }
    }
}

inline ll check(ll val, int sz0, int sz1) {
    ll cnt = 0;
    int pos = sz1;
    for(int i = 1; i <= sz0; i++) {
        while(pos > 0 && val / vals[0][i] < vals[1][pos])
            pos--;
        cnt += pos;
    }
    return cnt;
}

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n;
    ios::sync_with_stdio(false);
    cin >> n;
    for(i = 1; i <= n; i++) {
        cin >> v[i];
        if(i % 2)
            v1.push_back(v[i]);
        else
            v0.push_back(v[i]);
    }
    int sz0, sz1;
    sz0 = sz1 = 0;
    solve(0, v0, sz0, 1, MAXVAL, 0);
    solve(0, v1, sz1, 1, MAXVAL, 1);
    sort(vals[0] + 1, vals[0] + sz0 + 1);
    sort(vals[1] + 1, vals[1] + sz1 + 1);
    ll k;
    cin >> k;
    ll rez = 0;
    for(ll pas = 1LL << 59; pas; pas >>= 1) {
        if(rez + pas < MAXVAL && check(rez + pas, sz0, sz1) < k)
            rez += pas;
    }
    cout << rez + 1;
    //cin.close();
    //cout.close();
    return 0;
}