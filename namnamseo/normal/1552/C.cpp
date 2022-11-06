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

int n, k;
int a[maxn];

void Work() {
	cin >> n >> k;
	fill(a+1, a+1+2*n, 0);
	rrep(i, k) {
		int x, y; cin >> x >> y;
		a[x] = y; a[y] = x;
	}

	static int tmp[maxn], tn;
	tn = 0;
	rrep(i, 2*n) if (!a[i]) tmp[tn++] = i;
	rep(i, n-k) {
		int x = tmp[i];
		int y = tmp[i+n-k];
		a[x] = y; a[y] = x;
	}

	int ans = 0;
	rrep(i, 2*n) if (i < a[i]) {
		rrep(j, 2*n) if (j < i && i < a[j] && a[j] < a[i]) ++ans;
		else if (i < j && j < a[i] && a[i] < a[j]) ++ans;
	}

	ans /= 2;
	cout << ans << '\n';
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