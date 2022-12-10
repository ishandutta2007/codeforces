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

const int maxn = 5e5 + 85 - 69;
int a[maxn],
	b[maxn],
	cnt[2][maxn];
int n, m, k;
vector<int> all;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> k;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		all.PB(a[i]);
	}
	for(int i = 0; i < m; i++){
		cin >> b[i];
		all.PB(b[i]);
	}
	all.PB(0);
	sort(all(all));
	all.resize(unique(all(all)) - all.begin());
	for(int i = 0; i < n; i++){
		a[i] = lower_bound(all(all), a[i]) - all.begin();
		cnt[0][a[i]]++;
	}
	for(int i = 0; i < m; i++){
		b[i] = lower_bound(all(all), b[i]) - all.begin();
		cnt[1][b[i]]++;
	}
	for(int i = sz(all) - 1; i >= 0; i--){
		for(int j = 0; j < 2; j++)
			cnt[j][i] += cnt[j][i + 1];
		if(cnt[0][i] > cnt[1][i]){
			cout << "YES" << endl;
			return 0;
		}
	}
	cout << "NO" << endl;
	return 0;
}