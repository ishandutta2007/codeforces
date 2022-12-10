//sobskdrbhvk
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef long double LD;
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

int n, cnt[210];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++){
			char c;
			cin >> c;
			if(c == 'C')
				cnt[i]++, cnt[j + n]++;
		}
	int ans = 0;
	for(int i = 0; i < 2 * n; i++)
		ans += cnt[i] * (cnt[i] - 1) / 2;
	cout << ans << endl;
	return 0;
}