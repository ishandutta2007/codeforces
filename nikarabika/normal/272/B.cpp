#include <bits/stdc++.h>

using namespace std;

#define BP __builtin_popcount

int cnt[40], n;
long long int ans;

int main(){
	cin >> n;
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		ans += (cnt[BP(x)]++);
	}
	cout << ans << endl;
}