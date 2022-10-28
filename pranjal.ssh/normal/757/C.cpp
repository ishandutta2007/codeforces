#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define FOR(i,a,b) for (int i = (a); i <= (b); ++i)
#define NFOR(i,a,b) for(int i = (a); i >= (b); --i)
#define all(x) (x).begin(), (x).end()
#define sz(x) int(x.size())
typedef long long ll;typedef pair <int, int> ii;typedef vector <int> vi; const int inf = 1e9 + 7;
#define pr(...) dbs(#__VA_ARGS__, __VA_ARGS__)
template <class T> void dbs(string str, T t) {cerr << str << " : " << t << "\n";}
template <class T, class... S> void dbs(string str, T t, S... s) {int idx = str.find(',');cerr << str.substr(0, idx) << " : " << t << ",";dbs(str.substr(idx + 1), s...);}
template <class S, class T>ostream& operator <<(ostream& os, const pair<S, T>& p) {return os << "(" << p.first << ", " << p.second << ")";}
template <class T>ostream& operator <<(ostream& os, const vector<T>& p) {os << "[ ";for (auto& it : p) os << it << " ";return os << "]";}
template <class T>ostream& operator <<(ostream& os, const set<T>& p) {os << "[ ";for (auto& it : p) os << it << " ";return os << "]";}
template <class S, class T>ostream& operator <<(ostream& os, const map<S, T>& p) {os << "[ ";for (auto& it : p) os << it << " ";return os << "]";}
template <class T> void prc(T a, T b) {cerr << "[";for (T i = a; i != b; ++i) {if (i != a) cerr << ", ";cerr << *i;}cerr << "]\n";}
struct dis_set
{
	vi p, r, Size;
	dis_set(int n):p(n),r(n), Size(n){FOR(i, 0, n - 1)p[i] = i, Size[i] = 1;}

	int get(int i)
	{
		if (p[i] != i)p[i] = get(p[i]);
		return p[i];
	}
	int connect(int i, int j)
	{
		int x = get(i), y = get(j);
		if (x == y) return 0;
		if (r[x] < r[y])p[x] = y, Size[y] += Size[x];
		else {p[y] = x;Size[x] += Size[y]; if (r[x] == r[y])++r[x];}
		return 1;
	}
};

const int N = 1e5;
const int M = 1e6;
vector<ii> g[N + 10];
vector<ii> f[M + 10];
inline int mul(int a, int b) {
	return (a*1LL*b) % inf;
}
int fac[M + 10];


int main() 
{
   ios::sync_with_stdio(0); cin.tie(0);

   int n, m; cin >> n >> m;
   fac[0] = 1;
   FOR (i, 1, m) fac[i] = mul(i, fac[i - 1]);
   FOR (id, 1, n) {
   	int x; cin >> x;
   	vi t(x);
   	FOR (i, 0, x - 1) cin >> t[i];
   	sort(all(t));
   	FOR (i, 0, x - 1) {
   		int freq = 1;
   		int j = i;
   		while (j < x and t[j] == t[i]) ++j, ++freq;
   		i = j - 1;
   		g[id].push_back({freq, t[i]});
   		f[t[i]].push_back({id, freq});
   	}
   	sort(all(g[id]));
   }
   sort(f + 1, f + m + 1);
   int ans = 1;
   FOR (i, 1, m) {
   	int j = i;
   	int freq = 0;
   	while (j <= m and f[j] == f[i]) ++j, ++freq;
   	ans = mul(ans, fac[freq]);
   	i = j - 1;
   }
   cout << ans;

   return 0;
}