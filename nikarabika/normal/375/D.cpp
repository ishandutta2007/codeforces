//sobskdrbhvk
//sevomin segment pointerim ro mizanam, ghorbatan elallah :-S
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef long double LD;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define sz(x) ((int)(x).size())
#define smax(x, y) ((x) = max((x), (y)))
#define smin(x, y) ((x) = min((x), (y)))
#define all(x) x.begin(),x.end()
#undef free
#undef index
#define free FrEe
#define index InDeX

const int maxn = 1e5 + 85 - 69,
	  maxseg = maxn * 17;
int lastseg, n;
vector<int> adj[maxn], free;

struct Node{
	int value, chL, chR;
	Node(){
		value = 0;
		chL = chR = -1;
		return;
	}
	int left(void){
		if(chL == -1){
			chL = free.back();
			free.pop_back();
		}
		return chL;
	}
	int right(void){
		if(chR == -1){
			chR = free.back();
			free.pop_back();
		}
		return chR;
	}
	void clear(void){
		if(chL != -1) free.PB(chL);
		if(chR != -1) free.PB(chR);
		value = 0;
		chL = chR = -1;
		return;
	}
} node[maxseg];

struct esmeto_chi_bezaram_akhe_man{
	int root;
	set<pii> st;

	esmeto_chi_bezaram_akhe_man(){
		return;
	}

	void clear(Node &v){
		if(v.chL != -1)
			clear(node[v.chL]);
		if(v.chR != -1)
			clear(node[v.chR]);
		v.clear();
		return;
	}

	void clear(void){
		st.clear();
		clear(node[root]);
		root = 0;
		return;
	}

	void add(int idx, int val, int l, int r, Node &v){
		v.value += val;
		if(r - l == 1)
			return;
		int mid = (l + r) >> 1;
		if(idx < mid){
			add(idx, val, l, mid, node[v.left()]);
			if(node[v.chL].value == 0){
				node[v.chL].clear();
				free.PB(v.chL);
				v.chL = -1;
			}
		}
		if(idx >= mid){
			add(idx, val, mid, r, node[v.right()]);
			if(node[v.chR].value == 0){
				node[v.chR].clear();
				free.PB(v.chR);
				v.chR = -1;
			}
		}
		return;
	}

	int get(int st, int en, int l, int r, Node &v){
		if(st <= l and r <= en)
			return v.value;
		int mid = (l + r) >> 1;
		int ret = 0;
		if(st < mid and v.chL != -1)
			ret += get(st, en, l, mid, node[v.left()]);
		if(en > mid and v.chR != -1)
			ret += get(st, en, mid, r, node[v.right()]);
		return ret;
	}

	void insert(int color, int cnt){
		auto it = st.lower_bound(MP(color, 0));
		if(it != st.end() and it->L == color){
			add(it->R, -1, 1, n + 1, node[root]);
			//cout << "add " << it->R << ' ' << -1 << endl;
			cnt += it->R;
			st.erase(it);
		}
		st.insert(MP(color, cnt));
		add(cnt, +1, 1, n + 1, node[root]);
		//cout << "add " << cnt << ' ' << "+1" << endl;
		return;
	}
} stru[maxn];

vector<pii> quer[maxn];
int col[maxn], index[maxn], ans[maxn];
int q;

void dfs(int v, int p = -1){
	if(p != -1 and sz(adj[v]) == 1){
		index[v] = lastseg++;
		stru[index[v]].root = free.back();
		free.pop_back();
		//cout << "Index " << v << ": " << index[v] << endl;
	}
	else{
		int w = adj[v][adj[v][0] == p];
		for(auto u : adj[v]) if(u != p){
			dfs(u, v);
			if(sz(stru[index[u]].st) > sz(stru[index[w]].st))
				w = u;
		}
		index[v] = index[w];
		//cout << "Index " << v << ": " << index[v] << endl;
		for(auto u : adj[v]) if(u != p and u != w){
			for(auto val : stru[index[u]].st){
				stru[index[v]].insert(val.L, val.R);
				//cout << "insert " << v << ": " << val.L << ' ' << val.R << endl;
			}
			stru[index[u]].clear();
		}
	}
	stru[index[v]].insert(col[v], 1);
	//cout << "inserts " << v << ": " << col[v] << ' ' << 1 << endl;
	for(auto Q : quer[v])
		ans[Q.R] = stru[index[v]].get(Q.L, n + 1, 1, n + 1, node[stru[index[v]].root]);
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	free.reserve(maxseg);
	for(int i = maxseg - 1; i >= 0; i--)
		free.PB(i);
	cin >> n >> q;
	for(int i = 0; i < n; i++)
		cin >> col[i];
	for(int i = 1; i < n; i++){
		int fi, se;
		cin >> fi >> se;
		fi--, se--;
		adj[fi].PB(se);
		adj[se].PB(fi);
	}
	for(int i = 0; i < q; i++){
		int qv, qk;
		cin >> qv >> qk;
		qv--;
		quer[qv].PB({qk, i});
	}
	dfs(0);
	for(int i = 0; i < q; i++)
		cout << ans[i] << '\n';
	return 0;
}