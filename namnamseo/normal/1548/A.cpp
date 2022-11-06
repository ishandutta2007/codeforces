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

int n, m;

int od[maxn];
int nzc;

void ae(int x, int y, int sgn) {
	if (!od[x]) ++nzc;
	od[x] += sgn;
	if (!od[x]) --nzc;
}

int main()
{
	cppio();
	cin >> n >> m;

	rrep(i, m) {
		int x, y; cin >> x >> y;
		if (x > y) swap(x, y);
		ae(x, y, 1);
	}

	int q; cin >> q;

rrep(qi, q) {
	int cmd; cin >> cmd;
	if (cmd == 3) {
		cout << (n-nzc) << '\n';
		continue;
	}
	int x, y; cin >> x >> y;
	if (x > y) swap(x, y);
	int sgn = (cmd == 1) ? 1:(-1);
	ae(x, y, sgn);
}
	return 0;
}