#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

const int MAXVAL = (int) 3e5;

struct DSU {

    int par[2 * MAXVAL + 1], szx[2 * MAXVAL + 1], szy[2 * MAXVAL + 1];
    stack <int> stk;

    ll ans;

    inline void init() {
        ans = 0;
        for(int i = 1; i <= 2 * MAXVAL; i++) {
            szx[i] = szy[i] = par[i] = 0;
        }
        for(int i = 1; i <= MAXVAL; i++) {
            szx[i] = szy[i + MAXVAL] = 1;
        }
    }

    int root(int x) {
        if(par[x] == 0)
            return x;
        return root(par[x]);
    }

    inline void join(int a, int b) {

        b += MAXVAL;
        a = root(a), b = root(b);

        if(szx[a] + szy[a] > szx[b] + szy[b]) {
            swap(a, b);
        }

        if(a != b) {
            par[a] = b;

            ans -= 1LL * szx[a] * szy[a] + 1LL * szx[b] * szy[b];

            szx[b] += szx[a];
            szy[b] += szy[a];

            ans += 1LL * szx[b] * szy[b];

            stk.push(a);
        }
        else {
            stk.push(-1);
        }
    }

    inline void undo() {
        if(stk.top() != -1) {
            int a = stk.top();
            int b = par[a];

            ans -= 1LL * szx[b] * szy[b];

            szx[b] -= szx[a];
            szy[b] -= szy[a];

            ans += 1LL * szx[a] * szy[a] + 1LL * szx[b] * szy[b];

            par[a] = 0;
        }

        stk.pop();
    }

}dsu;

const int MAXQ = (int) 3e5;

vector <int> aint[4 * MAXQ + 1];
int x[MAXQ + 1], y[MAXQ + 1];

void update(int nod, int left, int right, int l, int r, int id) {
    if(l <= left && right <= r) {
        aint[nod].push_back(id);
    }
    else {
        int mid = (left + right) / 2;

        if(l <= mid) update(2 * nod, left, mid, l, r, id);
        if(mid < r) update(2 * nod + 1, mid + 1, right, l, r, id);
    }
}

ll sol[MAXQ + 1];

void solve(int nod, int left, int right) {
    for(auto it : aint[nod]) {
        dsu.join(x[it], y[it]);
    }


    if(left == right) {
        sol[left] = dsu.ans;
    }
    else {
        int mid = (left + right) / 2;

        solve(2 * nod, left, mid);
        solve(2 * nod + 1, mid + 1, right);
    }

    for(auto it : aint[nod]) {
        dsu.undo();
    }
}

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, q;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> q;

    map < pair <int, int>, int > mp;
    vector <int> pos(q + 1);

    for(i = 1; i <= q; i++) {
        cin >> x[i] >> y[i];

        if(mp[{x[i], y[i]}]) {
            pos[mp[{x[i], y[i]}]] = i - 1;
            mp[{x[i], y[i]}] = 0;
            pos[i] = -1;
        }
        else {
            mp[{x[i], y[i]}] = i;
        }
    }

    for(i = 1; i <= q; i++) {
        if(pos[i] == 0) {
            pos[i] = q;
        }

        if(pos[i] != -1) {
            update(1, 1, q, i, pos[i], i);
        }
    }

    dsu.init();

    solve(1, 1, q);

    for(i = 1; i <= q; i++) {
        cout << sol[i] << " ";
    }

    //cin.close();
    //cout.close();
    return 0;
}