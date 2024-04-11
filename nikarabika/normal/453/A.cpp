//sobskdrbhvk
//remember the flying, the bird dies ):(
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

LD Pow(LD x, int y){
	if(!y) return 1;
	LD ret = Pow(x, y>>1);
	ret *= ret;
	if(y&1) ret *= x;
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> m >> n;
	LD ans = m;
	for(int i = 1; i < m; i++){
		LD val = LD(i) / LD(m);
		ans -= Pow(val, n);
	}
	cout.precision(15);
	cout << fixed << ans << '\n';
	return 0;
}