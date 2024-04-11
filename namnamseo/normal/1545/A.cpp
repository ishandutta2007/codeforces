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
pp a[maxn];
char s[maxn];

void Work() {
	cin >> n;
	rrep(i, n) cin >> a[i].x, a[i].y = i;
	sort(a+1, a+n+1);
	bool ok = true;
	for (int i=1; i<=n;) {
		int j = i;
		while (j+1 <= n && a[i].x == a[j+1].x) ++j;
		int c[2] = {0, 0};
		int c2[2] = {0, 0};
		for (int k=i; k<=j; ++k) ++c[a[k].y&1];
		for (int k=i; k<=j; ++k) ++c2[k&1];
		if (c[0] == c2[0] && c[1] == c2[1]) {}
		else ok = false;
		i = j+1;
	}
	cout << (ok ? "YES" : "NO") << '\n';
}

int main()
{
	cppio();
	int tc; cin >> tc;
rrep(tci, tc) {
	Work();
}
	return 0;
}