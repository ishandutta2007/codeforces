#include "bits/stdc++.h"
#define puba push_back
#define mapa make_pair
#define ff first
#define ss second
#define bend(_x) (_x).begin(), (_x).end()
#define szof(_x) ((int) (_x).size())
#define TASK_NAME ""

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 1e9 + 7;

struct line {
    ll a, b, c;
    line() {
        a = c = 0;
        b = 1;
    }
    line(pii p1, pii p2) {
        a = p1.ss - p2.ss;
        b = p2.ff - p1.ff;
        c = -(p1.ff * a + p1.ss * b);
        assert(a * p2.ff + b * p2.ss + c == 0);
    }
    ll dist(pii p) {
        return p.ff * a + p.ss * b + c;
    }
};

int n;
ll s;

vector<pii> st;

int prev(int ind) {
    return (ind + szof(st) - 1) % szof(st);
}

int foll(int ind) {
    return (ind + 1) % szof(st);
}

int sign(ll num) {
    return num < 0 ? -1 : num == 0 ? 0 : 1;
}

double get_dist(pii p1, pii p2) {
    return sqrt((p1.ff - p2.ff) * (p1.ff - p2.ff) + (p1.ss - p2.ss) * (p1.ss - p2.ss));
}

int main() {
    //freopen(TASK_NAME ".in", "r", stdin);
    //freopen(TASK_NAME ".out", "w", stdout);

    scanf("%d%I64d", &n, &s);

    pii center = {INF, INF};
    vector<pii> inp;
    for (int i = 0; i < n; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        inp.puba({x, y});
        if (center > inp.back()) {
            center = inp.back();
        }
    }

    for (auto& p: inp) {
        p.ff -= center.ff;
        p.ss -= center.ss;
    }

    sort(bend(inp));
    
    for (auto p: inp) {
        while (szof(st) > 1) {
            pii p2 = st.back();
            st.pop_back();
            pii p1 = st.back();
            pii e1 = {p2.ff - p1.ff, p2.ss - p1.ss};
            pii e2 = {p.ff - p2.ff, p.ss - p2.ss};
            ll tmp = (ll) e1.ff * e2.ss - (ll) e1.ss * e2.ff;
            if (tmp > 0) {
                st.puba(p2);
                break;
            }
        }
        st.puba(p);
    }
    /*
    for (auto p: st) {
        cerr << p.ff << " " << p.ss << endl;
    }*/

    inp.pop_back();
    reverse(bend(inp));

    for (auto p: inp) {
        while (szof(st) > 1) {
            pii p2 = st.back();
            st.pop_back();
            pii p1 = st.back();
            pii e1 = {p2.ff - p1.ff, p2.ss - p1.ss};
            pii e2 = {p.ff - p2.ff, p.ss - p2.ss};
            ll tmp = (ll) e1.ff * e2.ss - (ll) e1.ss * e2.ff;
            ll tmp2 = (ll) e1.ff * e2.ff + (ll) e1.ss * e2.ss;
            if (tmp > 0 || (tmp == 0 && tmp2 < 0)) {
                st.puba(p2);
                break;
            }
        }
        st.puba(p);
    }

    st.pop_back();

    /*
    for (auto p: st) {
        cerr << p.ff << " " << p.ss << endl;
    }*/

    int resa = -1, resb = -1, resc = -1;
    for (int i = 0; i < szof(st); ++i) {
        int c = (i + 1) % szof(st);
        for (int j = (i + 1) % szof(st); (j + 1) % szof(st) != i; j = (j + 1) % szof(st)) {
            line l(st[i], st[j]);
            //cerr << i << " " << j << endl;
            while ((c + 1) % szof(st) != i) {
                int next = (c + 1) % szof(st);
                //cerr << st[i].ff << " " << st[i].ss << "    " << st[j].ff << " " << st[j].ss << "   " << st[c].ff << " " << st[c].ss << endl;
                //cerr << abs(l.dist(st[c])) << " " << abs(l.dist(st[next])) << endl;
                if (abs(l.dist(st[c])) < abs(l.dist(st[next]))) {
                    c = next;
                } else {
                    break;
                }
            }
            while (c != i) {
                line l2(st[j], {st[j].ff + (st[i].ff - st[c].ff), st[j].ss + (st[i].ss - st[c].ss)});//(st[c], st[i]);
                line l3(st[i], {st[i].ff + (st[j].ff - st[c].ff), st[i].ss + (st[j].ss - st[c].ss)});//(st[j], st[c]);
                if (sign(l2.dist(st[prev(j)])) * sign(l2.dist(st[foll(j)])) >= 0 && sign(l3.dist(st[prev(i)])) * sign(l3.dist(st[foll(i)])) >= 0) {
                    //cerr << st[i].ff << " " << st[i].ss << "\n";
                    //cerr << st[j].ff << " " << st[j].ss << "\n";
                    //cerr << st[c].ff << " " << st[c].ss << "\n";
                    //cerr << prev(i) << " " << foll(i) << endl;
                    resa = i;
                    resb = j;
                    resc = c;
                    break;
                }
                int next = (c + 1) % szof(st);
                if (next == i || abs(l.dist(st[c])) > abs(l.dist(st[next]))) {
                    break;
                }
                c = next;
            }
        }
        if (resa != -1) {
            break;
        }
    }

    if (resa == -1) {
        while (true) {
            cout << "@" << endl;
        }
    }

    //cerr << resa << " " << resb << " " << resc << endl;

    pii delt = {st[resb].ff - st[resc].ff, st[resb].ss - st[resc].ss};

    pii ansa = {st[resa].ff - delt.ff, st[resa].ss - delt.ss};
    pii ansb = {st[resa].ff + delt.ff, st[resa].ss + delt.ss};
    pii ansc = {st[resb].ff * 2 - ansb.ff, st[resb].ss * 2 - ansb.ss};

    double l1 = get_dist(st[resa], st[resb]);//get_dist(ansa, ansb);
    double l2 = get_dist(st[resa], st[resc]);//get_dist(ansa, ansc);
    double l3 = get_dist(st[resb], st[resc]);//get_dist(ansb, ansc);
    double p = (l1 + l2 + l3) / 2;

    //cerr << sqrt(max(0.0, p * (p - l1) * (p - l2) * (p - l3))) << endl;
    //assert(sqrt(max(0.0, p * (p - l1) * (p - l2) * (p - l3))) <= s);

    cout << ansa.ff + center.ff << " " << ansa.ss + center.ss << "\n";
    cout << ansb.ff + center.ff << " " << ansb.ss + center.ss << "\n";
    cout << ansc.ff + center.ff << " " << ansc.ss + center.ss << "\n";

    return 0;
}