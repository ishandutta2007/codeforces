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

const int maxn = 2e5 + 85 - 69;
int a[maxn],
	b[maxn];
int n;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i + 1] >> b[i];
	for(int i = 0; i < n; i++)
		a[i + 1] += a[i];
	int lo = -1e9,
		hi = +1e9;
	for(int i = 0; i < n; i++){
		int rate = a[i];
		if(b[i] == 1)
			smax(lo, 1900 - rate);
		else
			smin(hi, 1899 - rate);
	}
	if(lo > hi)
		cout << "Impossible\n";
	else if(hi == 1e9)
		cout << "Infinity" << endl;
	else
		cout << hi + a[n] << endl;
	return 0;
}