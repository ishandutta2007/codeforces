//sobskdrbhvk
//remember the flight, the bird dies ):(
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

const int maxn = 4e5 + 85 - 69;
const int maxval = 4e5 + 85 - 69;
LL a[maxn],
   cnt[maxn],
   sum[maxn],
   n;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		cnt[a[i]]++;
	}
	sort(a, a + n);
	for(int i = 1; i < maxval; i++)
		sum[i] = sum[i - 1] + cnt[i];
	LL ans = 0;
	for(int i = 1; i < maxval; i++){
		LL cur = 0;
		if(cnt[i])
			for(int j = i; j + i <= maxval; j += i)
				cur += 1LL * (sum[j + i - 1] - sum[j - 1]) * j;
		smax(ans, cur);
	}
	cout << ans << '\n';
	return 0;
}