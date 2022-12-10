#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	while(k--){
		cout << 2 * n - 1 << ' ' << 2 * n << ' ';
		n--;
	}
	while(n--)
		cout << 2 * n + 2 << ' ' << 2 * n + 1 << ' ';
	cout << endl;
	return 0;
}