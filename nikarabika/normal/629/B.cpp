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

int cnt[2][400], n;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	while(n--){
		char c;
		int st, en;
		cin >> c >> st >> en;
		cnt[c == 'M'][st - 1]++, cnt[c == 'M'][en]--;
	}
	int ans = -1;
	for(int i = 0; i < 366; i++){
		for(int j = 0; j < 2; j++)
			cnt[j][i + 1] += cnt[j][i];
		smax(ans, min(cnt[0][i], cnt[1][i]));
	}
	cout << ans * 2 << endl;
	return 0;
}