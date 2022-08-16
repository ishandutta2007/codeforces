#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 3e5+10, MOD = 1e9+7;

namespace string_hash {
    #define rep(i, a, b) for(int i = a; i < (b); ++i)
    #define all(x) begin(x), end(x)
    typedef pair<int, int> pii;

    typedef uint64_t ull;
    static int C; // initialized below

    // Arithmetic mod two primes and 2^32 simultaneously.
    // "typedef uint64_t H;" instead if Thue-Morse does not apply.
    template<int M, class B>
    struct A {
        int x; B b; A(int x=0) : x(x), b(x) {}
        A(int x, B b) : x(x), b(b) {}
        A operator+(A o){int y = x+o.x; return{y - (y>=M)*M, b+o.b};}
        A operator-(A o){int y = x-o.x; return{y + (y< 0)*M, b-o.b};}
        A operator*(A o) { return {(int)(1LL*x*o.x % M), b*o.b}; }
        explicit operator ull() { return x ^ (ull) b << 21; }
        bool operator==(A o){ return ull(*this) == ull(o); }
        bool operator!=(A o){ return ull(*this) != ull(o); }
    };
    typedef A<1000000007, A<1000000009, unsigned>> H;
    H hashString(string& s){H h{}; for(char c:s) h=h*C+c;return h;} //get hash of string
    H pw[N];
    struct HashConcat {
        H h;
        int n;
        
        HashConcat(): h(), n() {}
        HashConcat(string s) {
            n = sz(s), h = hashString(s);
        }
        HashConcat(H _h, int _n): h(_h), n(_n) {}
        HashConcat operator + (HashConcat o) {
            return HashConcat(h*pw[o.n]+o.h, n+o.n);
        }
        explicit operator H() { return h; }
        explicit operator ull() { return ull(h); }
        bool operator == (HashConcat o) {
            return H(*this) == H(o);
        }
    };

    #include <sys/time.h>
    void pre_hashes(){ //call pre before testcases
        timeval tp;
        gettimeofday(&tp, 0);
        C = (int)tp.tv_usec; // (less than modulo)
        assert((ull)(H(1)*2+1-3) == 0);
        
        pw[0]=1;
        rep(i,0,N-1)
            pw[i+1] = pw[i] * C;
    }
};

using H = string_hash::HashConcat;

int n;
string s;
vector<H> t[4 * N];

void build(int v, int tl, int tr) {
    if (tl == tr) {
        t[v].resize(1);
        t[v][0] = H(s.substr(tl, 1));
    } else {
        int tm = (tl + tr) / 2;
        build(2*v, tl, tm), build(2*v+1, tm+1, tr);
        int len = tr - tl + 1;
        t[v].resize(len);
        for (int i = 0; i < len; i++) {
            if (2 * i < len) {
                t[v][i] = t[2*v][i] + t[2*v+1][i];
            } else {
                t[v][i] = t[2*v+1][i - len / 2] + t[2*v][i - len / 2];
            }
        }
    }
}
H qry(int v, int tl, int tr, int l, int r, int x, int c) {
    if (r < tl || l > tr) return H();
    if (l <= tl && tr <= r) {
        return t[v][x];
    }
    int tm = (tl + tr) / 2;
    int new_x = x & ((1 << c) - 1);
    if ((x >> c) & 1) {
        int L1 = l, R1 = min(tm, r), L2 = max(l, tm + 1), R2 = r;
        return qry(2*v+1, tm+1, tr, tm + 1 + L1 - tl, tm + 1 + R1 - tl, new_x, c - 1) + qry(2*v, tl, tm, tl + L2 - (tm + 1), tl + R2 - (tm + 1), new_x, c - 1);
    } else {
        return qry(2*v, tl, tm, l, r, new_x, c - 1) + qry(2*v+1, tm+1, tr, l, r, new_x, c - 1);
    }
}

void solve() {
    cin >> n >> s;
    string_hash::pre_hashes();

    build(1, 0, (1 << n) - 1);
    int x = 0;
    for (int i = 1; i < (1 << n); i++) {
        int lo = -1, hi = (1 << n), mid = (lo + hi) / 2;
        while (lo < mid && mid < hi) {
            H one = qry(1, 0, (1 << n) - 1, 0, mid, x, n - 1);
            H two = qry(1, 0, (1 << n) - 1, 0, mid, i, n - 1);
            if (one == two) lo = mid;
            else hi = mid;
            mid = (lo + hi) / 2;
        }
        if (lo == (1 << n) - 1) continue;
        if (s[(lo + 1) ^ i] < s[(lo + 1) ^ x]) {
            x = i;
        }
    }
    for (int i = 0; i < (1 << n); i++) cout << s[i ^ x];
    cout << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}