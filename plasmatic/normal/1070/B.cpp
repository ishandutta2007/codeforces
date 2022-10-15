// ./b-berkomnadzor.yml
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
const ll INF = 0x3f3f3f3f, LLINF = 0x3f3f3f3f3f3f3f3f;

struct node {
    node *l, *r;
    int sum;
    node() : l(nullptr), r(nullptr), sum(0) {}
    ~node() {
        if (l) delete l;
        if (r) delete r;
    }
};

const int MN = 2e5 + 1;
int N;
vector<pair<ll, ll>> black;
map<ll, vector<pair<ll, ll>>> blackByNL;
vector<ll> ls, rs;
vector<pair<ll, int>> ans;

void add(node *&rt, ll ql, ll qr, ll l=0, ll r=(1LL<<32)-1) {
    if (ql > r || qr < l) return;
    if (!rt) rt = new node;
    if (l >= ql && r <= qr) return void(rt->sum = 1);
    ll mid = (l+r)/2;
    add(rt->l, ql, qr, l, mid); add(rt->r, ql, qr, mid+1, r);
}
void pullup(node *rt, ll l=0, ll r=(1LL<<32)-1) {
    if (!rt) return;
    if (l == r) return;
    ll mid = (l+r)/2;
    pullup(rt->l, l, mid); pullup(rt->r, mid+1, r);
    rt->sum += (rt->l ? rt->l->sum : 0) + (rt->r ? rt->r->sum : 0);
}
void makeans(node *rt, ll ql, ll qr, ll l=0, ll r=(1LL<<32)-1) {
    if (!rt) return;
    if (ql <= l && r <= qr && rt->sum > 0) return void(ans.emplace_back(l, __lg(r-l+1)));
    ll mid = (l+r)/2;
    makeans(rt->l, ql, qr, l, mid); makeans(rt->r, ql, qr, mid+1, r);
}
bool test(node *rt, ll ql, ll qr, ll l=0, ll r=(1LL<<32)-1) {
    if (!rt) return false;
    if (ql > r || qr < l) return false;
    if (rt->sum) return true;
    ll mid = (l+r)/2;
    return test(rt->l, ql, qr, l, mid) | test(rt->r, ql, qr, mid+1, r);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N; cin.ignore();

    node *wrt = nullptr;
    for (auto i = 0; i < N; i++) {
        string _line; getline(cin, _line); stringstream line(_line.substr(1));
        char t = _line[0];
        ll a, b, c, d, r = 32; 
        line >> a; line.ignore();
        line >> b; line.ignore();
        line >> c; line.ignore();
        line >> d; line.ignore();
        if (!line.eof())
            line >> r; 

        ll v = d | (c << 8LL) | (b << 16LL) | (a << 24LL), lb = (v >> (32-r)) << (32-r), rb = lb + (1LL << (32-r)) - 1;
        if (t == '+') {
            ls.push_back(lb);
            rs.push_back(rb);
            add(wrt, lb, rb);
        }
        else
            black.emplace_back(lb, rb);
    }
    ls.push_back(-LLINF); ls.push_back(LLINF); sort(ls.begin(), ls.end());
    rs.push_back(-LLINF); rs.push_back(LLINF); sort(rs.begin(), rs.end());
    sort(black.begin(), black.end());

    for (auto [l, r] : black) {
        if (test(wrt, l, r) > 0) {
            cout << "-1\n";
            return 0;
        }
        ll nxtL = *lower_bound(ls.begin(), ls.end(), l);
        blackByNL[nxtL].emplace_back(l, r);
    }
    delete wrt;

    for (auto [rb, v] : blackByNL) {
        ll lb = *(lower_bound(rs.begin(), rs.end(), v[0].first)-1);
        node *rt = nullptr;
        for (auto [l, r] : v)
            add(rt, l, r);
        pullup(rt);
        makeans(rt, lb+1, rb-1);
        delete rt;
    }

    cout << ans.size() << '\n';
    for (auto [val, len] : ans) {
        int v[4]; fill(v, v+4, 0);
        for (auto i = 3; i >= 0; i--) {
            v[i] = val & 255;
            val >>= 8;
        }
        cout << v[0] << '.' << v[1] << '.' << v[2] << '.' << v[3] << '/' << (32-len);
        cout << '\n';
    }

    return 0;
}