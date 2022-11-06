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

int n, k;
const int maxn = 100'010;

int a[maxn];

int kpd[maxn];
int kmd[maxn];

bool f()
{
	if (n == 1) {
		return a[1] == k;
	}

	bool ex = 0;
	rrep(i, n) if (a[i] == k) { ex = 1; break; }
	if (!ex) return 0;

	rrep(i, n-1) {
		if ((a[i]>=k && a[i+1]>=k)) {
			return 1;
		}
	}

	rrep(i, n-2) if (a[i]>=k && a[i+2]>=k) return 1;

	return 0;
}

int main()
{
	cppio();
	int tc; cin >> tc;
for(;tc--;) {
	cin >> n >> k;
	rrep(i, n) cin >> a[i];

	if (f()) {
		cout << "yes\n";
	} else cout << "no\n";
}
	return 0;
}