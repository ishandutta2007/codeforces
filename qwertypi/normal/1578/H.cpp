#include <bits/stdc++.h>

using namespace std;

int id(int v, char c){
	if(c == 'c'){
		return v * 2;
	}else if(c == 'i'){
		return v * 2 + 1;
	}
}

int p[400001], sz[400001];
void init(int n){
	for(int i = 0; i <= n; i++){
		p[i] = i;
		sz[i] = 1;
	}
}

int root(int x){
	if(p[x] == x) return x;
	return p[x] = root(p[x]);
}

bool join(int u, int v){
	int x = root(u), y = root(v);
	if(x == y) return false;
	if(sz[x] < sz[y]) swap(x, y);
	sz[x] += sz[y];
	p[y] = x;
	return true; 
}

void solve(){
	int n, m;
	cin >> n >> m;
	init(n * 2);
	for(int i = 0; i < m; i++){
		int x, y; string c;
		cin >> x >> y >> c;
		x--; y--;
		if(c == "crewmate"){
			join(id(x, 'c'), id(y, 'c'));
			join(id(x, 'i'), id(y, 'i'));
		}else{
			join(id(x, 'c'), id(y, 'i'));
			join(id(x, 'i'), id(y, 'c'));
		}
	}
	for(int i = 0; i < n; i++){
		if(root(id(i, 'i')) == root(id(i, 'c'))){
			cout << -1 << endl;
			return;
		}
	}
	map<int, int> cnt;
	for(int i = 0; i < n; i++){
		cnt[root(id(i, 'i'))]++;
		cnt[root(id(i, 'c'))]--;
	}
	int ans = 0;
	for(auto i : cnt){
		ans += abs(i.second);
	}
	cout << (n + ans / 2) / 2 << endl;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}