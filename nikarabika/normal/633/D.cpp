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

const int maxn = 1000 + 85 - 69;
int a[maxn],
	cnt[maxn],
	n;
vector<int> all;

int f(int x, int y){
	int z = x + y, ret;
	int idz = lower_bound(all(all), z) - all.begin();
	if(idz != sz(all) and all[idz] == z and cnt[idz])
		cnt[idz]--, ret = 1 + f(y, z), cnt[idz]++;
	else
		ret = 2;
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		all.PB(a[i]);
	}
	sort(all(all));
	all.resize(unique(all(all)) - all.begin());
	for(int i = 0; i < n; i++)
		cnt[lower_bound(all(all), a[i]) - all.begin()]++;
	int ans = 2;
	for(int i = 0; i < sz(all); i++){
		cnt[i]--;
		for(int j = 0; j < sz(all); j++)
			if(cnt[j])
				cnt[j]--, smax(ans, f(all[i], all[j])), cnt[j]++;
		cnt[i]++;
	}
	cout << ans << endl;
	return 0;
}