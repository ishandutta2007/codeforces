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

LD cnt(int x, int l, int r){
	return (x < l ? (LD)0 : LD(min(x, r) - l + 1)) / LD(r - l + 1);
}

LD cnt2(int x, int l, int r){
	return LD(1) - cnt(x - 1, l, r);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, l[5], r[5];
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> l[i] >> r[i];
	LD allans = 0;
	for(int i = 1; i <= 10000; i++){
		LD ans = 0;
		for(int j = 0; j < n; j++) if(i >= l[j] and i <= r[j]){
			for(int k = 0; k < n; k++) if(k != j){
				LD an = LD(i) / LD(r[j] - l[j] + 1);
				an *= cnt2(i + 1, l[k], r[k]);
				for(int ii = 0; ii < n; ii++) if(ii != j and ii != k)
					an *= cnt(i - (ii > j), l[ii], r[ii]);
				ans += an;
			}
			for(int k = 0; k < j; k++) if(i >= l[k] and i <= r[k]){
				LD an = LD(i) / LD(r[j] - l[j] + 1);
				an /= LD(r[k] - l[k] + 1);
				for(int ii = 0; ii < n; ii++) if(ii != j and ii != k)
					an *= cnt(i - (ii > k), l[ii], r[ii]);
				ans += an;
			}
		}
		allans += ans;
	}
	cout.precision(15);
	cout << fixed << allans << endl;
	return 0;
}