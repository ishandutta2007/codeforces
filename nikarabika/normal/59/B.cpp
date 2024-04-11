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
	int n, mn = -1, sum = 0;
	cin >> n;
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		sum += x;
		if((x & 1) and (mn == -1 or x < mn))
			mn = x;
	}
	if(sum & 1)
		cout << sum << endl;
	else if(mn == -1)
		cout << 0 << endl;
	else
		cout << sum - mn << endl;
	return 0;
}