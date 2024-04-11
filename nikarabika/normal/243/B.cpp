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

const int maxn = 1e5 + 85 - 69;
vector<int> adj[maxn],
	vec;
int n, m, h, t;
bool mark[maxn];

void print_ans1(int u, int v){
	cout << "YES\n"
		 << u+1 << ' ' << v+1 << '\n';
	mark[u] = mark[v] = true;
	for(int i = 0; i < h; i++)
		if(!mark[adj[u][i]]){
			cout << adj[u][i]+1 << ' ';
			mark[adj[u][i]] = true;
		}
		else h++;
	cout << '\n';
	for(int i = 0; i < t; i++)
		if(!mark[adj[v][i]]){
			cout << adj[v][i]+1 << ' ';
			mark[adj[v][i]] = true;
		}
		else t++;
	cout << '\n';
	exit(0);
}

void print_ans2(int u, int v){
	cout << "YES\n"
		 << u+1 << ' ' << v+1 << '\n';
	mark[u] = mark[v] = true;
	for(int i = 0; i < t; i++)
		if(!mark[adj[v][i]])
			mark[adj[v][i]] = true;
		else t++;
	for(int i = 0; i < h; i++)
		if(!mark[adj[u][i]])
			cout << adj[u][i]+1 << ' ';
		else h++;
	cout << '\n';
	for(int i = 0; i < n; i++)
		if(i != v and i != u and mark[i])
			cout << i + 1 << ' ';
	cout << '\n';
	exit(0);
}

void check(int u, int v, int cnt1, int cnt2, int esht){
	int rem1, rem2;
	esht -= (rem1 = max(0, h - cnt1));
	esht -= (rem2 = max(0, t - cnt2));
	if(esht < 0) return;
	cout << "YES\n"
		 << u+1 << ' ' << v+1 << '\n';
	mark[v] = mark[u] = true;
	for(auto w : vec) mark[w] = true;
	for(int i = 0; i < min(h, cnt1); i++)
		if(!mark[adj[u][i]]){
			cout << adj[u][i]+1 << ' ';
			mark[adj[u][i]] = true;
		}
		else cnt1++, h++;
	for(int i = 0; i < rem1; i++)
		cout << vec.back()+1 << ' ', vec.pop_back();
	cout << '\n';
	for(int i = 0; i < min(t, cnt2); i++)
		if(!mark[adj[v][i]])
			cout << adj[v][i]+1 << ' ';
		else cnt2++, t++;
	for(int i = 0; i < rem2; i++)
		cout << vec.back()+1 << ' ', vec.pop_back();
	cout << '\n';
	exit(0);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> h >> t;
	for(int i = 0; i < m; i++){
		int fi, se;
		cin >> fi >> se;
		fi--, se--;
		adj[fi].PB(se);
		adj[se].PB(fi);
	}
	for(int i = 0; i < n; i++)
		sort(all(adj[i]));
	for(int u = 0; u < n; u++){
		for(auto v : adj[u]){
			if(max(sz(adj[v]), sz(adj[u])) >= 201){
				bool sw = false;
				if(sz(adj[u]) > sz(adj[v]))
					sw = true,swap(v, u);
				if(sz(adj[u]) > h) print_ans1(u, v);
				else if(sz(adj[u]) > t) print_ans2(v, u);
				if(sw) swap(v, u);
				continue;
			}
			vec.clear();
			int ptr = 0;
			for(int i = 0; i < sz(adj[u]); i++){
				while(ptr < sz(adj[v]) and adj[v][ptr] < adj[u][i])
					ptr++;
				if(ptr < sz(adj[v]) and adj[v][ptr] == adj[u][i])
					vec.PB(adj[u][i]);
			}
			int cnt1 = sz(adj[u]) - sz(vec) - 1,
				cnt2 = sz(adj[v]) - sz(vec) - 1,
				esht = sz(vec);
			check(u, v, cnt1, cnt2, esht);
			check(v, u, cnt2, cnt1, esht);
		}
	}
	cout << "NO" << endl;
	return 0;
}