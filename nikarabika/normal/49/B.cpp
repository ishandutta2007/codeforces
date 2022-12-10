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

int getd(int x){
	int ret = 0;
	while(x){
		smax(ret, x % 10);
		x /= 10;
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int x, y;
	cin >> x >> y;
	int d = max(getd(x), getd(y)) + 1;
	int xx = 0, yy = 0;
	int an = 1;
	while(x or y){
		xx += (x % 10) * an;
		yy += (y % 10) * an;
		x /= 10;
		y /= 10;
		an *= d;
	}
	int sum = xx + yy;
	int cnt = 0;
	while(sum){
		cnt++;
		sum /= d;
	}
	cout << cnt << endl;
	return 0;
}