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

int n;

const int maxn = 30;
int g[maxn][maxn], g2[maxn][maxn];

vi lvl[maxn];
vector<vi> scc;

int par[maxn];
int rt(int a){ return par[a] = (par[a] == a ? a : rt(par[a]));}
void join(int a, int b) { a = rt(a), b = rt(b); if (a != b) par[a] = b; }

int in[maxn];
int glvl[maxn][maxn];

void toposort() {
	rep(k, 0, n) rep(i, 0, n) in[i] += g2[k][i];
	
	vector<int> ans;
	queue<int> q;
	rep(k, 0, n) if (rt(k) == k && in[k] == 0) 
		q.push(k);
	
	while(q.size()) {
		int a = q.front();
		q.pop();
		
		ans.pb(a);
		rep(i, 0, n) if (g2[a][i]) {
			in[i]--;
			if (!in[i]) q.push(i);
		}
	}
	
	rep(k, 0, ans.size()) {
		int a = ans[k];
		rep(i, 0, n) if (rt(i) == a) {
			lvl[k].pb(i);
		}
		
		rep(i, k + 1, ans.size()) {
			if (g2[a][ans[i]]) glvl[k][i] = 1;
		}
	}
}

// size = 18 x 3 x 18
const int H = 18, R = 3, C = 18 * 9;

char grid[H][R][C];
void dummy(int lvl) {
	rep(i, 0, C) printf("#"); puts("");
	rep(i, 0, C) printf("#"); puts("");
	rep(i, 0, C) {
		if (i / 2 == lvl) printf("#");
		else printf("."); 
	}
	puts("");
}

// req: glvl
void solve() {
	memset(grid, '.', sizeof grid);
	//create floor
	for (int k = 1; k < H; k+= 2) rep(i, 0, 2) rep(j, 0, C) 
		grid[k][i][j] = '#';
		
	// create wall
	for (int k = 0; k < H; k+= 2) rep(i, 1, 2) rep(j, 0, C) 
		grid[k][i][j] = '#';
		
	// create tunnel wall
	rep(k, 0, H) rep(i, 2, 3) for (int j = 1; j < C; j+= 2)
		grid[k][i][j] = '#';
	
	// create tunner floor
	rep(x, 0, n) rep(y, x + 1, n) {
		grid[2*y + 1][2][(x * 9 + y) * 2] = '#';
	}
	
	// create tunner door
	rep(x, 0, n) rep(y, x + 1, n) if (glvl[x][y]){
		// upper part
		grid[2*x][1][(x * 9 + y) * 2] = '.';
		// floor part
		grid[2*y][1][(x * 9 + y) * 2] = '.';
	}
	
	// create number
	
	rep(k, 0, n) rep(i, 0, lvl[k].size()) grid[2 * k][0][i] = '0' + lvl[k][i] + 1;
	
	printf("%d %d %d\n", C, R, H);
	rep(k, 0, H) {
		if (k) puts("");
		rep(i, 0, R) { rep(j, 0, C) printf("%c", grid[k][i][j]); puts(""); }
	}
}
int main() {
	cin >> n;
	rep(k, 0, n) rep(i, 0, n) {
		cin >> g[k][i];
	}
	
	rep(k, 0, n) rep(i, 0, n) rep(j, 0, n) {
		g[i][j] = max(g[i][j], (g[i][k] & g[k][j]));
	}
	
	iota(par, par + n, 0);
	rep(k, 0, n) rep(i, k + 1, n) if (g[k][i] && g[i][k]) join(k, i);
	
	rep(k, 0, n) rep(i, 0, n) if (g[k][i] && !g[i][k]) {
		g2[rt(k)][rt(i)] = 1;
	}
	
	toposort();
	
	solve();
}