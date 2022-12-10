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

const int maxn = 1e6 + 10;
const LL Mod = 1e9 + 7;
bool isp[maxn];
int sign[maxn],
	cnt[maxn];
LL P[maxn];
int n;

LL func(int x) {
	return (x * P[x - 1]) % Mod;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	memset(isp, true, sizeof isp);
	fill(sign, sign + maxn, 1);
	isp[0] = isp[1] = false;
	for (int i = 2; i < maxn; i++)
		if (isp[i])
			for (int j = i; j < maxn; j += i) {
				isp[j] = i == j;
				if ((j / i) % i == 0)
					sign[j] = 0;
				else
					sign[j] *= -1;
			}
	P[0] = 1;
	for (int i = 1; i < maxn; i++)
		P[i] = (P[i - 1] << 1) % Mod;
	cin >> n;
	for (int x, i = 0; i < n; i++)
		cin >> x, cnt[x]++;
	for (int i = 1; i < maxn; i++)
		for (int j = i + i; j < maxn; j += i)
			cnt[i] += cnt[j];
	LL ans = 0;
	for (int i = 2; i < maxn; i++) {
		LL rc = 0;
		for (int j = i; j < maxn; j += i)
			rc = (rc + sign[j / i] * func(cnt[j])) % Mod;
		ans += rc * i;
		ans %= Mod;
	}
	ans = (ans + Mod) % Mod;
	cout << ans << endl;
	return 0;
}