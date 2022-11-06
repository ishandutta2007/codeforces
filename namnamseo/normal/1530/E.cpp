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
int ccO[26];
int cc[26];

inline void Put(int i) { cout << char('a'+i); }

inline int Poll(int i) { while (i < 26 && !cc[i]) ++i; return i; }

void Work() {
	copy(ccO, ccO+26, cc);
	n = accumulate(cc, cc+26, 0);

	{
		int nz = 0;
		rep(i, 26) nz += !!cc[i];
		if (nz == 1) {
			int i = Poll(0);
			rep(j, n) Put(i);
			cout << '\n';
			return;
		}
	}

	rep(i, 26) if (cc[i] == 1) {
		Put(i); --cc[i];
		rep(j, 26) rep(k, cc[j]) Put(j);
		cout << '\n';
		return;
	}

	int f = Poll(0);
	if (cc[f] == 1) {
		rep(i, 26) rep(j, cc[i]) Put(i);
		cout << '\n'; return;
	}

	{
		int &fc = cc[f];
		int oth = n-fc;
		if (oth >= fc-2) {
			int ni = f+1;
			Put(f); --fc;
			while (fc) {
				Put(f); --fc;
				ni = Poll(ni);
				if (ni < 26) {
					Put(ni); --cc[ni];
				}
			}
			rep(i, 26) rep(j, cc[i]) Put(i);
			cout << '\n'; return;
		}
	}

	int nf = Poll(f+1);
	if (cc[nf] == 1) {
		Put(f); --cc[f];
		Put(nf); --cc[nf];
		rep(i, 26) rep(j, cc[i]) Put(i);
		cout << '\n'; return;
	}

	int nnf = Poll(nf+1);
	if (nnf != 26) {
		Put(f); --cc[f];
		Put(nf); --cc[nf];
		rep(i, cc[f]) Put(f); cc[f] = 0;
		Put(nnf); --cc[nnf];
		rep(i, 26) rep(j, cc[i]) Put(i);
		cout << '\n'; return;
	}

	Put(f); --cc[f];
	rep(i, cc[nf]) Put(nf); cc[nf] = 0;
	rep(i, cc[f]) Put(f); cc[f] = 0;
	cout << '\n'; return;
}

int main()
{
	cppio();
	int tc; cin >> tc;
rrep(tci, tc) {
	fill(ccO, ccO+26, 0);
	static char s[maxn];
	cin >> s;
	for (int i=0; s[i]; ++i) ++ccO[s[i]-'a'];

	Work();
}

	return 0;
}