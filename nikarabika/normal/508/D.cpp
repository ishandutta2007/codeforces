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

const int maxn = 2e5 + 85 - 69;
int in[maxn],
	out[maxn],
	frm[maxn],
	too[maxn],
	n, m;
vector<int> adj[maxn],
	tour;
bool mark[maxn];

void add_edge(int u, int v){
	frm[m] = u, too[m] = v;
	adj[u].PB(m);
	out[u]++, in[v]++, m++;
	return;
}

void dfs(int u){
	while(sz(adj[u])){
		int e = adj[u].back();
		adj[u].pop_back();
		if(mark[e]) continue;
		mark[e] = true;
		dfs(too[e]);
	}
	tour.PB(u);
}

int mp(char c){
	if(c >= 'a' and c <= 'z')
		return c - 'a';
	if(c >= 'A' and c <= 'Z')
		return 26 + c - 'A';
	return c - '0' + 52;
}

int pm(int x){
	if(x < 26) return x + 'a';
	x -= 26;
	if(x < 26) return x + 'A';
	x -= 26;
	return x + '0';
}

int func(char *s){
	return mp(s[0]) * 62 + mp(s[1]);
}

string cnuf(int x){
	string s = "  ";
	s[0] = pm(x / 62);
	s[1] = pm(x % 62);
	return s;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	int beg = -1;
	for(int i = 0; i < n; i++){
		char s[4];
		cin >> s;
		add_edge((beg=func(s + 0)), func(s + 1));
	}
	int cnt = 0;
	for(int i = 0; i < maxn; i++)
		if(out[i] > in[i]){
			if(out[i] > in[i] + 1 or cnt){
				cout << "NO" << endl;
				return 0;
			}
			beg = i;
			cnt++;
		}
	dfs(beg);
	if(sz(tour) != n + 1){
		cout << "NO" << endl;
		return 0;
	}
	reverse(all(tour));
	string ans;
	ans += cnuf(tour[0])[0];
	for(int i = 0; i < sz(tour); i++)
		ans += cnuf(tour[i])[1];
	cout << "YES\n" << ans << '\n';
	return 0;
}