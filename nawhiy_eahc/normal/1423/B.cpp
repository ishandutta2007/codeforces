#include <bits/stdc++.h>
#define x first
#define y second
#define pb push_back
#define all(v) v.begin(),v.end()
#pragma gcc optimize("O3")
#pragma gcc optimize("Ofast") 
#pragma gcc optimize("unroll-loops")
using namespace std;
const int INF = 1e9;
const int TMX = 1 << 18;
const long long llINF = 1e18;
const long long mod = 11092019;
const long long hashmod = 100003;
const int MAXN = 20000;
const int MAXM = 4000000;
typedef long long ll;
typedef long double ld;
typedef pair <int,int> pi;
typedef pair <ll,ll> pl;
typedef vector <int> vec;
typedef vector <pi> vecpi;
typedef long long ll;
int n,m,c2[10005],g[10005];
int dep[20005];
vec v[20005];
bool c[10005];

struct Edge {
	int x,y,w;
}q[100005];


bool cmp(Edge x,Edge y) {return x.w < y.w;}

bool dfs(int x) {
	c[x] = 1;
	for(int i : v[x]) {
		if(!c2[i]) {
			g[x] = i;
			c2[i] = x;
			return true;
		}
	}
	for(int i : v[x]) {
		if(!c[c2[i]]&&dfs(c2[i])) {
			g[x] = i;
			c2[i] = x;
			return true;
		}
	}
	return false;
}

bool isok() {
	int ret = 0;
	memset(c2,0,sizeof(c2));
	memset(g,0,sizeof(g));
	while(1) {
		memset(c,0,sizeof(c));
		int fl = 0;
		for(int j = 1;j <= n;j++) {
			if(!c2[g[j]]&&dfs(j)) {
				fl++;
			} 
		}
		if(!fl) break;
		ret += fl;
	}
	return (ret == n);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= m;i++) {
		cin >> q[i].x >> q[i].y >> q[i].w;
	}
	sort(q+1,q+m+1,cmp);
	int l = 1, r = m+1;
	while(l < r) {
		int mid = (l + r) >> 1;
		for(int i = 1;i <= n*2;i++) v[i].clear();
		for(int i = 1;i <= mid;i++) {
			v[q[i].x].pb(q[i].y);
		}
		if(isok()) r = mid;
		else l = mid+1;
	}
	if(l == m+1) cout << -1;
	else cout << q[l].w;
}