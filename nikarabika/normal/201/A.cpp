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
	int x;
	cin >> x;
	if(x == 3){
		cout << 5 << endl;
		return 0;
	}
	int ans = 1;
	while(ans * ans / 2 + 1 < x) ans+=2;
	cout << ans << endl;
	return 0;
}