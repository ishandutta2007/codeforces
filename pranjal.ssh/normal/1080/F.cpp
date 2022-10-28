#include <bits/stdc++.h>
using namespace std;

#define cerr cout
#define F first
#define S second
#define FOR(i,a,b) for (auto i = (a); i <= (b); ++i)
#define NFOR(i,a,b) for(auto i = (a); i >= (b); --i)
#define all(x) (x).begin(), (x).end()
#define sz(x) int(x.size())
typedef long long ll; typedef pair <int, int> ii; typedef vector <int> vi; const int inf = 1e9 + 7;
string to_string(string s) { return '"' + s + '"';}
string to_string(char s) { return string(1, s);}
string to_string(const char* s) { return to_string((string) s);}
string to_string(bool b) { return (b ? "true" : "false");}
template <typename A> string to_string(A);
template <typename A, typename B>string to_string(pair<A, B> p) {return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";}
template <typename A> string to_string(A v) {bool f = 1; string r = "{"; for (const auto &x : v) {if (!f)r += ", "; f = 0; r += to_string(x);} return r + "}";}
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) {cerr << " " << to_string(H); debug_out(T...);}
#define pr(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)

const int N = 2e7;
int ctr = 1;
int L[N], R[N], T[N];
#define mid ((l+r)>>1)
int node(int x) {
    ++ctr;
    T[ctr] = x;
    return ctr;
}
int upd(int no, int l, int r, int pos, int val) {
    if (l == r) {
        return node(min(T[no], val));
    }
    int now = node(inf);
    L[now] = L[no], R[now] = R[no];
    if (pos <= mid) L[now] = upd(L[no], l, mid, pos, val);
    else R[now] = upd(R[no], mid+1, r, pos, val);
    T[now] = max(T[L[now]], T[R[now]]);
    return now;
}

int qry(int no, int l, int r, int u, int v) {
    if (r < u or l > v) return 0;
    if (l >= u and r <= v) return T[no];
    return max(qry(L[no], l, mid, u, v), qry(R[no], mid+1, r, u, v));
}

int main()
{
    int n, m, k; scanf("%d %d %d", &n, &m, &k);
    T[0] = inf;
    vector<vector<ii>> a(n);
    map<int, vector<ii>> mp;
    FOR (i, 0, k - 1) {
        int l, r, p; scanf("%d %d %d", &l, &r, &p);
        a[p - 1].emplace_back(l, r);
        
    }

    
    FOR (i, 0, n - 1) {
        // sort(all(a[i]));
        // auto b = a[i]; a[i].clear();
        // for (ii x: b) {
        //     while (!a[i].empty() and a[i].back().S >= x.S) a[i].pop_back();
        //     if (a[i].empty() or (x.F > a[i].back().F and x.S > a[i].back().S)) {a[i].push_back(x);}
        // }
        for (auto it: a[i]) mp[-it.F].emplace_back(it.S, i);
    }
    
    map<int, int> root;
    int prv = 0;
    root[inf] = 0;
    for (auto it: mp) {
        int l = -it.F;
        root[l] = prv;
        for (auto itt: it.S) {
            int r = itt.F, idx = itt.S + 1;
            root[l] = upd(root[l], 1, n, idx, r); 
        }
        prv = root[l];
    }

    while (m--) {
        int a, b, x, y;
        scanf("%d %d %d %d", &a, &b, &x, &y);
        int it = root.lower_bound(x)->S;
        printf(qry(it, 1, n, a, b) <= y ? "yes\n" : "no\n");
        fflush(stdout);
    }
    
    return 0;
}