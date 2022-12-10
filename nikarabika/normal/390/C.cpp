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

int a[100000], sum[10][100000];
int n, k, w;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k >> w;
	for(int i = 0; i < n; i++){
		char c;
		cin >> c;
		a[i] = c - '0';
	}
	for(int i = 0; i < k; i++){
		sum[i][0] = (i == 0) * a[i];
		for(int j = 1; j < n; j++){
			if(j % k == i)
				sum[i][j] = sum[i][j - 1] + a[j];
			else
				sum[i][j] = sum[i][j - 1];
		}
	}
	while(w--){
		int fi, se;
		cin >> fi >> se;
		fi--, se--;
		int ans = 0;
		for(int i = 0; i < k; i++)
			if(i != (fi + k - 1) % k)
				ans += sum[i][se] - (fi == 0 ? 0 : sum[i][fi - 1]);
		int i = (fi + k - 1) % k;
		int cnt = (se - fi + 1) / k;
		ans += cnt - (sum[i][se] - (fi == 0 ? 0 : sum[i][fi - 1]));
		cout << ans << '\n';
	}
	return 0;
}