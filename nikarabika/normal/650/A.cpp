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

const int maxn = 2e5 + 85 - 69;
LL cntx[maxn],
   cnty[maxn],
   cntp[maxn];
pii po[maxn];
vector<int> allx, ally;
vector<pii> allp;
int n;
LL ans;

template<typename AN>
void compress(vector<AN> &vec){
	sort(all(vec));
	vec.resize(unique(all(vec)) - vec.begin());
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++){
		int fi, se;
		cin >> fi >> se;
		po[i] = {fi, se};
		allp.PB({fi, se});
		allx.PB(fi);
		ally.PB(se);
	}
	compress(allp);
	compress(allx);
	compress(ally);
	for(int i = 0; i < n; i++){
		int idx = lower_bound(all(allx), po[i].L) - allx.begin(),
			idy = lower_bound(all(ally), po[i].R) - ally.begin(),
			idp = lower_bound(all(allp), po[i]) - allp.begin();
		ans += (cntx[idx]++) + (cnty[idy]++) - (cntp[idp]++);
	}
	cout << ans << endl;
	return 0;
}