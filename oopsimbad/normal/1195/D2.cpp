#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
 
#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
#define f first
#define s second
#define mp make_pair
#define pb push_back
 
const int MAXN = 100005;
const ll MOD = 998244353;

ll sum[11], cnt[11], sum2[11];
int arr[MAXN];

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
	int n; cin >> n;
	ll ans = 0;
	F0R(i, n) {
		int a; cin >> a; arr[i] = a;
		int c10 = 1, j = 0;
		ll cur = 0;
		while(a != 0) {
			cur = (cur + a%10*11LL%MOD*c10%MOD*c10%MOD)%MOD;
			a /= 10;
			c10 *= 10;
			j++;
		}
		sum[j] = (sum[j] + cur) % MOD;
		cnt[j]++;
	}
	F0R(i, n) {
		int a = arr[i];
		int c10 = 1, j = 0;
		ll cur = 0;
		while(a != 0) {
			cur = (cur + a%10*11LL%MOD*c10%MOD*c10%MOD)%MOD;
			a /= 10;
			c10 *= 10;
			j++;
			if(a == 0) sum2[j] = (sum2[j] + (2LL*a%MOD*c10%MOD*c10%MOD+cur)%MOD*cnt[j]%MOD+sum[j]) % MOD;
			ans = (ans + (2LL*a%MOD*c10%MOD*c10%MOD+cur)%MOD*cnt[j]%MOD+sum[j])%MOD;
		}
	}
	F0R(i, 11) ans = (ans - sum2[i]*499122177%MOD + MOD) % MOD;
	cout << ans << endl;
    return 0;
}