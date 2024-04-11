#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 1e5+10;

int n;
ll a[MAXN][2], ans[MAXN];

struct Line {
    bool type;
    double x;
    ll m, c;
};

bool operator<(Line l1, Line l2) {
    if (l1.type || l2.type) return l1.x < l2.x;
    return l1.m > l2.m;
}

set<Line> cht;
bool has_prev(set<Line>::iterator it) {
    return it != cht.begin();
}
bool has_next(set<Line>::iterator it) {
    return it != cht.end() && next(it) != cht.end();
}
double intersect(set<Line>::iterator l1, set<Line>::iterator l2) {
    return (double)(l1->c - l2->c) / (l2->m - l1->m);
}
void calc_x(set<Line>::iterator it) {
    if (has_prev(it)) {
        Line l = *it;
        l.x = intersect(prev(it), it);
        cht.insert(cht.erase(it), l);
    }
}
bool bad(set<Line>::iterator it) {
    if (has_next(it) && next(it)->c <= it->c) return true;
    return (has_prev(it) && has_next(it) &&
            intersect(prev(it), next(it)) <= intersect(prev(it), it));
}
void add_line(ll m, ll c) {
    set<Line>::iterator it;
    it = cht.lower_bound({0, 0, m, c});
    if (it != cht.end() && it->m == m) {
        if (it->c <= c) return;
        cht.erase(it);
    }
    it = cht.insert({0, 0, m, c}).first;
    if (bad(it)) cht.erase(it);
    else {
        while (has_prev(it) && bad(prev(it))) cht.erase(prev(it));
        while (has_next(it) && bad(next(it))) cht.erase(next(it));

        if (has_next(it)) calc_x(next(it));
        calc_x(it);
    }
}
ll query(ll h) {
    Line l = *prev(cht.upper_bound({1, (double)h, 0, 0}));
    return l.m * h + l.c;
}

void solve(){
    cin >> n;
    for (int j = 0; j < 2; j++) for (int i = 0; i < n; i++) cin >> a[i][j];
    ans[0] = 0; add_line(a[0][1], ans[0]);
    for (int i = 1; i < n; i++){
        ans[i] = query(a[i][0]);
        add_line(a[i][1], ans[i]);
    }
    cout << ans[n-1];
}
int main(){
    ios::sync_with_stdio(false); cin.sync_with_stdio(false); cin.tie(0);
    int t=1;
    // cin >> t;
    while (t--) solve();
}