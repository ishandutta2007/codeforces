#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll ;
typedef double db;
typedef pair<ll, ll> pii;
 
#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int M = (int)1e6 + 9;
const int N = (int)1e5 + 2;
vector<pii> T[N];

ll amount[N];
ll required[N];

ll dist[N];

struct Node{
	ll cookies;
	ll req_time;
};

Node Tree[M * 4];

void upd(int id, ll add){
	ll tim = add * 1ll * id;
	id += M;
	Tree[id].cookies += add;
	Tree[id].req_time += tim;
	id /= 2;
	while(id > 0){
		Tree[id].cookies = Tree[id * 2].cookies + Tree[id * 2 + 1].cookies;
		Tree[id].req_time = Tree[id * 2].req_time + Tree[id * 2 + 1].req_time;
		id /= 2;
	}
}

Node Query(int l, int r){
	ll total_time = 0;
	ll cookies_eaten = 0;
	l += M;
	r += M;
	while(l <= r){
		if(l % 2 == 1){
			total_time += Tree[l].req_time;
			cookies_eaten += Tree[l].cookies;
			l ++ ;
		}
		if(r % 2 == 0){
			total_time += Tree[r].req_time;
			cookies_eaten += Tree[r].cookies;
			r -- ;
		}
		l /= 2;
		r /= 2;
	}
	return {cookies_eaten, total_time};
}

void init(){
	for(int i = 0 ;i < M * 4; i ++ ){
		Tree[i].cookies = 0;
		Tree[i].req_time = 0;
	}
}

void dfs1(int u){
	for(auto x : T[u]){
		dist[x.fi] = dist[u] + x.se;
		dfs1(x.fi);
	}
}

ll f[N];

ll Tr;
ll Tim;


void dfs2(int u){
	upd(required[u], amount[u]);
	Tr = Tim - dist[u] * 2;
	if(Tr >= 0){
	int lf = 0, rf = M, mid; // eat completely 
	while(rf - lf > 1){
		mid = (lf + rf) / 2;
		if(Query(0, mid).req_time <= Tr)
			lf = mid;
		else
			rf = mid;
	}
	Node rez = Query(0, lf);
	Tr -= rez.req_time;
	f[u] += rez.cookies;
	if(lf + 1 < M){
		f[u] += Tr / (lf + 1);
	}
	}
	for(auto x : T[u]){
		dfs2(x.fi);
	}
	upd(required[u], -amount[u]);
}

ll answ = 0;

ll mx[N];

ll dfs3(int u){
	if(u == 1){
		mx[u] = f[u];
		for(auto x : T[u])
			mx[u] = max(mx[u], dfs3(x.fi));
		return mx[u];
	}
	ll v1 = 0, v2 = 0;
	ll ret;
	for(auto x : T[u]){
		ret = dfs3(x.fi);
		if(ret >= v1){
			v2 = v1;
			v1 = ret;
		}
		else if(ret > v2){
			v2 = ret;
		}
	}
	return max(f[u], v2);
}

int main(){
	fastIO;
	init();
	int n;
	cin >> n >> Tim;
	for(int i = 1; i <= n; i ++ )
		cin >> amount[i];
	for(int i = 1; i <= n; i ++ ){
		cin >> required[i];
	}
	int p, w;
	for(int i = 2; i <= n; i ++ ){
		cin >> p >> w;
		T[p].push_back(mp(i, w));
	}
	dfs1(1);
	dfs2(1);
	cout << dfs3(1);
	return 0;
}