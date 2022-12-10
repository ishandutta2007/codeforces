//sobskdrbhvk
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
#define next nxt
#define stime statime
#define ftime fintime

const int maxn = 1e6 + 85 - 69;
int next[maxn],
	stime[maxn],
	ftime[maxn],
	su[maxn],
	n, k, tim;
string s;
vector<int> adj[maxn];

bool check(int l, int r){
	return stime[r + 1] >= stime[r - l + 1]
		and stime[r + 1] < ftime[r - l + 1];
}

bool kperiod(int lena, int lenb){
	if(lena == 0) return true;
	return check(lena - lenb, lena - 1)
		and kperiod(lena - lenb, lenb);
}

void dfs(int u){
	stime[u] = tim++;
	for(auto v : adj[u])
		dfs(v);
	ftime[u] = tim;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k
		>> s;
	int match = 0;
	for(int i = 1; i < n; i++){
		while(match > 0 and s[i] != s[match])
			match = next[match];
		match += s[i] == s[match];
		next[i + 1] = match;
	}
	for(int i = 1; i <= n; i++)
		adj[next[i]].PB(i);
	dfs(0);
	for(int len = 1; len * k <= n; len++) if(kperiod(len * k, len)){
		int lo = len * k - 1,
			hi = min(n, len * (k + 1));
		while(hi - lo > 1){
			int mid = (lo + hi) >> 1;
			if(check(len * k, mid))
				lo = mid;
			else
				hi = mid;
		}
		su[len * k - 1]++;
		su[hi]--;
	}
	for(int i = 1; i <= n; i++)
		su[i] += su[i - 1];
	for(int i = 0; i < n; i++)
		cout << bool(su[i]);
	cout << '\n';
	return 0;
}