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

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string s;
	cin >> s;
	reverse(all(s));
	LL ans = 0;
	for(int i = 0; i < sz(s); i++)
		ans += (s[i] - '0') % 4 == 0;
	for(int i = 0; i + 1 < sz(s); i++)
		if(((s[i + 1] - '0') * 10 + s[i] - '0') % 4 == 0)
			ans += sz(s) - i - 1;
	cout << ans << endl;
	return 0;
}