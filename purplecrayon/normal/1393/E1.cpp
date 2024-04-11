#include "bits/stdc++.h"
using namespace std;
 
template<class T> using min_pq=priority_queue<T, vector<T>, greater<T>>;
 
#define sz(v) (int)v.size()
#define ar array
// #define f first
// #define s second
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef unsigned int ui;
const int MAXN = 1e5+10, MAXM = 5e4+10, MAXL = 18, ALP = 26, MOD = 1e9+7, MAXK = 1e2+10,  MAXA = 10, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};
const ll INF = 1e9+10;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
typedef pair<int, int> pii;


typedef uint64_t ull;
static int C; // initialized below

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
H pw[MAXN];
struct HashInterval { //get hashes of any interval
	int n;
	vector<H> ha;
	string s;
    HashInterval(){}
	HashInterval(string& str) : ha(sz(str)+1), s(str) {
		n = sz(str);
		rep(i,0,n)
			ha[i+1] = ha[i] * C + str[i];
	}
	H get(int a, int b) { // hash for range [a, b]
		b++;
		return ha[b] - ha[a] * pw[b - a];
	}
};
int lcp(HashInterval& a, HashInterval& b){ //length of lcp of two strings
	if (a.n == 0 || b.n == 0 || a.get(0, 0) != b.get(0, 0)) return 0;
	int lo=0, hi=min(a.n, b.n)+1, mid=(lo+hi)/2;
	while (lo < mid && mid < hi){
		if (a.get(0, mid-1) == b.get(0, mid-1)) lo=mid;
		else hi=mid;
        mid=(lo+hi)/2;
	}
	return lo;
}
H hashString(string& s){H h{}; for(char c:s) h=h*C+c;return h;} //get hash of string
struct HashConcat {
	H h;
	int n;
	
	HashConcat(string& s) {
		n = sz(s), h = hashString(s);
	}
	HashConcat(H _h, int _n): h(_h), n(_n) {}
	HashConcat operator+(HashConcat& o){
		return HashConcat(h*pw[o.n]+o.h, n+o.n);
	}
	explicit operator H() { return h; }
};
#include <sys/time.h>
void pre_hashes(){ //call pre before testcases
	timeval tp;
	gettimeofday(&tp, 0);
	C = (int)tp.tv_usec; // (less than modulo)
	assert((ull)(H(1)*2+1-3) == 0);
	
	pw[0]=1;
	rep(i,0,MAXN-1)
		pw[i+1] = pw[i] * C;
		
}

int n;
string s[MAXN];
HashInterval h[MAXN];
vector<ll> dp[MAXN];
vector<ar<int, 2>> st[MAXN];

H get_pre(ar<int, 2> a, int len) {
    if (!len) return H();
    if (a[1] == 0) return h[a[0]].get(1, len);

    len--;
    if (len >= a[1]) {
        HashConcat l = HashConcat(h[a[0]].get(0, a[1]-1), a[1]);
        HashConcat r = HashConcat(h[a[0]].get(a[1]+1, len+1), len-a[1]+1);
        return H(l+r);
    }
    return h[a[0]].get(0, len);
}
bool comp(ar<int, 2> a, ar<int, 2> b) { //a[0] excluding a[1], b[0] excluding b[1], check if a < b
    int len_a = sz(s[a[0]])-(a[1] != sz(s[a[0]])), len_b = sz(s[b[0]])-(b[1] != sz(s[b[0]]));
    int len = min(len_a, len_b);

    if (get_pre(a, len) == get_pre(b, len)) {
        return len_a < len_b;
    }
    int lo=-1, hi=len, mid=(lo+hi)/2;
    while (lo < mid && mid < hi) {
        if (get_pre(a, mid) == get_pre(b, mid)) lo=mid;
        else hi=mid;
        mid=(lo+hi)/2;
    }
    int real_index_a = lo >= a[1] ? lo+1 : lo, real_index_b = lo >= b[1] ? lo+1 : lo;
    return s[a[0]][real_index_a] < s[b[0]][real_index_b];
}
bool eq(ar<int, 2> a, ar<int, 2> b) {
    return !comp(a, b) && !comp(b, a);
}
bool leq(ar<int, 2> a, ar<int, 2> b) {
    return comp(a, b) || eq(a, b);
}
void solve(){
	pre_hashes();

    cin >> n;
    for (int i = 0; i < n; i++) cin >> s[i], h[i] = HashInterval(s[i]);

    for (int i = 0; i < n; i++) {
        int m = sz(s[i]);
        dp[i].resize(m+1); st[i].reserve(m+1);

        for (int j = 0; j <= m; j++) st[i].push_back({i, j});
        stable_sort(st[i].begin(), st[i].end(), comp);
    }
    for (int i = 0; i < n; i++) {
        if (!i) { fill(dp[i].begin(), dp[i].end(), 1); continue; }
        int j = 0, m = sz(s[i]);

        ll sm = 0;
        for (int k = 0; k <= m; k++) {
            while (j < sz(st[i-1]) && leq(st[i-1][j], st[i][k])) {
                sm += dp[i-1][j], sm %= MOD;
                j++;
            }
            dp[i][k] = sm;
        }
    }
    ll ans=0;
    for (ll c : dp[n-1]) ans += c, ans %= MOD;
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t_c=1;
    //cin >> t_c;
    while (t_c--) solve();
}