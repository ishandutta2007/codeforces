//sobskdrbhvk
//man HLD mizanam, age rah-e asoontar dasht maskharam nakonid :D
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

const int maxn = 100 * 1000,
	  maxl = 20;
bool mark[maxn],
	 incyc[maxn],
	 cycfound;
int	h[maxn],
	par[maxn],
	nxt[maxn],
	prv[maxn],
	where[maxn],
	pathcnt[maxn],
	pathid[maxn],
	pathroot[maxn],
	lastpathid,
	cycledge,
	treeedge,
	n, m;
vector<int> adj[maxn],
	seg[maxn];
vector<bool> laz[maxn];

void dfs1(int v, int p = -1){
	mark[v] = true;
	for(auto u : adj[v])
		if(u != p){
			nxt[v] = u;
			prv[u] = v;
			if(mark[u]){
				cycfound = true;
				//cout << "cycle verices: ";
				u = v;
				do{
					//cout << u << ' ';
					incyc[u] = true;
					where[u] = pathcnt[0]++;
					u = nxt[u];
				}while(u != v);
				//cout << endl;
			}
			else
				dfs1(u, v);
			if(cycfound)
				return;
		}
	return;
}

int dfs2(int v, int p = -1){
	par[v] = p;
	int adjcnt = 0, ret = 1, Max = -1, maxid = -1;
	for(auto u : adj[v])
		if(u != p and !incyc[u]){
			adjcnt++;
			int uval = dfs2(u, v);
			ret += uval;
			if(uval > Max)
				Max = uval, maxid = u;
		}
	if(par[v] == -1)
		goto hell;
	if(adjcnt) pathid[v] = pathid[maxid];
	else pathid[v] = lastpathid++;
	where[v] = pathcnt[pathid[v]]++;
	pathroot[pathid[v]] = v;
hell:
	return ret;
}

void push(int segid, int l, int r, int id);

void flip(int segid, int st, int en, int l, int r, int id = 0){
	if(st >= r or en <= l)
		return;
	if(st <= l and r <= en){
		seg[segid][id] = (r - l) - seg[segid][id];
		laz[segid][id] = !laz[segid][id];
		return;
	}
	if(laz[segid][id]) push(segid, l, r, id);
	int mid = (l + r) >> 1;
	flip(segid, st, en, l, mid, id * 2 + 1);
	flip(segid, st, en, mid, r, id * 2 + 2);
	seg[segid][id] = seg[segid][id * 2 + 1] + seg[segid][id * 2 + 2];
	return;
}

void push(int segid, int l, int r, int id){
	int mid = (l + r) >> 1;
	flip(segid, l, mid, l, mid, id * 2 + 1);
	flip(segid, mid, r, mid, r, id * 2 + 2);
	laz[segid][id] = 0;
	return;
}

int update_path(int v){
	while(~par[v]){
		//cout << v << endl;
		treeedge -= seg[pathid[v]][0];
		flip(pathid[v], where[v], pathcnt[pathid[v]], 0, pathcnt[pathid[v]]);
		treeedge += seg[pathid[v]][0];
		v = par[pathroot[pathid[v]]];
	}
	return v;
}

int dist(int v, int u){
	if(where[u] > where[v])
		return where[u] - where[v];
	return pathcnt[0] - (where[v] - where[u]);
}

void cycflip(int v, int u){
	if(where[v] < where[u])
		flip(0, where[v], where[u], 0, pathcnt[0]);
	else
		flip(0, where[u], pathcnt[0], 0, pathcnt[0]),
			flip(0, 0, where[v], 0, pathcnt[0]);
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		int fi, se;
		cin >> fi >> se;
		fi--, se--;
		adj[fi].PB(se);
		adj[se].PB(fi);
	}
	dfs1(0);
	//cout << "dfs1 done!" << endl;
	lastpathid = 1;
	for(int i = 0; i < n; i++)
		if(incyc[i])
			dfs2(i);
	//cout << "dfs2 done!" << endl;
	for(int i = 0; i < lastpathid; i++){
		seg[i].resize(pathcnt[i] * 4);
		laz[i].resize(pathcnt[i] * 4);
	}
	//cout << "segment resizing done!" << endl;
	for(int q = 0; q < m; q++){
		int fi, se;
		//cout << "Reading query " << q << endl;
		cin >> fi >> se, fi--, se--;
		//cout << "Query #" << q << " Read!" << endl;
		fi = update_path(fi);
		//cout << "path_update1 done" << endl;
		se = update_path(se);
		//cout << "path_update2 done" << endl;
		if(fi != se){
			cycledge -= seg[0][0];
			if(dist(fi, se) < dist(se, fi))
				cycflip(fi, se);
			else if(dist(fi, se) > dist(se, fi))
				cycflip(se, fi);
			else if(prv[fi] < nxt[fi])
				cycflip(se, fi);
			else
				cycflip(fi, se);
			cycledge += seg[0][0];
		}
		//cout << "cycle updating done" << endl;
		//cout << "TREE: " << treeedge << " & CYCLE: " << cycledge << endl;
		cout << n - treeedge - min(pathcnt[0] - 1, cycledge) << '\n';
	}
	return 0;
}