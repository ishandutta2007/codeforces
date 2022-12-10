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

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	int lo = 0, hi = 100 * (n + m);
	while(hi - lo > 1){
		int mid = (lo + hi) >> 1;
		int fmid1 = mid / 2 + mid / 3 - mid / 6,
			fmid2 = mid / 2,
			fmid3 = mid / 3;
		if(fmid1 >= n + m and fmid2 >= n and fmid3 >= m)
			hi = mid;
		else
			lo = mid;
	}
	cout << hi << endl;
	return 0;
}