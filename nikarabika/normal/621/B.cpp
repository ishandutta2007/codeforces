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

const int maxn = 2000;
LL arrcnt2[maxn * 2 + 100];
LL cnt1[maxn * 2 + 100];
int n;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	LL *cnt2 = arrcnt2 + maxn + 50;
	cin >> n;
	while(n--){
		int x, y;
		cin >> x >> y;
		x--, y--;
		cnt1[x + y]++;
		cnt2[x - y]++;
	}
	LL ans = 0;
	for(int i = -maxn; i <= +maxn; i++)
		ans += cnt2[i] * (cnt2[i] - 1) / 2;
	for(int i = 0; i <= 2 * maxn; i++)
		ans += cnt1[i] * (cnt1[i] - 1) / 2;
	cout << ans << endl;
	return 0;
}