#include <bits/stdc++.h>

using namespace std;

int n, a[3050];

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n;
	int x = 0;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		for(int j = 1; j < i; j++)
			x += a[j] > a[i];
	}
	cout << 4 * (x / 2) + (x & 1) << ".000000" << endl;
	return 0;
}