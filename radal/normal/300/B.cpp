#include <bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define X first
#define Y second
#define debug(x) cerr << #x << ": " << x << endl;
#define ll long long int
#define endl '\n'
#define mp make_pair
#define pb push_back
#define rep(i,l,r) for (ll i=l; i<r; i++)
#define repr(i,r,l) for (int i=r; i>=l; i--)
using namespace std;
const long long int N=5e1+30,inf = 1e18;
int visited[N],cnt[N];
vector <int> adj[N],team[N];
bool f=0;
void dfs(int v,int t){
	visited[v] = t;
	int s = adj[v].size();
	for (int u : adj[v]){
		if (!visited[u]){
			dfs(u,t);
		}
	}
}
int main(){
	int n,m;
	cin >> n >> m;
	rep(i,0,m){
		int x,y;
		cin >> x >> y;
		adj[x].pb(y);
		adj[y].pb(x);
	}
	int t = 0;
	rep(i,1,n+1){
		if (!visited[i]){
			t++;
			dfs(i,t);
		}
		cnt[visited[i]]++;
		team[visited[i]].pb(i);
	}
	sort(cnt,cnt+t+1);
	if (cnt[t] > 3){
		cout << -1 << endl;
		return 0;
	}
	int p1=0;
	stack <int> st1,st2,st3;
	rep(i,1,t+1){
		if (team[i].size() == 1) st1.push(i);
		if (team[i].size() == 2) st2.push(i);
		if (team[i].size() == 3) st3.push(i);
	}
	if (st1.size() < st2.size() || (st1.size()-st2.size())%3) {
		cout << -1 << endl;
		return 0;
	}
	while (!st3.empty()){
		int i = st3.top();
		cout << team[i][0] << ' ' << team[i][1] << ' ' << team[i][2] << endl;
		st3.pop();
	}
	while (!st2.empty()){
		int i = st2.top();
		int j = st1.top();
		cout << team[i][0] << ' ' << team[i][1] << ' ' << team[j][0] << endl;
		st2.pop();
		st1.pop();
	}
	while (!st1.empty()){
		int i = st1.top();
		st1.pop();
		int j = st1.top();
		st1.pop();
		int k = st1.top();
		
		cout << team[i][0] << ' ' << team[j][0] << ' ' << team[k][0] << endl;
		st1.pop();
	}
}