#pragma GCC optimize ("O3", "unroll-loops")
// #pragma GCC target ("avx2")
// #pragma comment(linker, "/stack:200000000")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include "bits/stdc++.h"
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define distinct(x) sort(all(x)); x.resize(unique(all(x))-x.begin())
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define CASE(x) int x; cin >> x; while (x--)
#define CASEt(x) int x; cin >> x; for (int tc = 1; tc <= x; ++tc)
using namespace std;
namespace {
	const int MOD107 = 1000000007;
	const int MOD998 = 998244353;
	using ll = long long;
	using ull = unsigned long long;
	using pii = pair<int, int>;
	using pll = pair<ll, ll>;
	template <class T> using minheap = priority_queue<T, vector<T>, greater<T>>;
	template <class T> using maxheap = priority_queue<T, vector<T>, less<T>>;
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//	mt19937_64 rng64(chrono::steady_clock::now().time_since_epoch().count());
	struct Modular {
	private:
		long long MODVALUE = 0;
		long long val = 0;
 
		Modular initModular(long long val) const { return Modular(val, MODVALUE); }
 
	#ifdef LOCAL
		inline void validate() const {
			assert(MODVALUE != 0);
			assert(0 <= val && val < MODVALUE);
		}
 
		inline void validate(const Modular& other) const {
			validate();
			other.validate();
			assert(MODVALUE == other.MODVALUE);
		}
	#else
		inline void validate() const { }
		inline void validate(const Modular& other) const { }
	#endif
 
	public:
		explicit operator long long() const { return val; }
 
		template<class T> Modular& operator = (const T& other) { val = (other % MODVALUE + MODVALUE) % MODVALUE; return *this; }
		long long getMod() { return MODVALUE; }
		template<class T> void setMod(const T& MOD) { MODVALUE = MOD; }
 
		Modular& operator += (const Modular& other)       { validate(other); val += other.val; if (val >= MODVALUE) val -= MODVALUE; return *this; }
		Modular  operator +  (const Modular& other) const { Modular tmp = *this; return tmp += other; }
		template<class T> Modular& operator += (const T& other)       { return *this += initModular(other); }
		template<class T> Modular  operator +  (const T& other) const { return *this +  initModular(other); }
		template<class T> friend Modular operator + (const T& other, const Modular& m) { return m.initModular(other) + m; }
 
		Modular& operator ++()    { return *this += 1; }
		Modular  operator ++(int) { Modular tmp = *this; ++*this; return tmp; }
 
		Modular  operator -  () const { return initModular(-val); }
		Modular& operator -= (const Modular& other)       { validate(other); val -= other.val; if (val < 0) val += MODVALUE; return *this;}
		Modular  operator -  (const Modular& other) const { Modular tmp = *this; return tmp -= other; }
		template<class T> Modular& operator -= (const T& other)       { return *this -= initModular(other); }
		template<class T> Modular  operator -  (const T& other) const { return *this -  initModular(other); }
		template<class T> friend Modular operator - (const T& other, const Modular& m) { return m.initModular(other) - m; }
 
		Modular& operator --()    { return *this -= 1; }
		Modular  operator --(int) { Modular tmp = *this; --*this; return tmp; }
 
		Modular& operator *= (const Modular& other)       { validate(other); val *= other.val; val %= MODVALUE; if (val < 0) val += MODVALUE; return *this; }
		Modular  operator *  (const Modular& other) const { Modular tmp = *this; return tmp *= other; }
		template<class T> Modular& operator *= (const T& other)       { return *this *= initModular(other); }
		template<class T> Modular  operator *  (const T& other) const { return *this *  initModular(other); }
		template<class T> friend Modular operator * (const T& other, const Modular& m) { return m.initModular(other) * m; }
 
		Modular pow(long long power) const {
			Modular m = *this, ans = initModular(1);
			while (power) {
				if (power & 1) ans *= m;
				m *= m;
				power >>= 1;
			}
			return ans;
		}
		Modular pow(const Modular& other) const { return pow(other.val); }
		Modular inv() const { return pow(MODVALUE - 2); }
 
		Modular& operator /= (const Modular& other)       { val *= other.inv().val; val %= MODVALUE; if (val < 0) val += MODVALUE; return *this; }
		Modular  operator /  (const Modular& other) const { Modular tmp = *this; return tmp /= other; }
		template<class T> Modular& operator /= (const T& other)       { return *this /= initModular(other); }
		template<class T> Modular  operator /  (const T& other) const { return *this /  initModular(other); }
		template<class T> friend Modular operator / (const T& other, const Modular& m) { return m.initModular(other) / m; }
 
		friend istream& operator >> (istream& in, Modular& m) { in >> m.val; m.val %= m.MODVALUE; if (m.val < 0) m.val += m.MODVALUE; return in; }
		friend ostream& operator << (ostream& out, const Modular& m) { return out << m.val; }
 
		Modular() { val = 0; MODVALUE = 0; }
		Modular(long long val, long long MOD) : MODVALUE(MOD), val((val % MOD + MOD) % MOD) { }
	};
	using Mint = Modular;
	inline ll binpow(ll b, ll p, ll mod) {
		b %= mod;
		ll ans = 1;
		for (; p > 0; p >>= 1) {
			if (p&1) {ans *= b; ans %= mod;}
			b *= b;
			b %= mod;
		}
		return ans;
	}
	inline ll max(ll a, int b) { return (a > b ? a : b); }
	inline ll max(int a, ll b) { return (a > b ? a : b); }
	inline ll min(ll a, int b) { return (a < b ? a : b); }
	inline ll min(int a, ll b) { return (a < b ? a : b); }
	template <class T> inline bool chkmin(T&x, const T& y) { return y < x ? x = y, 1 : 0; }
	template <class T> inline bool chkmax(T&x, const T& y) { return x < y ? x = y, 1 : 0; }
}
namespace IO {
	struct InputWrapper {
	private:
		istream& in;

	public:
		template<class T> inline void _R(T &x) { in >> x; }
		template<class T1, class T2> inline void _R(pair<T1,T2> &x) { _R(x.first); _R(x.second); }
		template<class T> inline void _R(vector<T> &x) { for (auto& i : x) _R(i); }
		template<class T> inline void _R(deque<T> &x) { for (auto& i : x) _R(i); }
		inline void R() { }
		template<class T1, class... T2> inline void R(T1 &x, T2 &...y) { _R(x); R(y...); }
		template<class... T> inline void operator () (T &...x) { R(x...); }
		InputWrapper(istream& in) : in(in) { }
	} R(cin);

	struct OutputWrapper {
	private:
		ostream& out;
		
	public:
		template<class Container> inline void printContainer(const Container& x) { bool isFirst = 1; for (auto i : x) { if (!isFirst) out << ' '; isFirst = 0; _W(i); } }
		template<class T> inline void _W(const T& x) { out << x; }

		template<class T1, class T2> inline void _W(const pair<T1,T2>& p) {_W(p.first); _W(' '); _W(p.second);}
		template<class... T> inline void _W(const vector<T...>& x) { printContainer(x); }
		template<class... T> inline void _W(const deque<T...>& x) { printContainer(x); }
		template<class... T> inline void _W(const forward_list<T...>& x) { printContainer(x); }
		template<class... T> inline void _W(const list<T...>& x) { printContainer(x); }
		template<class... T> inline void _W(const set<T...>& x) { printContainer(x); }
		template<class... T> inline void _W(const multiset<T...>& x) { printContainer(x); }
		template<class... T> inline void _W(const unordered_set<T...>& x) { printContainer(x); }
		template<class... T> inline void _W(const unordered_multiset<T...>& x) { printContainer(x); }
		template<class... T> inline void _W(const map<T...>& x) { printContainer(x); }
		template<class... T> inline void _W(const multimap<T...>& x) { printContainer(x); }
		template<class... T> inline void _W(const unordered_map<T...>& x) { printContainer(x); }
		template<class... T> inline void _W(const unordered_multimap<T...>& x) { printContainer(x); }

		inline void W() { out << '\n'; }
		template<class T> inline void W(const T &x) { _W(x); W(); }
		template<class T1, class... T2> inline void W(const T1 &x, const T2 &...y) { _W(x); _W(' '); W(y...); }
		template<class... T> inline void operator () (const T &...x) { W(x...); }
		OutputWrapper(ostream& out) : out(out) { }
	} W(cout), D(cerr);
} using namespace IO;
namespace outputFormat{
	inline string Case(int tc) {return "Case #" + to_string(tc) + ':';}
	inline string YN(bool b) {return b ? "Yes" : "No";}
} using namespace outputFormat;
namespace std {
	template <class T1, class T2> struct hash<pair<T1,T2>> {
		std::size_t operator()(pair<T1,T2> _) const {
			return hash<T1>{}(_.first) ^ hash<T2>{}(_.second);
		}
	};
}


int main() {
	int n,s; R(n,s); s--;
	vector<int> a(n); R(a);

	vector<int> numUsed = a;
	distinct(numUsed);
	
	for (int i = 0; i < n; i++)
		a[i] = lower_bound(all(numUsed), a[i]) - numUsed.begin();

	const int NUM_COUNT = (int)numUsed.size();
	vector<vector<int>> pos(NUM_COUNT);
	for (int i = 0; i < n; i++)
		pos[a[i]].emplace_back(i);

	vector<int> dp(n, 1e9);
	vector<int> last_pos(n, -1);
	vector<int> starting_idx(n, -1);
	vector<int> moving_dir(n, 0);
	vector<int> starting_dist(n, 0);
	auto upd = [&](int from, int baseAns, int val) {
		const int sz = (int)pos[val].size();
		if (sz == 1) {
			int cur = pos[val][0];
			int dist = pos[val][0] - from;
			if (dist <= 0) dist += n;

			if (chkmin(dp[cur], baseAns + dist)) {
				last_pos[cur] = from;
				starting_idx[cur] = 0;
				moving_dir[cur] = -1;
				starting_dist[cur] = dist;
			}

			dist = n - dist;
			if (chkmin(dp[cur], baseAns + dist)) {
				last_pos[cur] = from;
				starting_idx[cur] = 0;
				moving_dir[cur] = 1;
				starting_dist[cur] = -dist;
			}
		}
		else {
			for (int i = 0; i < sz; i++) {
				int cur = pos[val][i];
				int nxt = pos[val][(i + 1) % sz];
				int lst = pos[val][(i + sz - 1) % sz];
				
				{
					int dist = cur - from;
					if (dist <= 0) dist += n;
					int aux_dist = from - nxt;
					if (aux_dist < 0) aux_dist += n;

					if (chkmin(dp[cur], baseAns + dist + aux_dist * 2)) {
						last_pos[cur] = from;
						starting_idx[cur] = (i + 1) % sz;
						moving_dir[cur] = 1;
						starting_dist[cur] = -aux_dist;
					}
				}

				{
					int dist = from - cur;
					if (dist <= 0) dist += n;
					int aux_dist = lst - from;
					if (aux_dist < 0) aux_dist += n;

					if (chkmin(dp[cur], baseAns + dist + aux_dist * 2)) {
						last_pos[cur] = from;
						starting_idx[cur] = (i + sz - 1) % sz;
						moving_dir[cur] = -1;
						starting_dist[cur] = aux_dist;
					}
				}
			}

			int adjNext = lower_bound(all(pos[val]), from) - pos[val].begin();
			if (adjNext == (int)pos[val].size()) adjNext = 0;
			int adjLast = adjNext - 1;
			if (adjLast == -1) adjLast = sz - 1;

			{
				int cur = pos[val][adjNext];
				int dist = from - cur;
				if (dist <= 0) dist += n;
				if (chkmin(dp[pos[val][adjNext]], baseAns + dist)) {
					last_pos[cur] = from;
					starting_idx[cur] = (adjNext + sz - 1) % sz;
					moving_dir[cur] = -1;
					starting_dist[cur] = from - pos[val][(adjNext + sz - 1) % sz];
					if (starting_dist[cur] < 0)
						starting_dist[cur] += n;
					starting_dist[cur] *= -1;
				}
			}

			{
				int cur = pos[val][adjLast];
				int dist = cur - from;
				if (dist <= 0) dist += n;
				if (chkmin(dp[pos[val][adjLast]], baseAns + dist)) {
					last_pos[cur] = from;
					starting_idx[cur] = (adjLast + 1) % sz;
					moving_dir[cur] = 1;
					starting_dist[cur] = pos[val][(adjLast + 1) % sz] - from;
					if (starting_dist[cur] < 0)
						starting_dist[cur] += n;
				}
			}
		}
	};
	upd(s, 0, 0);
	for (int i = 1; i < NUM_COUNT; i++)
		for (auto& j : pos[i - 1])
			upd(j, dp[j], i);

	int ans = INT_MAX;
	int now = -1;
	for (auto& i : pos[NUM_COUNT - 1])
		if (chkmin(ans, dp[i]))
			now = i;

	vector<int> moves;
	for (int currentNum = NUM_COUNT - 1; currentNum >= 0; currentNum--, now = last_pos[now]) {
		const int sz = pos[currentNum].size();

		vector<int> tmpMoves = { starting_dist[now] };
		
		for (int cur = starting_idx[now], nxt = (cur + moving_dir[now] + sz) % sz; pos[currentNum][cur] != now; cur = nxt, nxt = (nxt + moving_dir[now] + sz) % sz) {
			const int curPos = pos[currentNum][cur];
			const int nxtPos = pos[currentNum][nxt];
			int dist = (nxtPos - curPos) * moving_dir[now];
			if (dist <= 0) dist += n;
			tmpMoves.emplace_back(dist * moving_dir[now]);
		}

		reverse(all(tmpMoves));
		moves.insert(moves.end(), all(tmpMoves));
	}

	reverse(all(moves));

	W(ans);
	for (auto& i : moves) {
		if (i >= 0) W._W('+');
		W(i);
	}

	return 0;
}

static auto __init__ = [](){
#ifndef LOCAL
	ios::sync_with_stdio(false);
	cin.tie(0);
#endif
	cout << fixed << setprecision(10);
	return 42;
}();