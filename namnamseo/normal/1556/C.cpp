#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pp;
typedef pair<ll,ll> pll;
void cppio(){ ios_base::sync_with_stdio(0); cin.tie(0); }
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define eb emplace_back
#define x first
#define y second
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define sz(x) (int)(x).size()

const int maxn = int(2e5) + 10;

int n;
int a[maxn];

ll stk[maxn], top;
ll cnt[maxn];

int main()
{
	cppio();
	cin >> n;
	n -= n&1;
	rrep(i, n) cin >> a[i];

	ll ans = 0;

	top = 1;
	rrep(i, n) {
		if (i%2 == 1) {
			stk[top] = stk[top-1] + a[i];
			cnt[top] = 0;
			++top;
			continue;
		}
		ll tgt = stk[top-1] - a[i];
		while (true) {
			if (stk[top-1] < tgt) {
				stk[top] = tgt;
				cnt[top] = 1;
				++top;
				break;
			} else if (stk[top-1] == tgt) {
				ans += cnt[top-1];
				++cnt[top-1];
				break;
			} else {
				if (top == 1) {
					ans += cnt[top-1];
					stk[top-1] = tgt;
					cnt[top-1] = 0;
					break;
				}
				ll d = min(stk[top-1]-stk[top-2], stk[top-1]-tgt);
				ans += d + cnt[top-1];
				--top;
			}
		}
	}

	cout << ans << '\n';

	return 0;
}