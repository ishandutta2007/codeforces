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

int pl, pr,
	vl, vr,
	k;

LL getp(int l, int r){
	smax(l, pl);
	smin(r, pr);
	if(l > r) return 0;
	return r - l + 1;//LD(r - l + 1) / (pr - pl + 1);
}

LL getv(int l, int r){
	smax(l, vl);
	smin(r, vr);
	if(l > r) return 0;
	return r - l + 1;//LD(r - l + 1) / (vr - vl + 1);
}

vector<int> all;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> pl >> pr >> vl >> vr >> k;
	all.PB(0);
	for(int len = 1; len < 10; len++){
		for(int mask = 0; mask < (1 << len); mask++){
			LL num = 0;
			for(int i = len - 1; i >= 0; i--)
				if((mask >> i) & 1)
					num = num * 10 + 7;
				else
					num = num * 10 + 4;
			all.PB(num);
		}
	}
	all.PB(1e9 + 5);
	LL ans = 0;
	for(int i = 1; i < sz(all) - k; i++){
		ans += getp(all[i - 1] + 1, all[i]) * getv(all[i + k - 1], all[i + k] - 1);
		LL val = 0;
		ans += (val = getv(all[i - 1] + 1, all[i]) * getp(all[i + k - 1], all[i + k] - 1));
		if(val and k == 1) ans--;
	}
	cout.precision(15);
	cout << fixed << LD(ans) / (1LL * (pr - pl + 1) * (vr - vl + 1)) << '\n';
	return 0;
}