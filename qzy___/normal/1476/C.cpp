#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 100010;

int T , n;
int a[N] , b[N] , c[N];

signed main() {
	ios::sync_with_stdio(false);
	cin >> T;
	while(T--) {
		cin >> n;
		for(int i = 1; i <= n; i++)
			cin >> c[i];
		int sum = 0 , ans = 0;
		for(int i = 1; i <= n; i++)
			cin >> a[i];
		for(int i = 1; i <= n; i++)
			cin >> b[i];
		sum = abs(b[2] - a[2]) + 2 , ans = sum + c[2] - 1;
		for(int i = 3; i <= n; i++) {
			if(a[i] > b[i])
				swap(a[i] , b[i]);
			if(a[i] == b[i])
				sum = 2;
			else
			{
				sum += c[i - 1] - b[i] + a[i] + 1;
				sum = max(abs(b[i] - a[i]) + 2 , sum);
			}
			ans = max(ans , sum + c[i] - 1);
		}
		cout << ans << endl;
	}
	return 0;
}