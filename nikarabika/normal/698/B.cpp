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

const int maxn = 2e5;
int a[maxn],
	n;
int mark[maxn];
vector<int> vec, root;

void dfs(int v){
	mark[v] = 1;
	if(a[v] == v){
		mark[v] = 2;
		return;
	}
	if(mark[a[v]] == 2){
		mark[v] = 2;
		return;
	}
	if(mark[a[v]] == 1){
		mark[v] = 2;
		vec.PB(v);
		return;
	}
	if(mark[a[v]] == 0)
		dfs(a[v]);
	mark[v] = 2;
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i], a[i]--;
		if(a[i] == i){
			if(sz(root))
				a[i] = root[0];
			root.PB(i);
		}
	}
	for(int i = 0; i < n; i++)
		if(!mark[i])
			dfs(i);
	if(sz(root)){
		for(auto v : vec)
			a[v] = root[0];
		cout << sz(vec) + sz(root) - 1 << '\n';
		for(int i = 0; i < n; i++)
			cout << a[i] + 1 << ' ';
		cout << '\n';
	}
	else{
		cout << sz(vec) << '\n';
		for(auto v : vec)
			a[v] = vec[0];
		for(int i = 0; i < n; i++)
			cout << a[i] + 1 << ' ';
		cout << '\n';
	}
	return 0;
}