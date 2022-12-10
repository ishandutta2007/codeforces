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

const LL maxval = 1e16;
map<LL, int> mp;
LL n, k;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	mp[0] = 1;
	LL su = 0,
	   ans = 0;
	for(int i = 0; i < n; i++){
		LL x;
		cin >> x;
		su += x;
		LL tmp = 1;
		mp[su]++;
		if(k == 1){
			ans += mp[su - 1];
			continue;
		}
		if(k == 1 or k == -1){
			ans += mp[su + 1] + mp[su - 1];
			continue;
		}
		while(tmp < maxval){
			ans += mp[su - tmp];
			tmp *= k;
		}
	}
	cout << ans << endl;
	return 0;
}