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

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string s;
	cin >> s;
	s = 'a' + s;
	int ans = 0;
	for(int i = 1; i < sz(s); i++){
		int dif = abs(s[i] - s[i - 1]);
		ans += min(dif, 26 - dif);
	}
	cout << ans << '\n';
	return 0;
}