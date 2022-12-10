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

const int maxn = 200 + 85 - 69;
int a[maxn],
	tmp1[maxn],
	tmp2[maxn],
	n, k, ans = -1000000000;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	for(int len = 1; len <= n; len++){
		for(int i = 0; i + len <= n; i++){
			int sz1 = 0,
				sz2 = 0,
				sum1 = 0;
			for(int j = 0; j < n; j++){
				if(j >= i and j < i + len)
					tmp1[sz1++] = a[j], sum1 += a[j];
				else
					tmp2[sz2++] = a[j];
			}
			sort(tmp1, tmp1 + sz1);
			sort(tmp2, tmp2 + sz2, greater<int>());
			for(int j = 0; j <= min(k, min(sz1, sz2)); j++){
				smax(ans, sum1);
				sum1 -= tmp1[j];
				sum1 += tmp2[j];
			}
		}
	}
	cout << ans << endl;
	return 0;
}