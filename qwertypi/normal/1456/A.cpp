#include <bits/stdc++.h>

#define int long long
using namespace std;

vector<pair<int, int>> A;

int cnt[200020];
void sub(){
	int n, p, k;
	cin >> n >> p >> k;
	fill(cnt, cnt + 2 * n + 10, 0);
	string s;
	cin >> s;
	int x, y;
	cin >> x >> y;
	int ans = (1LL << 60);
	for(int i = n - 1; i >= 0; i--){
		cnt[i] = cnt[i + k] + (s[i] == '0');
		if(n - i >= p){
			ans = min(ans, x * (cnt[i + p - 1]) + y * i);
		}
	}
	cout << ans << endl;
}

int32_t main(){
	int t;
	cin >> t;
	while(t--){
		sub();
	}
}