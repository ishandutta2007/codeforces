#include <bits/stdc++.h>
    
using namespace std;
    
mt19937 rnd(time(0));
    
//        //\\      ||||||  ||||          //\\        ||||||
//       //  \\       ||    ||  ||       //  \\       ||   ||
//      //    \\      ||    ||   ||     //    \\      ||   ||
//     //------\\     ||    ||   ||    //------\\     ||||||
//    //        \\    ||    ||   ||   //        \\    ||  \\
//   //          \\ ||||||  |||||    //          \\   ||   \\
    
#define AvAR ASADULLIN
    
#define int long long
#define mp make_pair
#define all(a) a.begin(), a.end()
#define pii pair<int, int>
#define fi first
#define se second
#define ld long double
#define size(a) (int)(a.size())
#define chkmax(a, b) a = max(a, b)
#define chkmin(a, b) a = min(a, b)
    
const int inf = 1e10 + 2;


map<int, pii> col;

int mn = -1, mx = inf;
bool bad = false;

pii er(int c) {
    col.erase(col[c].fi);
    pii res = col[c];
    col.erase(c);
    return res;
}

pii er_begin() {
    return er(col.begin()->fi);
}

pii er_end() {
    return er((--col.end())->fi);
}

int f() {
    int res = 0, cnt = 0;

    deque<pii> le, ri;
    le.emplace_back(er_begin());

    while(size(le) || size(ri)) {
        while(size(le)) {
            pii v = le.front();
            le.pop_front();

            if (v.fi > mx || v.fi < mn) bad = true;
            mx = v.fi;

            while(size(col) && (--col.end())->fi > v.fi) {
                ri.emplace_back(er_end());
            }

            res += v.se;
            cnt++;
        }

        while(size(ri)) {
            pii v = ri.front();
            ri.pop_front();

            if (v.fi > mx || v.fi < mn) bad = true;
            mn = v.fi;

            while(size(col) && col.begin()->fi < v.fi) {
                le.emplace_back(er_begin());
            }

            res += v.se;
            cnt++;
        }
    }

    return min(res, cnt - res);
}

void solve() {
    int n;
    cin >> n;
    for(int i = 0;i < n;i++) {
        int a, b;
        cin >> a >> b;
        col[a] = mp(b, 0);
        col[b] = mp(a, 1);
    }

    int res = 0;
    while(size(col)) {
        res += f();
    }

    if (bad) cout << -1 << endl;
    else cout << res << endl;
}

signed main() {
    cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0);
    cout.precision(15);
    
#ifdef technocum
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    solve();
}