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
	LL l, r, k, num = 1;
	bool has = false;
	cin >> l >> r >> k;
	while(num <= r){
		if(num >= l){
			cout << num << ' ';
			has = true;
		}
		if(num <= r / k)
			num *= k;
		else
			break;
	}
	if(!has)
		cout << -1;
	return 0;
}