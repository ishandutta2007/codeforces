#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;
	cout << 3 * n + 4 << endl;
	for(int i = 0; i <= n; i++){
		cout << 1 + i << ' ' << 0 + i << endl;
		cout << 0 + i << ' ' << 1 + i << endl;
		cout << 0 + i << ' ' << 0 + i << endl;
	}
	cout << 1 + n << ' ' << 1 + n << endl;
}