// Not my code https://codeforces.com/contest/1580/submission/138986509
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
 
#include <bits/stdc++.h>
 
#define fix(f,n) std::fixed<<std::setprecision(n)<<f
 
typedef long long ll;
 
int mod = 1e9 + 7;
 
int dx[4] = {1, 0, -1, 0}; 
int dy[4] = {0, -1, 0, 1}; 
char direction[4] = {'D', 'L', 'U', 'R'}; 
 
using namespace std;
 
// template <typename T>
// using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
// template <typename T>
// using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>; 
 
#ifdef ADD_TRACE
template<typename T>
void __p(T a) {
	cout<<a;
}
template<typename T, typename F>
void __p(pair<T, F> a) {
	cout<<"{";
	__p(a.first);
	cout<<",";
	__p(a.second);
	cout<<"}";
}
template<typename T>
void __p(std::vector<T> a) {
	cout<<"{";
	for(auto it=a.begin(); it<a.end(); it++)
		__p(*it),cout<<",}"[it+1==a.end()];
}
template<typename T>
void __p(std::set<T> a) {
	cout<<"{";
	for(auto it=a.begin(); it!=a.end();){
		__p(*it); 
		cout<<",}"[++it==a.end()];
	}
 
}
template<typename T>
void __p(std::multiset<T> a) {
	cout<<"{";
	for(auto it=a.begin(); it!=a.end();){
		__p(*it); 
		cout<<",}"[++it==a.end()];
	}
}
template<typename T, typename F>
void __p(std::map<T,F> a) {
	cout<<"{\n";
	for(auto it=a.begin(); it!=a.end();++it)
	{
		__p(it->first);
		cout << ": ";
		__p(it->second);
		cout<<"\n";
	}
	cout << "}\n";
}
 
template<typename T, typename ...Arg>
void __p(T a1, Arg ...a) {
	__p(a1);
	__p(a...);
}
template<typename Arg1>
void __f(const char *name, Arg1 &&arg1) {
	cout<<name<<" : ";
	__p(arg1);
	cout<<endl;
}
template<typename Arg1, typename ... Args>
void __f(const char *names, Arg1 &&arg1, Args &&... args) {
	int bracket=0,i=0;
	for(;; i++)
		if(names[i]==','&&bracket==0)
			break;
		else if(names[i]=='(')
			bracket++;
		else if(names[i]==')')
			bracket--;
	const char *comma=names+i;
	cout.write(names,comma-names)<<" : ";
	__p(arg1);
	cout<<" | ";
	__f(comma+1,args...);
}
#define trace(...) cout<<"Line:"<<__LINE__<<" ", __f(#__VA_ARGS__, __VA_ARGS__)
#else
#define trace(...)
#endif
 
// struct edge{
// 	int a, b, weight;
 
// 	bool operator < (edge other) const {
// 		return weight < other.weight; 
// 	}
// };
		
// struct custom_hash {
//     static uint64_t splitmix64(uint64_t x) {
//         x += 0x9e3779b97f4a7c15;
//         x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
//         x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
//         return x ^ (x >> 31);
//     }
 
//     size_t operator()(uint64_t x) const {
//         static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
//         return splitmix64(x + FIXED_RANDOM);
//     }
// };
 
//Use chash with gp_hash_table
// const int RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();
// struct chash { // To use most bits rather than just the lowest ones:
// 	const uint64_t C = ll(4e18 * acos(0)) | 71; // large odd number
// 	ll operator()(ll x) const { return __builtin_bswap64((x^RANDOM)*C); }
// };
 
// struct Basis {
// 	int size = 0;
// 	int max_bits = 0;  
// 	vector<int> basis; 
 
// 	Basis(int n) {
// 		max_bits = n; 
// 		basis = vector<int>(n); 
// 	}
 
// 	Basis(const Basis& b) {
// 		this->size = b.size; 
// 		this->max_bits = b.max_bits; 
// 		this->basis = b.basis; 
// 	}
 
// 	void insertVector(int x) {
// 		for(int i = 0; i < max_bits; i++) {
// 			if(x & (1 << i)) {
// 				if(!basis[i]) {
// 					basis[i] = x; 
// 					size++; 
// 					break; 
// 				} else x ^= basis[i]; 
// 			}
// 		}
// 	}
// };
 
// vector<int> sieveOfEratosthenes(int n) {
// 	vector<int> primes;
// 	bool prime[n + 1];
// 	memset(prime, true, sizeof(prime));
// 	for (int p = 2; p * p <= n; p++) {
// 		if (prime[p] == true) {
// 			for (int i = p * p; i <= n; i += p)
// 				prime[i] = false;
// 		}
// 	}
// 	for (int p = 2; p <= n; p++)
// 		if (prime[p])
// 			primes.push_back(p);
// 	return primes;
// }
 
// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
// ll getRand(ll l, ll r) {
// 	uniform_int_distribution<ll> uid(l, r); 
// 	return uid(rng); 
// }
 
// //Dont forget to reset MOD if some other MOD is needed
// const ll MOD = 1e9+7;
 
// //Comment the line above and uncomment the line below if problem requires more than 1 MOD
// //After uncommenting the below line, declaration of Mint becomes [ Mint<mod> M; ]
 
// //template<ll MOD>
// class Mint
// {
// 	//WARNING:
// 	//Be very careful not to use two Mints with different mods for any operation
// 	//No guarantee of behavior in this case
// 	public:
// 	ll val;
// 	static ll mod_exp(ll a, ll b){ ll res=1;   a=a%MOD; while(b>0){ if(b%2==1) res=(res*a)%MOD; b/=2; a=(a*a)%MOD; } return res; }
// 	static ll gcdExtended(ll a, ll b, ll *x, ll *y) { if (a == 0) { *x = 0, *y = 1; return b; } ll x1, y1; ll gcd = gcdExtended(b%a, a, &x1, &y1);*x = y1 - (b/a) * x1; *y = x1; return gcd; }
// 	static ll modInverse(ll a) { ll x, y; 	ll g = gcdExtended(a, MOD, &x, &y); g++; ll res = (x%MOD);	if(res < 0) res += MOD;	return res;} 
// 	Mint(){	val = 0;} 
// 	Mint(ll x){	val = x%MOD;	if(val < 0) val += MOD;}
// 	Mint& operator +=(const Mint &other){	val += other.val;	if(val >= MOD) val -= MOD; return (*this); }
// 	Mint& operator -=(const Mint &other){   val -= other.val;if(val < 0) val += MOD;  return (*this); }
// 	Mint& operator *=(const Mint &other){	val = (val * other.val)%MOD; return (*this); }
// 	Mint& operator /=(const Mint &other){	val = (val * modInverse(other.val)) % MOD; return (*this); }
// 	Mint& operator =(const Mint &other) { 	val = other.val; return (*this); }
// 	Mint operator +(const Mint &other) const {	return Mint(*this) += other; }
// 	Mint operator -(const Mint &other) const {	return Mint(*this) -= other; }
// 	Mint operator *(const Mint &other) const {	return Mint(*this) *= other; }
// 	Mint operator /(const Mint &other) const {	return Mint(*this) /= other; }
// 	bool operator ==(const Mint &other) const {   return val == other.val; }
 
// 	Mint operator ++() { ++val; if(val == MOD) val = 0; return (*this); }
// 	Mint operator ++(int) { val++; if(val == MOD) val = 0; return Mint(val-1); }
// 	Mint operator --() { --val; if(val == -1) val = MOD-1; return (*this); }
// 	Mint operator --(int) { val--; if(val == -1) val = MOD-1; return Mint(val+1); }
 
// 	// ^ has very low precedence, careful!!
 
// 	template<typename T>
// 	Mint& operator ^=(const T &other){   val = mod_exp(val, other); return (*this); }
// 	template<typename T>
// 	Mint operator ^(const T &other) const {  return Mint(*this) ^= other; }
 
// 	Mint& operator ^=(const Mint &other){   val = mod_exp(val, other.val); return (*this); }
// 	Mint operator ^(const Mint &other) const {  return Mint(*this) ^= other; }
 
// 	template<typename T>
// 	explicit operator T() {	return (T)val; }
// 	template<typename T>
// 	friend Mint operator +(T other, const Mint &M){	return Mint(other) + M; }
// 	template<typename T>
// 	friend Mint operator -(T other, const Mint &M){	return Mint(other) - M; }
// 	template<typename T>
// 	friend Mint operator *(T other, const Mint &M){	return Mint(other) * M; }
// 	template<typename T>
// 	friend Mint operator /(T other, const Mint &M){	return Mint(other) / M; }
// 	template<typename T>
// 	friend Mint operator ^(T other, const Mint &M){	return Mint(other) ^ M; }
 
 
// 	friend std::ostream &operator << (std::ostream &output, const Mint &M){  return output << M.val; }
// 	friend std::istream &operator >> (std::istream &input, Mint &M) { input >> M.val;	M.val %= MOD;	return input;}
// };
 
 
void solve() {
	int n, m; 
	cin >> n >> m; 
 
	vector<vector<int>> a(n, vector<int>(m)); 
	vector<vector<int>> g(n+1, vector<int>(m+1));
 
	string s; 
	for(int i = 0; i < n; ++i) {
		cin >> s; 
		for(int j = 0; j < m; ++j) {
			a[i][j] = s[j] - '0'; 
		}
	}
 
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) {
			g[i+1][j+1] = g[i][j+1] + g[i+1][j] - g[i][j] + a[i][j]; 
		}
	}
 
	trace(a); 
	trace(g); 
 
	auto get = [&](int r2, int c2, int r1, int c1) {
		return g[r2+1][c2+1] - g[r1][c2+1] - g[r2+1][c1] + g[r1][c1]; 
	}; 
 
	auto get_cost = [&](int r2, int c2, int r1, int c1) {
		trace(r2, c2, r1, c1); 
		trace(get(r2-1, c2-1, r1+1, c1+1)); 
		trace(get(r2-1, c2, r1+1, c2)); 
		trace(get(r2-1, c1, r1+1, c1)); 
		trace(get(r2, c2-1, r2, c1+1)); 
		trace(get(r1, c2-1, r1, c1+1)); 
		return get(r2-1, c2-1, r1+1, c1+1) + 2 * (r2 - r1 - 1) - get(r2-1, c2, r1+1, c2) - get(r2-1, c1, r1+1, c1) + 2 * (c2 - c1 - 1) - get(r2, c2-1, r2, c1+1) - get(r1, c2-1, r1, c1+1); 
	}; 
 
	int ans = n * m; 
 
	vector<int> cost(m); 
	vector<int> minind(m); 
	for(int r1 = 0; r1 < n; ++r1) {
		for(int r2 = r1 + 4; r2 < n; ++r2) {
			trace(r1, r2); 
 
			// cost[3] = get(r2-1, 2, r1+1, 1) + 4 - get(r2, 2, r2, 1) - get(r1, 2, r1, 1) + 2 * (r2 - r1 - 1) - get(r2 - 1, 0, r1 + 1, 0) - get(r2-1, 3, r1 + 1, 3); 
			cost[3] = get_cost(r2, 3, r1, 0); 
			for(int c = 4; c < m; ++c) {
				cost[c] = cost[c-1] + 2 - a[r1][c-1] - a[r2][c-1] + 2 * get(r2-1, c-1, r1+1, c-1) - get(r2-1, c, r1+1, c); 
			}
 
			trace(cost); 
 
			minind[m-1] = m-1; 
			for(int i = m-2; i >= 0; --i) {
				if(cost[i] < cost[minind[i+1]]) {
					minind[i] = i; 
				} else {
					minind[i] = minind[i+1]; 
				}
			}			
 
			trace(minind); 
 
			for(int l = 0; l+3 < m; ++l) {
				int r = minind[l+3]; 
				ans = min(ans, get_cost(r2, r, r1, l)); 
				trace(l, r, ans); 
			}
		}
	}
 
	cout << ans << '\n';
}
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t = 1;
	cin >> t;
	for (int i = 0; i < t; i++) {
		solve();
	}
	return 0;
}