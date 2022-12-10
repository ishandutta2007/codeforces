#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef pair<LL, LL> pll;

#define PB push_back
#define MP make_pair
#define L first
#define R second

LL x;
vector<pll> ans;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> x;
	for(LL n = 1; n * (n + 1) * (2 * n + 1) / 6 <= x; n++){
		LL r = x;
		r *= 6;
		if(r % (n * (n + 1)) != 0)
			continue;
		r /= n * (n + 1);
		r += n - 1;
		if(r % 3 != 0)
			continue;
		r /= 3;
		if(r >= n)
			ans.PB(MP(n, r)), ans.PB(MP(r, n));
	}
	sort(ans.begin(), ans.end());
	ans.resize(unique(ans.begin(), ans.end()) - ans.begin());
	cout << ans.size() << endl;
	for(int i = 0; i < (int)ans.size(); i++)
		cout << ans[i].L << ' ' << ans[i].R << endl;
	return 0;
}