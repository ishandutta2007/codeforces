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

LL b, d, s;

LL solve(int ii, int jj){
	LL a[3] = {b, d, s};
	for(int i = ii; i < 3; i++)
		a[i]--;
	for(int i = 0; i <= jj; i++)
		a[i]--;
	LL cnt = max(a[0], max(a[1], a[2]));
	LL ret = 0;
	for(int i = 0; i < 3; i++)
		ret += cnt - a[i];
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	LL ans = -1;
	cin >> b >> d >> s;
	for(int i = 0; i < 3; i++)
		for(int j = 0; j < 3; j++)
			if(ans == -1 or solve(i, j) < ans)
				ans = solve(i, j);
	cout << ans << '\n';
	return 0;
}