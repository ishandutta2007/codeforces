#include <bits/stdc++.h>

using namespace std;

const long double EPS = 1E-9;

struct pt {
    long double x, y;
};

struct seg {
    pt p, q;
    int id;

    long double get_y(long double x) const {
        if (abs(p.x - q.x) < EPS)
            return p.y;
        return p.y + (q.y - p.y) * (x - p.x) / (q.x - p.x);
    }
};

const int c=25002;
int n;
long double x[c], y[c], dx[c], dy[c], gx[c], gy[c], ss[c];
long double lo=0, hi=1e12, mid;
vector<seg> a;

bool intersect1d(long double l1, long double r1, long double l2, long double r2) {
    if (l1 > r1)
        swap(l1, r1);
    if (l2 > r2)
        swap(l2, r2);
    return max(l1, l2) <= min(r1, r2) + EPS;
}

int vec(const pt& a, const pt& b, const pt& c) {
    long double s = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
    return abs(s) < EPS ? 0 : s > 0 ? +1 : -1;
}

bool intersect(const seg& a, const seg& b)
{
    return intersect1d(a.p.x, a.q.x, b.p.x, b.q.x) &&
           intersect1d(a.p.y, a.q.y, b.p.y, b.q.y) &&
           vec(a.p, a.q, b.p) * vec(a.p, a.q, b.q) <= 0 &&
           vec(b.p, b.q, a.p) * vec(b.p, b.q, a.q) <= 0;
}

bool operator<(const seg& a, const seg& b)
{
    long double x = max(min(a.p.x, a.q.x), min(b.p.x, b.q.x));
    return a.get_y(x) < b.get_y(x) - EPS;
}

struct event {
    long double x;
    int tp, id;

    event() {}
    event(long double x, int tp, int id) : x(x), tp(tp), id(id) {}

    bool operator<(const event& e) const {
        if (abs(x - e.x) > EPS)
            return x < e.x;
        return tp > e.tp;
    }
};

set<seg> s;
vector<set<seg>::iterator> where;

set<seg>::iterator prev(set<seg>::iterator it) {
    return it == s.begin() ? s.end() : --it;
}

set<seg>::iterator next(set<seg>::iterator it) {
    return ++it;
}

pair<int, int> solve(const vector<seg>& a) {
    int n = (int)a.size();
    vector<event> e;
    for (int i = 0; i < n; ++i) {
        e.push_back(event(min(a[i].p.x, a[i].q.x), +1, i));
        e.push_back(event(max(a[i].p.x, a[i].q.x), -1, i));
    }
    sort(e.begin(), e.end());

    s.clear();
    where.resize(a.size());
    for (size_t i = 0; i < e.size(); ++i) {
        int id = e[i].id;
        if (e[i].tp == +1) {
            set<seg>::iterator nxt = s.lower_bound(a[id]), prv = prev(nxt);
            if (nxt != s.end() && intersect(*nxt, a[id]))
                return make_pair(nxt->id, id);
            if (prv != s.end() && intersect(*prv, a[id]))
                return make_pair(prv->id, id);
            where[id] = s.insert(nxt, a[id]);
        } else {
            set<seg>::iterator nxt = next(where[id]), prv = prev(where[id]);
            if (nxt != s.end() && prv != s.end() && intersect(*nxt, *prv))
                return make_pair(prv->id, nxt->id);
            s.erase(where[id]);
        }
    }

    return make_pair(-1, -1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> x[i] >> y[i] >> dx[i] >> dy[i] >> ss[i];
        long double sum=sqrt(dx[i]*dx[i]+dy[i]*dy[i]);
        gx[i]=dx[i]/sum, gy[i]=dy[i]/sum;
    }
    while (hi-lo>1e-6) {
        mid=(hi+lo)/2;
        a.clear();
        for (int i=1; i<=n; i++) {
            seg ert;
            ert.p.x=x[i], ert.p.y=y[i];
            ert.q.x=x[i]+gx[i]*ss[i]*mid, ert.q.y=y[i]+gy[i]*ss[i]*mid;
            ert.id=i;
            a.push_back(ert);
        }
        pair<int, int> ans=solve(a);
        if (ans.first!=-1) {
            hi=mid;
        } else {
            lo=mid;
        }
    }
    if (lo>1e11) {
        cout << "No show :(" << "\n";
    } else {
        cout.precision(20);
        cout << lo << "\n";
    }
    return 0;
}