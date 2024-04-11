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
	int n, m, MN, MX;
	cin >> m >> n >> MN >> MX;
	int mx = -1, mn = 85 + 85 - 69;
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		smax(mx, x);
		smin(mn, x);
	}
	bool an;
	if(m - n == 1)
		an = (MN == mn and mx <= MX) or (MX == mx and mn >= MN);
	else
		an = (mx <= MX and mn >= MN);
	cout << (an ? "Correct" : "Incorrect");
	return 0;
}