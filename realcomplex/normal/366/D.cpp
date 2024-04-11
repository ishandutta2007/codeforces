#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double db;

#define fi first
#define se second
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define all(x) ((x).begin(),(x).end())
#define len(x) ((ll)(x).size())
#define mp make_pair

struct Edge{
	int u;
	int v;
	int l;
	int r;
	bool operator< (Edge B) const{
		if(l == B.l)
			return r < B.r;
		else
			return l < B.l;
	}
};

const int N = 1005;
int lnk[N];
int rnk[N];

void init(){
	for(int i = 0 ; i < N; i ++ ){
		lnk[i] = i;
		rnk[i] = 1;
	}
}

int fin(int u){
	if(lnk[u] == u)
		return u;
	return lnk[u] = fin(lnk[u]);
}

void merge(int u, int v){
	u = fin(u);
	v = fin(v);
	if(u == v)
		return;
	if(rnk[u] > rnk[v])
		swap(u, v);
	rnk[v] += rnk[u];
	lnk[u] = v;
}

int main(){
	fastIO;
	int n, m;
	cin >> n >> m;
	Edge s[m];
	for(int i = 0 ; i < m ; i ++ ){
		cin >> s[i].u >> s[i].v >> s[i].l >> s[i].r;
	}
	sort(s, s + m);
	vector<Edge> use;
	int cl, cr;
	bool ok;
	int ans = 0;
	for(int i = 0 ; i < m ; i ++ ){
		use.push_back({s[i].u, s[i].v, s[i].r, s[i].l});
		cl = s[i].l;
		cr = s[i].r;
		sort(use.begin(), use.end());
		reverse(use.begin(), use.end());
		init();
		ok = false;
		for(auto x : use){
			cl = max(cl, x.r);
			cr = min(cr, x.l);
			merge(x.u, x.v);
			if(fin(1) == fin(n)){
				ok = true;
				break;
			}
		}
		if(ok)
			ans = max(ans, cr - cl + 1);
	}
	if(ans == 0)
		cout << "Nice work, Dima!\n";
	else
		cout << ans << "\n";
	return 0;
}