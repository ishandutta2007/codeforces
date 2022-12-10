#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	int n, ans = 0;
	cin >> n;
	int a[n + n + 5];
	memset(a, 0, sizeof a);
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		a[x]++;
	}
	for(int i = 1; i <= n + n; i++){
		if(a[i] > 1){
			ans += a[i] - 1;
			a[i + 1] += a[i] - 1;
		}
	}
	cout << ans << endl;
	return 0;
}