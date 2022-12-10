//sobskdrbhvk
//remember the flying, the bird dies ):(
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
	int n;
	cin >> n;
	LL sum = 0;
	int val[n];
	for(int i = 0; i < n; i++){
		int fi, se;
		cin >> fi >> se;
		val[i] = fi - se;
		sum += val[i];
	}
	LL mx = sum,
	   mn = sum;
	int posx = -1,
	   posn = -1;
	for(int i = 0; i < n; i++){
		smax(mx, sum - 2 * val[i]);
		if(mx == sum - 2 * val[i]) posx = i;
		smin(mn, sum - 2 * val[i]);
		if(mn == sum - 2 * val[i]) posn = i;
	}
	if(abs(mx) > abs(mn))
		cout << posx + 1;
	else
		cout << posn + 1;
	return 0;
}