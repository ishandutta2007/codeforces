#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
// #include <sys/resource.h>

using namespace std;
using namespace __gnu_pbds;

#define INF 1000000007

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int> > vvi;
typedef pair<int, int> ii;
typedef vector<pair<int, int> > vii;
typedef vector<vector<pair<int, int> > > vvii;


#define TRACE

#ifdef TRACE
template<class T, class U>
ostream& operator<<(ostream& out, const pair<T, U>& a) {out << "[" << a.first << " " << a.second << "]"; return out;}
template<class T>
ostream& operator<<(ostream& out, const vector<T>& a) {out << "[ "; for (auto &it : a)out << it << " "; out << "]"; return out;}
template<class T>
ostream& operator<<(ostream& out, const set<T>& a) {out << "[ "; for (auto &it : a)out << it << " "; out << "]"; return out;}
template<class T>
ostream& operator<<(ostream& out, const multiset<T>& a) {out << "[ "; for (auto &it : a)out << it << " "; out << "]"; return out;}
template<class T, class U>
ostream& operator<<(ostream& out, const map<T, U>& a) {for (auto &it : a)out << it.first << " -> " << it.second << " | "; return out;}
template<class T, class U>
ostream& operator<<(ostream& out, const multimap<T, U>& a) {for (auto &it : a)out << it.first << " -> " << it.second << " | "; return out;}

#define pra(a,n) cerr<<#a<<" : ";for(int i=0;i<n;++i)cerr<<a[i]<<" ";cerr<<endl;
#define praa(a,n,m) cerr<<#a<<" : "<<endl;for(int i=0;i<n;++i){for(int j=0;j<m;++j)cerr<<a[i][j]<<" ";cerr<<endl;}
#define pr(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
    cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ','); cerr.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);
}
#else
#define pr(...)
#define pra(a,n)
#define praa(a,n,m)
#endif

#define inc_stack_limit const rlim_t kStackSize = 64 * 1024 * 1024;struct rlimit rl;rl.rlim_cur = kStackSize;setrlimit(RLIMIT_STACK, &rl);
#define all(x) (x).begin(), (x).end()
#define nall(x) (x).rbegin(), (x).rend()
#define sz(a) int((a).size())
#define pres(s,x) (s.find(x)!=s.end())
#define pb push_back
#define MP make_pair
#define F first
#define S second
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define NFOR(i,a,b) for(int i=(a);i>=(b);--i)
#define TCASE int __T;cin>>__T;FOR(Tc,1,__T)

inline int add(int a, int b, int m = INF) {a += b; if (a >= m)a -= m; return a;}
inline int sub(int a, int b, int m = INF) {a -= b; if (a < 0)a += m; return a;}
inline int mul(int a, int b, int m = INF) {return (int)(((ll)a * (ll)b) % m);}



template<int n>
struct matrix {
    int a[n][n];
    static const ll INF2 = INF * 1LL * INF;
    matrix() {
        FOR(i, 0, n - 1) FOR (j, 0, n - 1) a[i][j] = i == j;
    }

    matrix(vvi b) {
        FOR(i, 0, sz(b) - 1) FOR(j, 0, sz(b) - 1) a[i][j] = b[i][j];
    }

    int* operator[](int x) {return a[x];}

    matrix operator*(matrix b) {
        matrix ans;
        FOR (i, 0, n - 1) {
            FOR (j, 0, n - 1) {
                ll x = 0;
                FOR (k, 0, n - 1) {
                    x += a[i][k] * 1LL * b[k][j];
                    if (x >= INF2) x -= INF2;
                }
                ans[i][j] = x % INF;
            }
        }
        return ans;
    }
    matrix operator+(matrix b) {
        matrix ans;
        FOR (i, 0, n - 1) {
            FOR (j, 0, n - 1) {
                ans[i][j] = a[i][j] + b[i][j];
                if (ans[i][j] >= INF) ans[i][j] -= INF;
            }
        }
        return ans;
    }
    matrix operator^(ll pw) {
        matrix ans, now = *this;
        while (pw > 0) {
            if (pw & 1)
                ans = ans * now;
            now = now * now;
            pw >>= 1;
        }
        return ans;
    }
};

matrix<2> fib({{1, 1}, {1, 0}});
matrix<2> yolo;


template <typename node>
struct ST {

#define mid ((l+r)>>1)

    int n;
    vector<node> T;

    ST(int n): n(n), T(4 * n + 10) {}

    void build(int no, int l, int r, vi& arr) {
        if(l == r) {
            T[no].mat = (fib ^ arr[l - 1]);
            return;
        }
        build(no << 1, l, mid, arr);
        build(no << 1 | 1, mid + 1, r, arr);
        T[no] = node::merge(T[no << 1], T[no << 1 | 1]);
    }

    inline void LAZY(int no, int l, int r) {
        T[no].mat = T[no].mat * T[no].lazy;
        if (l != r) {
            T[no << 1].lazy = T[no << 1].lazy * T[no].lazy ;
            T[no << 1 | 1].lazy = T[no << 1 | 1].lazy * T[no].lazy ;
        }

        T[no].lazy = matrix<2>();
    }

    node qry(int no, int l, int r, int u, int v) {
        LAZY(no, l, r);

        if (l >= u and r <= v)return T[no];
        if (v <= mid) {if (l != r)LAZY(no << 1 | 1, mid + 1, r); return qry(no << 1, l, mid, u, v);}
        else if (u >= mid + 1) {if (l != r)LAZY(no << 1, l, mid); return qry(no << 1 | 1, mid + 1, r, u, v);}

        return node::merge(qry(no << 1, l, mid, u, v), qry(no << 1 | 1, mid + 1, r, u, v));
    }

    void updr(int no, int l, int r, int u, int v, int val) {
        LAZY(no, l, r);

        if (l >= u and r <= v) {T[no].lazy = yolo ; LAZY(no, l, r); return;}
        if (r < u or l > v) return;

        updr(no << 1, l, mid, u, v, val), updr(no << 1 | 1, mid + 1, r, u, v, val);
        T[no] = node::merge(T[no << 1], T[no << 1 | 1]);
    }
#undef mid
};

struct node {
    matrix<2> mat;
    matrix<2> lazy;
    node() : mat(), lazy() {}

    static node merge(node x, node y) {
        node ans;
        ans.mat = x.mat + y.mat;
        return ans;
    }
};


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    int n, m;
    cin >> n >> m;

    ST<node> T(n);
    vi arr(n);
    FOR (i, 0, n - 1) cin >> arr[i];
    T.build(1, 1, n, arr);
    
    
    while (m--) {
        int t; cin >> t;
        if (t == 1) {
            int l, r, x;
            cin >> l >> r >> x;
            yolo = fib ^ x;
            T.updr(1, 1, n, l, r, x);
        }
        else {
            int l, r;
            cin >> l >> r;
            cout << T.qry(1, 1, n, l, r).mat[1][0] << "\n";
        }
    }

    return 0;
}