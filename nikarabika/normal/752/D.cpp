//sobskdrbhvk
//remember the flying, the bird dies ):(
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
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

const int maxn = 1e5 + 85 - 69,
	  maxsz = 2e5 + 85 + 69;
int go[maxsz][26];
vector<int> vec[maxsz];
bool mark[maxn],
	 pali[maxn];
int a[maxn],
	n, k, sz = 2;
string s[maxn],
	   t[maxn];

bool cmp(int i, int j){
	return a[i] > a[j];
}

LL dfs(int u = 0, int v = 1){
	if(u == -1 or v == -1)
		return 0;
	LL ret = 0;
	for(int i = 0; i < 26; i++)
		ret += dfs(go[u][i], go[v][i]);
	if(sz(vec[u]) and sz(vec[v]) and !mark[vec[u][0]] and !pali[vec[u][0]]){
		for(auto id : vec[u])
			mark[id] = true;
		for(auto id : vec[v])
			mark[id] = true;
		for(int i = 0; i < sz(vec[v]) and i < sz(vec[u]); i++)
			ret += max(0, a[vec[u][i]] + a[vec[v][i]]);
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	memset(go, -1, sizeof go);
	cin >> n >> k;
	for(int i = 0; i < n; i++)
		cin >> s[i] >> a[i];
	for(int i = 0; i < n; i++){
		t[i] = s[i];
		reverse(all(t[i]));
		pali[i] = (s[i] == t[i]);
	}
	for(int i = 0; i < n; i++){
		int u = 0;
		for(auto c : s[i]){
			int &v = go[u][c - 'a'];
			if(v == -1)
				v = sz++;
			u = v;
		}
		vec[u].PB(i);
		u = 1;
		for(auto c : t[i]){
			int &v = go[u][c - 'a'];
			if(v == -1)
				v = sz++;
			u = v;
		}
		vec[u].PB(i);
	}
	for(int i = 0; i < maxsz; i++)
		sort(all(vec[i]), cmp);
	LL ans = dfs();
	LL evesum = 0;
	LL maxodd = 0;
	for(int i = 0; i < maxsz; i++) if(sz(vec[i]) and !mark[vec[i][0]] and pali[vec[i][0]]){
		for(auto id : vec[i])
			mark[id] = true;
		LL cur = 0;
		for(int j = 0; j + 1 < sz(vec[i]); j+=2){
			LL curcur = a[vec[i][j]] + a[vec[i][j + 1]];
			if(curcur > 0) cur += curcur;
		}
		evesum += cur;
		cur = a[vec[i][0]] - cur;
		for(int j = 1; j + 1 < sz(vec[i]); j+=2){
			LL curcur = a[vec[i][j]] + a[vec[i][j + 1]];
			if(curcur > 0) cur += curcur;
		}
		smax(maxodd, cur);
	}
	cout << ans + evesum + maxodd << endl;
	return 0;
}