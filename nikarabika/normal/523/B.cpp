//sobskdrbhvk
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
typedef long double LD;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define sz(x) ((int)(x).size())
#define smax(x, y) ((x) = max((x), (y)))
#define smin(x, y) ((x) = min((x), (y)))
#define all(x) x.begin(),x.end()

const int maxn = 2e5 + 100;
LL a[maxn], n, t;
LD c, realans[maxn], appans[maxn];

inline LD Abs(LD x){return x <= 0 ? -x : x;};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> t >> c;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		LD an = LD(a[i]) / LD(t);
		appans[i] = ((i > 0 ? appans[i - 1] : LD(0)) + an) / c;
	}
	LD ave = 0;
	for(int i = 0; i < n; i++){
		if(i >= t)
			ave -= LD(a[i - t]) / LD(t);
		ave += LD(a[i]) / LD(t);
		realans[i] = ave;
	}
	int q;
	cin >> q;
	cout.precision(10);
	while(q--){
		int idx;
		cin >> idx;
		idx--;
		cout << fixed << realans[idx] << ' ' << appans[idx] << ' ' << Abs(appans[idx] - realans[idx]) / realans[idx] << '\n';
	}
	return 0;
}