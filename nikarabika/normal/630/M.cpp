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

int fusk(int x, int deg){
	x = (x + deg) % 360;
	return min(x, 360 - x);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	LL x;
	cin >> x;
	x %= 360;
	x = 360 - x;
	int ans = 0;
	for(int i = 1; i < 4; i++)
		if(fusk(x, 90 * i) < fusk(x, 90 * ans))
			ans = i;
	cout << ans << endl;
	return 0;
}