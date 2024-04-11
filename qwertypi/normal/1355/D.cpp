#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
	int n, s;
	cin >> n >> s;
	if(s >= 2 * n){
		cout << "YES" << endl;
		for(int i = 0; i < n; i++){
			cout << (s / n + (i < s % n)) << ' ';
		}
		cout << endl;
		cout << 1 << endl;
		return 0;
	}
	cout << "NO" << endl;
}