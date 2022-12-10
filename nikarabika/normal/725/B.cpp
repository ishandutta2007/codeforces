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
	LL n;
	char c;
	cin >> n >> c;
	n--;
	if(n % 4 >= 2) n -= 2;
	LL ans = n / 4 * 16;
	n %= 4;
	ans += n * 7;
	n %= 2;
	if(c >= 'd')
		ans += 'g' - c;
	else
		ans += c - 'a' + 4;
	cout << ans << endl;
	return 0;
}