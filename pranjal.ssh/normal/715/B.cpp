#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
// #include <sys/resource.h>

using namespace std;
using namespace __gnu_pbds;



typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int> > vvi;

typedef vector<vll> vvll;
typedef pair<int, int> ii;
typedef pair<ll, ii> iii;
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
#define boost ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)

#define pb push_back
#define MP make_pair
#define F first
#define S second
#define FOR(i,a,b) for(ll i=(a);i<=(b);++i)
#define NFOR(i,a,b) for(int i=(a);i>=(b);--i)
#define TCASE int __T;cin>>__T;FOR(Tc,1,__T)
#define ass(n,l,r) assert(n>=l and n<=r)


vvii g;
vll e;
vii edges;

const ll INF = 1e13;

int main()
{
	// boost;
	int n, m, L, s, t;
	cin >> n >> m >> L >> s >> t;

	g = vvii(n);
	e = vll(m);
	edges = vii(m);

	FOR(i, 0, m - 1) {
		int u, v, w;
		cin >> u >> v >> w;
		e[i] = w;
		edges[i] = {u, v};
		g[u].pb({v, i});
		g[v].pb({u, i});
	}

	priority_queue<iii, vector<iii>, greater<iii> > Q;

	vvll D(n, vll(n, INF * 10));
	vvi dad(n, vi(n, -1));
	vvi daddy(n, vi(n, -1));

	D[0][s] = 0;
	Q.push(iii(0LL, ii(0, s)));

	while (!Q.empty()) {
		iii top = Q.top();
		Q.pop();
		// pr(top);
		int v = top.S.S;
		ll d = top.F;
		int times = top.S.F;
		
		if (d <= D[times][v]) {
			for (auto it : g[v]) {
				
				int v2 = it.F;
				ll cost = e[it.S];
				int times2 = (times + (e[it.S] == 0));

				if (times2 < n and D[times2][v2] > D[times][v] + cost) {

					D[times2][v2] = D[times][v] + cost;
					dad[times2][v2] = v;
					daddy[times2][v2] = it.S;

					Q.push(iii(D[times2][v2], ii(times2, v2)));
				}
			}
		}
	}
	
	if (D[0][t] < L) {
		cout << "NO\n"; return 0;
	}

	if (D[0][t] == L) {
		cout<<"YES\n";
		FOR(i, 0, m - 1) {
			cout << edges[i].F << " " << edges[i].S << " ";
			if (e[i] == 0)cout << INF * 10 << "\n";
			else cout << e[i] << "\n";
		}
		return 0;
	}
	// return 0;

	FOR(i, 1, n - 1) {
		int temp = i;
		if (D[i][t] + i <= L) {
			int x = t;
			while (1) {
				if (e[daddy[i][x]] == 0) {
					e[daddy[i][x]] = 1 + L - D[i][t] - i;

					x = dad[i][x];
					int j = i-1;
					while (1) {
						if (dad[j][x] == -1)break;
						int bc = 0;
						if (e[daddy[j][x]] == 0) e[daddy[j][x]] = 1,bc=1;
						x = dad[j][x];
						j-=bc;
					}
					break;
				}
				x = dad[i][x];
			}
			cout<<"YES\n";
			FOR(i, 0, m - 1) {
				cout << edges[i].F << " " << edges[i].S << " ";
				if (e[i] == 0)cout << INF * 10 << "\n";
				else cout << e[i] << "\n";
			}
			return 0;
		}
		i = temp;
	}



	cout << "NO\n";



	return 0;
}