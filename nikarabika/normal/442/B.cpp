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

const int maxn = 100 + 10;
vector<LD> vec;
int n;

LD merge(int i, int j){
	LD p = vec[i];
	LD q = vec[j];
	return p * (1 - q) + (1 - p) * q;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++){
		LD x;
		cin >> x;
		vec.PB(x);
	}
	sort(all(vec));
	LD ans = 0,
	   zer = 1,
	   yek = 0;
	for(int i = n - 1; i >= 0; i--){
		LD nyek = yek * (1 - vec[i]) + zer * vec[i];
		LD nzer = zer * (1 - vec[i]);
		yek = nyek, zer = nzer;
		smax(ans, yek);
	}
	cout.precision(15);
	cout << fixed << ans << '\n';
	return 0;
}