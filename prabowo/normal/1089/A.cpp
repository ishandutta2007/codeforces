
#include<bits/stdc++.h>


#define pii pair<int,int>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define pf push_front
#define pb2 pop_back
#define pf2 pop_front
#define line printf("\n")
#define pq priority_queue
#define rep(k,i,j) for(int k = (int)i;k<(int)j;k++)
#define repd(k,i,j) for(int k = (int)i;k>=(int)j;k--)
#define ll long long
#define ALL(a) a.begin(),a.end()
#define vi vector<int>

using namespace std;

double EPS = 1e-9;
int INF = 1e9+7;;
long long INFLL = 1e17;
double pi = acos(-1);
int dirx[8] = {-1,0,0,1,-1,-1,1,1};
int diry[8] = {0,1,-1,0,-1,1,-1,1};

clock_t first_attempt = clock();
inline void cek_time(){
	clock_t cur = clock()- first_attempt;
	cerr<<"TIME : "<<(double) cur/CLOCKS_PER_SEC<<endl;
}
inline void OPEN (string s) {
	freopen ((s + ".in").c_str (), "r", stdin);
	freopen ((s + ".out").c_str (), "w", stdout);
}

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
typedef tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update> bbst;
//find_by_order(idx) : i-th index 
//order_of_key(val)  : val has which index

string to_string(string s) {
  return '"' + s + '"';
}

string to_string(const char* s) {
  return to_string((string) s);
}

string to_string(bool b) {
  return (b ? "true" : "false");
}

template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}

void debug_out() { cerr << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

//end of template

const int maxn = 205;
const int FLAG = INF * 2;
vector<pii> sc[2];
int DP[maxn][maxn][4][4];
int dp(int a,int b, int pta, int ptb) {
	if (a < 0 || b < 0 || pta < 0 || ptb < 0) return 0;
	if (pta + ptb == 0) return (a == 0 && b == 0); 
	
	int &ret = DP[a][b][pta][ptb];
	if (ret != -1) return ret;
	
	int rd = (pta + ptb == 5 ? 1 : 0);
	ret = 0;
	for (auto x : sc[rd]) if (a >= x.fi && b >= x.se) {
		int l = 0, r = 1;
		if (x.fi > x.se) swap(l, r);
		if (pta == 3 && !l) continue;
		if (ptb == 3 && !r) continue;
		ret = max(ret, dp(a - x.fi, b - x.se, pta - l, ptb - r));
	}
	
	return ret;
}

vector<pii> ans;
void bt(int a, int b, int pta, int ptb) {
	if (a < 0 || b < 0 || pta < 0 || ptb < 0) return;
	if (pta + ptb == 0) return; 
	
	int rd = (pta + ptb == 5 ? 1 : 0);
	
	for (auto x : sc[rd]) if (a >= x.fi && b >= x.se) {
		int l = 0, r = 1;
		if (x.fi > x.se) swap(l, r);
		if (pta == 3 && !l) continue;
		if (ptb == 3 && !r) continue;
		if (dp(a - x.fi, b - x.se, pta - l, ptb - r)) {
			bt(a - x.fi, b - x.se, pta - l, ptb - r);
			ans.pb(x);
			return;
		}
	}
}

int main() {
	memset(DP, -1, sizeof DP);
	
	rep(k, 26, maxn) {
		int i = k - 2;
		sc[0].pb({k, i});
		sc[0].pb({i, k});
	}
	
	rep(k, 0, 24) {
		sc[0].pb({25, k});
		sc[0].pb({k, 25});
	}
	
	rep(k, 16, maxn) {
		int i = k - 2;
		sc[1].pb({k, i});
		sc[1].pb({i, k});
	}
	
	rep(k, 0, 14) {
		sc[1].pb({15, k});
		sc[1].pb({k, 15});
	}
	
	int t;
	cin >> t;
	while(t--) {
		int x, y;
		cin >> x >> y;
		
		ans.clear();
		pii cur = {-INF, 0};
		rep(k, 0, 4) rep(i, 0, 4) {
			if (k != 3 && i != 3) continue;
			if (k == 3 && i == 3) continue;
			
			if (!dp(x, y, k, i)) continue;
			if (cur.fi - cur.se < k - i) cur = {k, i};
		}
		
		if (cur.fi == -INF) puts("Impossible");
		else {
			bt(x, y, cur.fi, cur.se);
			
			printf("%d:%d\n", cur.fi, cur.se);
			for (auto p : ans) printf("%d:%d ", p.fi, p.se);
			puts("");
			
			for (auto p : ans) {
				x -= p.fi;
				y -= p.se;
				cur.fi -= (p.fi > p.se);
				cur.se -= (p.fi < p.se);
			}
			assert(x == 0 && !y && !cur.fi && !cur.se);
		}
		
	}
}