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

const int maxn = 3e5 + 85 - 69;
string str[maxn], s;
vector<int> adj[maxn];
int next[maxn],
	fail[maxn][26];
int ans, n;

void dfs(int v, int match = 0){
	for(auto u : adj[v]){
		int tmp = match;
		for(auto c : str[u]){
			tmp = fail[tmp][c - 'a'];
			tmp += c == s[tmp];
			if(tmp == sz(s)) ans++, tmp = next[tmp - 1];
		}
		dfs(u, tmp);
	}
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 1; i < n; i++){
		int fi;
		cin >> fi >> str[i], fi--;
		adj[fi].PB(i);
	}
	cin >> s;
	int match = 0;
	for(int i = 1; i < sz(s); i++){
		while(match and s[i] != s[match])
			match = next[match - 1];
		match += s[i] == s[match];
		next[i] = match;
	}
	for(int i = 1; i < sz(s); i++){
		for(int j = 0; j < 26; j++)
			if(s[i] == 'a' + j) fail[i][j] = i;
			else fail[i][j] = fail[next[i - 1]][j];
	}
	dfs(0);
	cout << ans << endl;
	return 0;
}