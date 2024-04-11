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

const int maxn = int(1e3) + 10;

int n;

int stk[maxn], top;

int main()
{
	cppio();
	int tc; cin >> tc;
for(;tc--;) {
	cin >> n;

	top = 0; fill(stk, stk+n+1, 0);
	rrep(i, n) {
		int x; cin >> x;
		if (x != 1) {
			while (top && stk[top-1]+1 != x) --top;
		}
		if (top && stk[top-1]+1 == x) ++stk[top-1];
		else {
			assert(x == 1);
			stk[top++] = x;
		}

		rep(j, top-1) cout << stk[j] << '.';
		cout << stk[top-1] << '\n';
	}
}

	return 0;
}