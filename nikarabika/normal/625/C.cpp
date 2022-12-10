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

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	int num = 1;
	k--;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < k; j++)
			ans[i][j] = num++;
	for(int i = 0; i < n; i++)
		for(int j = k; j < n; j++)
			ans[i][j] = num++;
	int sum = 0;
	for(int i = 0; i < n; i++)
		sum += ans[i][k];
	cout << sum << '\n';
	for(int i = 0; i < n; i++, cout << '\n')
		for(int j = 0; j < n; j++)
			cout << ans[i][j] << ' ';
	return 0;
}