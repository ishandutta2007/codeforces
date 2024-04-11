#include<bits/stdc++.h>


#define pii pair<ll,ll>
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

const int maxn = 1e6 + 5;
int n, K, m;

#define piii pair<pii, pii> 
piii arr[maxn];

vector<int> ins[maxn], rem[maxn];


struct BIT {
	ll bit[maxn];

	void upd(int pos, ll v) {
		for (++pos; pos < maxn; pos+= pos & - pos) 
			bit[pos] += v;
	}

	ll query(int pos) {
		ll ans = 0;
		for (++pos; pos > 0; pos-= pos & -pos) 
			ans += bit[pos];
		return ans;
	}

	int bit_search(ll v) {
		ll sum = 0;
		int pos = 0;
		for (int i = 20; i >=0; i--) {
			if (pos + (1<<i) < maxn && sum + bit[pos + (1 << i)] < v) {
				sum += bit[pos + (1 << i)];
				pos += (1<<i);
			}
		}
		
		return pos + 1;
	}
} core, cost;

int main() {
	cin >> n >> K >> m;
	
	rep(k, 0, m) {
		int l, r, c, p;
		cin >> l >> r >> c >> p;
		arr[k] = {{p, c}, {l, r}};
	}
	sort (arr, arr + m);
	
	rep(k, 0, m) {
		int l = arr[k].se.fi;
		int r = arr[k].se.se;
		ins[l].pb(k);
		rem[r + 1].pb(k);
	}
	
	ll ans = 0;
	rep(k, 1, n + 1) {
		for (auto x : ins[k]) {
			core.upd(x, arr[x].fi.se);
			cost.upd(x, (ll) arr[x].fi.fi*arr[x].fi.se);
		}
		for (auto x : rem[k]) {
			core.upd(x, -arr[x].fi.se);
			cost.upd(x, (ll) -arr[x].fi.fi*arr[x].fi.se);
		}
		
		int x = core.bit_search(K);
		if (x == maxn) {
			ans += cost.query(x - 1);
		}
		else {
			ans += cost.query(x - 1);
			ans += (ll) arr[x - 1].fi.fi * (K - core.query(x - 1));
		}
	}
	
	cout << ans << endl;
}