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
	int n, k;
	cin >> n >> k;
	if(k >= n * (n - 1) / 2){
		cout << "no solution\n";
		return 0;
	}
	int curx = 0;
	for(int i = n - 1; i >= 0; --i){
		cout << 0 << ' ' << curx << '\n';
		curx += i;
	}
	return 0;
}