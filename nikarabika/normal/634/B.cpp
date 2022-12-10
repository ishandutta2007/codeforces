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
#define smin(x, y) (x) = min((x), (y))
#define smax(x, y) (x) = max((x), (y))

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	const int maxl = 60;
	LL s, x;
	cin >> s >> x;
	bool an = s == x;
	LL ans = 1;
	for(int i = maxl - 1; i >= 0; i--)
		if((x >> i) & 1)
			s -= 1LL << i, ans <<= 1;
	if(s & 1) ans = 0;
	for(int i = 1; i < maxl; i++)
		if(((s >> i) & 1) and ((x >> (i - 1)) & 1))
			ans = 0;
	if(an)
		ans = max(0LL, ans - 2);
	cout << ans << endl;
	return 0;
}