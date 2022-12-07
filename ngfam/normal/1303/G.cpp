#include<bits/stdc++.h>

using namespace std;

#define double long double
typedef long long num_t;
const num_t oo = (num_t) 1e18;
struct LineHull {
    struct Line {
        num_t a, b;
        Line(num_t a = 0, num_t b = 0) : a(a), b(b) {}
        int operator < (const Line& rhs) const {return make_pair(-a, b) < make_pair(-rhs.a, rhs.b);}
        int operator == (const Line& rhs) const {return make_pair(a, b) == make_pair(rhs.a, rhs.b);}
        int operator != (const Line& rhs) const {return make_pair(a, b) != make_pair(rhs.a, rhs.b);}
        num_t query(num_t x) {return a * x + b;}
    };
    double intersect(Line ln1, Line ln2) {
        return (double) (ln2.b - ln1.b) / (ln1.a - ln2.a);
    }
    int bad(Line ln1, Line ln2, Line ln3) {
        return (double) (ln1.a - ln2.a) * (ln2.b - ln3.b) >= (double) (ln2.a - ln3.a) * (ln1.b - ln2.b);
        //return intersect(ln1, ln2) >= intersect(ln2, ln3);
    }
    set<Line> hull;
    set<pair<double, Line> > pos;
    void add(num_t a, num_t b) {
        Line ln(a, b);
        if (hull.find(ln) != hull.end()) return;
        hull.insert(ln);
        set<Line>::iterator it = hull.find(ln);
        if (it == hull.begin()) {
            pos.insert(make_pair(-oo, ln));
            if (++it != hull.end()) pos.erase(make_pair(-oo, *it));
            it--;
        }
        else {
            Line prv = *(--it); it++;
            if (prv.a == ln.a) {
                hull.erase(ln);
                return;
            }
            if (*it != *hull.rbegin()) {
                Line nxt = *(++it); it--;
                if (bad(prv, ln, nxt)) {
                    hull.erase(ln);
                    return;
                }
                pos.erase(make_pair(intersect(prv, nxt), nxt));
            }
        }
        Line u, v;
        if (it != hull.begin()) {
            v = *(--it);
            while (it != hull.begin()) {
                u = *(--it);
                if (bad(u, v, ln)) {
                    pos.erase(make_pair(intersect(u, v), v));
                    hull.erase(v); it = hull.find(v = u);
                }
                else {
                    it++;
                    break;
                }
            }
            pos.insert(make_pair(intersect(v, ln), ln));
            it++;
        }
        if (*it != *hull.rbegin()) {
            u = *(++it);
            while (*it != *hull.rbegin()) {
                v = *(++it);
                if (ln.a == u.a || bad(ln, u, v)) {
                    pos.erase(make_pair(intersect(u, v), v));
                    hull.erase(u); it = hull.find(u = v);
                }
                else {
                    it--;
                    break;
                }
            }
            pos.insert(make_pair(intersect(ln, u), u));
            it--;
        }
    }
    num_t query(num_t x) {
        if (!pos.size()) return oo;
        set<pair<double, Line> >::iterator it = pos.upper_bound(make_pair(x, Line(-oo, -oo)));
        it--;
        return it->second.a * x + it->second.b;
    }
} dlh;
#undef double


const int MAXN = 150005;

int n;
int a[MAXN];
vector<int> g[MAXN];

int del[MAXN];
int child[MAXN];
vector<int> adj[MAXN];

void dfs_prepare(int v, int p) {
  child[v] = 1;
  for(int s : adj[v]) if(s != p && !del[s]) {
    dfs_prepare(s, v);
    child[v] += child[s];
  }
}

int dfs_centroid(int v, int p, int root) {
  for(int s : adj[v]) if(s != p && !del[s]) {
    if(child[s] * 2 >= child[root]) return dfs_centroid(s, v, root);
  }
  return v;
}

int glob;
long long ans = -oo;

void add(int v, int p, long long sumR, long long R, int lenR, LineHull &cur) {



  lenR++;
  sumR += a[v];
  R += sumR;

  cur.add(-lenR, -R);
  for(int s : g[v]) if(s != p && !del[s]) {
    add(s, v, sumR, R, lenR, cur);
  }
}

void query(int v, int p, long long sumL, long long L, int lenL, LineHull &cur) {
  lenL++;
  sumL += a[v];
  L += 1LL * a[v] * lenL;

  ans = max(ans, L + -cur.query(sumL));
  for(int s : g[v]) if(s != p && !del[s]) {
    query(s, v, sumL, L, lenL, cur);
  }
}

void solve(int v) {
  glob = v;
  LineHull up, down;
  for(int s : g[v]) if(!del[s]) {
    query(s, v, 0, 0, 0, up);
    add(s, v, a[v], a[v], 1, up);
  }

  ans = max(ans, -up.query(0));

  reverse(g[v].begin(), g[v].end());
  down.add(-1, -a[v]);

  for(int s : g[v]) if(!del[s]) {
    query(s, v, 0, 0, 0, down);
    add(s, v, a[v], a[v], 1, down);
  }
}

void go(int v) {

  dfs_prepare(v, -1);
  v = dfs_centroid(v, -1, v);
  del[v] = 1;
  solve(v);
  for(int s : adj[v]) if(!del[s]) {
    go(s);
  }
}

long long correct = 0;

void dfs_brute(int v, int p, long long R, long long S) {
  R += a[v];
  S += R;
  correct = max(correct, S);
  for(int s : g[v]) if(s != p) dfs_brute(s, v, R, S);


}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  cin >> n;
  for(int i = 0; i + 1 < n; ++i) {
    int u, v; cin >> u >> v;
    g[--u].push_back(--v);
    g[v].push_back(u);
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  for(int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  go(0);

  cout << ans << endl;

  return 0;
}