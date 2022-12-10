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

int n, k;
vector<int> vec;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	for(int i = 0; i < n; i++){
		char c;
		cin >> c;
		if(c - '1')
			vec.PB(i);
	}
	int ans = 1000 * 1000;
	for(int i = 0; i + k < sz(vec); i++){
		int left = vec[i],
			right = vec[i + k];
		int lo = i, hi = i + k;
		while(hi - lo > 5){
			int mid = (lo + hi) >> 1;
			if(right - vec[mid] <= vec[mid] - left)
				hi = mid;
			else
				lo = mid;
		}
		for(int j = lo; j <= hi; j++)
			smin(ans, max(right - vec[j], vec[j] - left));
	}
	cout << ans << endl;
	return 0;
}