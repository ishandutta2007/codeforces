#include <bits/stdc++.h>

using namespace std;

char f[20][20];
void sub(){
	int x, y;
	cin >> x >> y;
	for(int i = 0; i < x; i++){
		for(int j = 0; j < y; j++){
			f[i][j] = '0';
		}
	}
	for(int i = 0; i < x; i++){
		f[i][0] = '0' + (i + 1) % 2;
		f[i][y - 1] = '0' + (i + 1) % 2;
	}
	for(int j = 2; j < y - 2; j++){
		f[0][j] = '0' + (j + 1) % 2;
		f[x - 1][j] = '0' + (j + 1) % 2;
	}
	for(int i = 0; i < x; i++){
		for(int j = 0; j < y; j++){
			cout << f[i][j];
		}
		cout << endl;
	}
}
int32_t main(){
	int t;
	cin >> t;
	while(t--){
		sub();
	}
	return 0;
}