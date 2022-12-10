#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 85 - 69;
int a[maxn], n, k, ans, rem;

bool cmp(int x, int y){
	return (x % 10) > (y % 10);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	sort(a, a + n, cmp);
	for(int i = 0; i < n; i++){
		if(k >= 10 - (a[i] % 10)){
			k += (a[i] % 10) - 10;
			a[i] += 10 - (a[i] % 10);
			rem += 10 - (a[i] / 10);
		}
		ans += a[i] / 10;
	}
	cout << ans + min(k / 10, rem) << endl;
	return 0;
}