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

LL b, p, wat;

void solve(int cnt, int k = 512){
	if(cnt == 1)
		return;
	while(k > cnt) k >>= 1;
	wat += (2 * b + 1) * k / 2;
	solve(cnt - k / 2, k);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n >> b >> p;
	solve(n);
	cout << wat << ' ' << p * n << endl;
	return 0;
}