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

const int maxn = 1e3 + 10;
int x[maxn],
	y[maxn],
	p[maxn],
	ord[maxn],
	n, s;

bool cmp(int i, int j){
	return x[i] * x[i] + y[i] * y[i] < x[j] * x[j] + y[j] * y[j];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> s;
	s = 1000 * 1000 - s;
	for(int i = 0; i < n; i++)
		cin >> x[i] >> y[i] >> p[i];
	iota(ord, ord + n, 0);
	sort(ord, ord + n, cmp);
	for(int i = 0; i < n; i++){
		int id = ord[i];
		s -= p[id];
		if(s <= 0){
			cout.precision(15);
			cout << fixed << sqrt(x[id] * x[id] + y[id] * y[id]) << '\n';
			return 0;
		}
	}
	cout << -1 << endl;
	return 0;
}