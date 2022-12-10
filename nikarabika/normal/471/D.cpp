#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 10;
int n, m;
int a[maxn], b[maxn];
int da[maxn], db[maxn];
int next[maxn], ans;

int main(){
	cin >> n >> m;
	cin >> a[0];
	for(int i = 1; i < n; i++){
		cin >> a[i];
		da[i - 1] = a[i] - a[i - 1];
	}
	cin >> b[0];
	for(int i = 1; i < m; i++){
		cin >> b[i];
		db[i - 1] = b[i] - b[i - 1];
	}
	if(m == 1){
		cout << n << endl;
		return 0;
	}
	if(m > n){
		cout << 0 << endl;
		return 0;
	}
	n --;
	m --;
	//KMP!
	int match = 0;
	for(int i = 1; i < m; i++){
		while(match and db[i] != db[match])
			match = next[match - 1];
		if(db[i] == db[match])
			match ++;
		next[i] = match;
	}
	match = 0;
	for(int i = 0; i < n; i++){
		while(match and da[i] != db[match])
			match = next[match - 1];
		if(da[i] == db[match])
			match++;
		if(match == m){
			ans ++;
			match = next[match - 1];
		}
	}
	cout << ans << endl;
	return 0;
}