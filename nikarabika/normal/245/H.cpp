#include <bits/stdc++.h>

using namespace std;

const int maxn = 5e3 + 1;
int a[maxn][maxn];
string s;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> s;
	for(int i = 0; i < s.size(); i++){
		int p = i, q = i;
		while(p >= 0 and q < s.size() and s[p] == s[q])
			a[p--][q++] = true;
	}
	for(int i = 0; i < s.size(); i++){
		int p = i, q = i + 1;
		while(p >= 0 and q < s.size() and s[p] == s[q])
			a[p--][q++] = true;
	}
	for(int i = s.size() - 2; i >= 0; i--){
		int t = a[i][i];
		for(int j = i + 1; j < s.size(); j++){
			a[i][j] += t;
			t = a[i][j];
			a[i][j] += a[i + 1][j];
		}
	}
	int q;
	cin >> q;
	while(q--){
		int fi, se;
		cin >> fi >> se;
		cout << a[fi - 1][se - 1] << '\n';
	}
	return 0;
}