//sobskdrbhvk
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define sz(x) ((int)(x).size())
#define smax(x, y) ((x) = max((x), (y)))
#define smin(x, y) ((x) = min((x), (y)))
#define all(x) x.begin(),x.end()

int ans[1000][1000];

int C(int n, int r){
	int ret = 1;
	for(int i = 0; i < r; i++)
		ret = ret * (n - i) / (i + 1);
	return ret;
}

int get_max(int val, int r){
	int ret = 0;
	while(C(ret + 1, r) <= val) ret++;
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int k;
	cin >> k;
	int x = get_max(k, 3);
	int n = x;
	k -= x * (x - 1) * (x - 2) / 6;
	for(int i = 0; i < x; i++)
		for(int j = 0; j < x; j++)
			ans[i][j] = i != j;
	while(k > 0){
		int y = get_max(k, 2);
		k -= y * (y - 1) / 2;
		for(int i = x - 1; i >= x - y; i--)
			ans[i][n] = ans[n][i] = true;
		n++;
	}
	cout << n << '\n';
	for(int i = 0; i < n; i++, cout << '\n')
		for(int j = 0; j < n; j++)
			cout << ans[i][j];
	return 0;
}