#include <bits/stdc++.h>

using namespace std;

int p[100001];
bool ok[100001];
int n, m;
int id(int i, int j){
	return i * m + j;
}

bool test(int v){
	for(int i = 0; i < n * m; i++) ok[i] = p[i] >= v;
	for(int i = 0; i < n; i++){
		bool ex = false;
		for(int j = 0; j < m; j++){
			ex |= ok[id(i, j)];
		}
		if(!ex) return false;
	}
	for(int j = 0; j < m; j++){
		int cnt = 0;
		for(int i = 0; i < n; i++){
			if(ok[id(i, j)]) cnt++;
		}
		if(cnt >= 2) return true;
	}
	return false;
}

void solve(){
	cin >> m >> n;
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			cin >> p[id(j, i)];
		}
	}
	
	int l = 0, r = 1e9 + 1;
	while(l != r){
		int mid = (l + r + 1) / 2;
		if(test(mid)){
			l = mid;
		}else{
			r = mid - 1;
		}
	}
	cout << l << endl;
}

int main(){
	int t = 1;
	cin >> t;
	while(t--){
		solve();
	}
}