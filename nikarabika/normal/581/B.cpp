#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;
	int a[n], ans[n];
	for(int i = 0; i < n; i++)
		cin >> a[i];
	int max_floor = 0;
	for(int i = n - 1; i >= 0; i--){
		ans[i] = max(0, max_floor - a[i] + 1);
		max_floor = max(max_floor, a[i]);
	}
	for(int i = 0; i < n; i++)
		cout << ans[i] << ' ';
	cout << endl;
	return 0;
}