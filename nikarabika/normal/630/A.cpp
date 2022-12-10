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

LL Pow(LL n){
	LL ret = 1, an = 5;
	while(n){
		if(n & 1)
			ret = (ret * an) % 100;
		an = (an * an) % 100;
		n >>= 1;
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	LL n;
	cin >> n;
	int ret = Pow(n);
	cout << ret << endl;
	return 0;
}