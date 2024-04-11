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
	LL n, sum = 0, Min = 1000 * 1000 * 1000 + 10;
	cin >> n;
	while(n--){
		LL x;
		cin >> x;
		sum += x;
		if(x & 1)
			smin(Min, x);
	}
	if(sum & 1LL)
		cout << sum - Min << endl;
	else
		cout << sum << endl;
	return 0;
}