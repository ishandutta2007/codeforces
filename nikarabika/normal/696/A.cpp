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

map<LL, LL> mp;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int q;
	cin >> q;
	while(q--){
		LL ty, fi, se, th;
		cin >> ty >> fi >> se;
		if(ty == 1){
			cin >> th;
			if(fi == se)
				continue;
			while(fi != se){
				if(fi < se)
					swap(fi, se);
				mp[fi] += th;
				fi>>=1;
			}
		}
		else{
			LL ret = 0;
			while(fi != se){
				if(fi < se) swap(fi, se);
				ret += mp[fi];
				fi>>=1;
			}
			cout << ret << '\n';
		}
	}
	return 0;
}