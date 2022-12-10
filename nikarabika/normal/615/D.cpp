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
#define smin(x, y) (x) = min((x), (y))
#define smax(x, y) (x) = max((x), (y))

const int maxn = 2e5 + 85 - 69;
const LL Mod = 1000LL * 1000 * 1000 + 7;
LL a[maxn], cnt[maxn], mul1[maxn], mul2[maxn];
vector<LL> all;
int n;

LL Pow(LL x, LL y){
	if(y == 0)
		return 1;
	LL ret = Pow(x, y / 2);
	ret = (ret * ret) % Mod;
	if(y & 1)
		ret = (ret * x) % Mod;
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
	sort(all.begin(), all.end());
	all.resize(unique(all.begin(), all.end()) - all.begin());
	for(int i = 0; i < n; i++)
		cnt[lower_bound(all.begin(), all.end(), a[i]) - all.begin()]++;
	n = all.size();
	mul1[0] = 1;
	for(int i = 0; i < n; i++)
		mul1[i + 1] = (mul1[i] * (cnt[i] + 1)) % (Mod - 1);
	mul2[n] = 1;
	for(int i = n - 1; i >= 0; i--)
		mul2[i] = (mul2[i + 1] * (cnt[i] + 1)) % (Mod - 1);
	LL ans = 1;
	for(int i = 0; i < n; i++)
		ans = (ans * Pow(Pow(all[i], (cnt[i] * (cnt[i] + 1)) / 2), (mul1[i] * mul2[i + 1]) % (Mod - 1))) % Mod;
	cout << ans << endl;
	return 0;
}