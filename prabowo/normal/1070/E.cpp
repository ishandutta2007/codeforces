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

// clock_t first_attempt = clock();
// inline void cek_time(){
// 	clock_t cur = clock()- first_attempt;
// 	cerr<<"TIME : "<<(double) cur/CLOCKS_PER_SEC<<endl;
// }
// inline void OPEN (string s) {
// 	freopen ((s + ".in").c_str (), "r", stdin);
// 	freopen ((s + ".out").c_str (), "w", stdout);
// }

// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>

// using namespace __gnu_pbds;
// typedef tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update> bbst;
//find_by_order(idx) : i-th index 
//order_of_key(val)  : val has which index

//end of template

const int maxn = 2e5 + 5;
int tc;

int n, m;
ll T;

ll p[maxn];

int N;
struct BIT {
	ll bit[maxn];

	void upd(int pos, ll v) {
		for (++pos; pos < N; pos+= pos & - pos) 
			bit[pos] += v;
	}

	ll query(int pos) {
		ll ans = 0;
		for (++pos; pos > 0; pos-= pos & -pos) 
			ans += bit[pos];
		return ans;
	}

	int lower_bound(ll v) {
		ll sum = 0;
		int pos = 0;
		for (int i = 20; i >=0; i--) {
			if (pos + (1<<i) < N && sum + bit[pos + (1 << i)] < v) {
				sum += bit[pos + (1 << i)];
				pos += (1<<i);
			}
		}
		
		return pos + 1;
	}
	
	void clear() {
		rep(k, 0, N) bit[k] = 0;
	}
} cnt, val;

void fix() {
	while(true) {
		int sz = cnt.query(n);
		int L = sz / m * m;
		if (L == sz) L -= m;
		
		int i = cnt.lower_bound(L);
		if (L == 0) i--;
		ll vL = val.query(i - 1), vR = val.query(n) - vL;
		ll v = 2*vL + vR;
		
		if (v <= T) break;
		else {
			// delete right most
			i = cnt.lower_bound(sz) - 1;
			cnt.upd(i, -1);
			val.upd(i, -p[i]);
		}
	}
}

void insert(int x) {
	cnt.upd(x, 1);
	val.upd(x, p[x]);
	
	fix();
}

map<int, vi> swp;
void clear() {
	swp.clear();
	cnt.clear();
	val.clear();
}

int main() {
	cin >> tc;
	
	while(tc--) {
		cin >> n >> m >> T;
		rep(k, 0, n) scanf("%lld", &p[k]), swp[p[k]].pb(k);
		
		// resize bit
		N = n + 5;
		
		pii ans = {-1, 1};
		for (auto a : swp) {
			for (auto b : a.se) {
				insert(b);
				
				// rep(k, 0, N) printf("%lld ", cnt.query(k)); line;
			}
			// line;
			
			int d = a.fi;
			if (d > T) d = T;
			pii cur = {(int) cnt.query(n), d};
			// printf("cur %d %d\n", cur.fi, cur.se);
			ans = max(ans, cur);
		}
		printf("%d %d\n", ans.fi, ans.se);
		
		clear();
	}
}