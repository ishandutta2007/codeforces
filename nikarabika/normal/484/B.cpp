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

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	vector<int> s;
	cin >> n;
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		s.PB(x);
	}
	sort(all(s));
	s.resize(unique(all(s)) - s.begin());
	int ans = 0;
	for(auto val : s){
		for(int val2 = val; val2 <= 1000 * 1000; val2 += val){
			auto it = lower_bound(all(s), val2 + val);
			it--;
			if((*it) >= val2)
				smax(ans, (*it) % val);
		}
	}
	cout << ans << '\n';
	return 0;
}