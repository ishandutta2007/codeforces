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

const int maxn = 1e5 + 10,
	  maxl = 20;
int a[maxn],
	spp[maxn],
	spt[maxn][maxl],
	n;
LL sum[maxn],
   ans;

int func(int i, int j){
	return max(MP(a[i], i), MP(a[j], j)).R;
}

int get_max(int l, int r){
	int an = spp[r - l + 1];
	return func(spt[l][an], spt[r - (1 << an) + 1][an]);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n - 1; i++)
		cin >> a[i], a[i]--, spt[i][0] = i;
	spt[n - 1][0] = a[n - 1] = n - 1;
	for(int j = 1; j < maxl; j++)
		for(int i = 0; i + (1 << j) <= n; i++)
			spt[i][j] = func(spt[i][j - 1], spt[i + (1 << (j - 1))][j - 1]);
	spp[0] = -1;
	for(int i = 1; i < maxn; i++)
		spp[i] = spp[i>>1] + 1;
	for(int i = n - 2; i >= 0; i--){
		int id = get_max(i + 1, a[i]);
		sum[i] = sum[id] + (n - 1 - a[i]) - (a[i] - id) + (a[i] - i);
	}
	LL ans = 0;
	for(int i = 0; i < n; i++)
		ans += sum[i];
	cout << ans << endl;
	return 0;
}