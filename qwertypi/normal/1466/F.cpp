#include <bits/stdc++.h>

#define int long long
using namespace std;

int mod = 1e9 + 7;

int par[500001];
bool det[500001];

int root(int x){
	if(x == par[x]) return x;
	return par[x] = root(par[x]);
}

int powmod(int a, int b){
	int res = 1;
	while(b){
		if(b % 2){
			res = (res * a) % mod;
		}
		
		b /= 2;
		a = (a * a) % mod;
	}
	return res;
}

int cnt = 0;
bool join(int x, int y){
	x = root(x), y = root(y);
	if(x == y) return false;
	par[y] = x;
	
	if(!(det[x] && det[y])){
		cnt++;
	}else{
		return false;
	}
	
	if(det[x] || det[y]){
		det[x] = true;
	}
	
	return true;
}

bool join(int x){
	x = root(x);
	if(det[x]){
		return false;
	}else{
		det[x] = true;
		cnt++;
		return true;
	}
}

int ans[500001], c = 0;
int32_t main(){
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);
	int n, m, x, y;
	cin >> n >> m;
	for(int i = 1; i <= m; i++){
		par[i] = i;
		det[i] = false;
	}
	for(int i = 0; i < n; i++){
		int k;
		cin >> k;
		if(k == 1){
			cin >> x;
			if(join(x)){
				ans[c++] = i + 1;
			}
		}else{
			cin >> x >> y;
			if(join(x, y)){
				ans[c++] = i + 1;
			}
		}
	}
	
	cout << powmod(2, cnt) << ' ' << cnt << endl;
	for(int i = 0; i < cnt; i++){
		cout << ans[i] << ' ';
	}
	cout << endl;
}