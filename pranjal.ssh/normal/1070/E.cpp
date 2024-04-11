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

template<class node>
struct ST {
#define mid ((l+r)>>1)
    int n;
    vector<node> T;
    ST(int n): n(n), T(4 * n + 10) {}

    // void build(int no, int l, int r, vector<int> &arr) {
    //   if (l == r) {T[no] = node(arr[l]); return;}

    //   build(no << 1, l, mid, arr);
    //   build(no << 1 | 1, mid + 1, r, arr);
    //   T[no] = T[no << 1] + T[no << 1 | 1];
    // }
    void upd(int no, int l, int r, int pos, int val) {
        if (l == r) { T[no] = node(val > 0, val); return;}
        if (pos <= mid) upd(no << 1, l, mid, pos, val);
        else upd(no << 1 | 1, mid + 1, r, pos, val);

        T[no] = T[no << 1] + T[no << 1 | 1];
    }

    ll get(int no, int l, int r, int cnt) {
        if (cnt == 0) return 0;
        if (l == r) {
            return T[no].y;
        }
        ll x = T[2*no+1].x;
        if (cnt <= x) return get(2*no+1, mid+1, r, cnt);
        else return T[2*no+1].y + get(2*no, l, mid, cnt - T[2*no+1].x);
    }

    node qry(int no, int l, int r, int u, int v) {
        if (l >= u and r <= v)return T[no];
        if (v <= mid) return qry(no << 1, l, mid, u, v);
        else if (u >= mid + 1) return qry(no << 1 | 1, mid + 1, r, u, v);

        return qry(no << 1, l, mid, u, v) + qry(no << 1 | 1, mid + 1, r, u, v);
    }

#undef mid
};

struct node {
    /*FUCK*/
    int x;
    ll y;
    node(int x = 0, ll y = 0): x(x), y(y) {}
    node operator +(const node&rhs) {
        return node(x + rhs.x, y + rhs.y);
    }
};

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    int t; cin >> t; while (t--) {
        int n, m; ll t; cin >> n >> m >> t;
        vector<ii> a; FOR (i, 1, n) {
            int x; cin >> x;
            a.emplace_back(x, i);
        }
        sort(all(a));
        ST<node> T(n);
        vector<int> on(n + 1);
        int r = sz(a);
        int mx = 0, d = 1;
        FOR (i, 0, n - 1) {
            int x = a[i].F;
            int pos = a[i].second;
            if (pos <= r) {
                on[pos] = 1;
                T.upd(1, 1, n, pos, x);
            }
            if (i == n - 1 or a[i].F != a[i + 1].F) {
                int cnt = T.T[1].x % m;
                if (T.T[1].x and cnt == 0) cnt = m;
                ll sum = 2*T.T[1].y;
                if (cnt) sum -= T.get(1, 1, n, cnt);
                while (sum > t) {
                    // pr(T.T[1].x, sum);
                    on[r] = 0;
                    T.upd(1, 1, n, r, 0);
                    --r;
                    cnt = T.T[1].x % m;
                    if (T.T[1].x and cnt == 0) cnt = m;
                    sum = 2*T.T[1].y;
                    if (cnt) sum -= T.get(1, 1, n, cnt);
                }
                if (T.T[1].x > mx) mx = T.T[1].x, d = a[i].F;
            }
        }
        cout << mx << " " << d << "\n";
    }

    return 0;
}