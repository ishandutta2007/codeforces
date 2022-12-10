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

int f(int x){
	if(x == 0)
		return 0;
	return x / 5 + f(x / 5);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int m;
	cin >> m;
	int lo = 0, hi = 5 * m;
	while(hi - lo > 1){
		int mid = (lo + hi) >> 1;
		int fmid = f(mid);
		if(fmid < m)
			lo = mid;
		else
			hi = mid;
	}
	if(f(hi) != m)
		cout << 0 << endl;
	else{
		cout << 5 << endl;
		for(int i = 0; i < 5; i++)
			cout << hi + i << ' ';
		cout << endl;
	}
	return 0;
}