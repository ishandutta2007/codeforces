#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 10;
int pd[maxn];
int n, a[maxn], ans;

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	a[0] = -(2e9);
	a[n + 1] = +(2e9);
	for(int i = n; i > 0; i--)
		pd[i] = 1 + (i < n and a[i] < a[i + 1]) * pd[i + 1];
	int x = 0;
	for(int i = 1; i <= n; i++){
		int f = 0;
		if(a[i - 1] < a[i + 1] - 1)
			f = x + pd[i + 1];
		else
			f = max(x, pd[i]);
		x = 1 + (a[i] > a[i - 1]) * x;
		ans = max(ans, f + 1);
	}
	cout << ans << endl;
	return 0;
}