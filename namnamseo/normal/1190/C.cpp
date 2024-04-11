#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pp;
typedef pair<ll,ll> pll;
void read(int& x){ scanf("%d",&x); }
void read(ll& x){ scanf("%lld",&x); }
void read(pp& x){ scanf("%d%d",&x.first, &x.second); }
void read(pll& x){ scanf("%lld%lld",&x.first, &x.second); }
template<typename T,typename... Args>
void read(T& a,Args&... b){ read(a); read(b...); }
void cppio(){ ios_base::sync_with_stdio(0); cin.tie(0); }
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define eb emplace_back
#define x first
#define y second
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define sz(x) (int)(x).size()
#define xy(a) (a).x, (a).y

const int maxn = int(1e5) + 10;

int n, k;
char s[maxn];

pp dpL[maxn][2];
pp dpR[maxn][2];

int main()
{
	cin >> n >> k >> (s+1);
	rrep(i, n) s[i] -= '0';

	rep(j, 2) dpL[0][j] = {maxn, -1};
	rrep(i, n) {
		rep(j, 2) dpL[i][j] = dpL[i-1][j];
		int p = s[i];

		dpL[i][p].x = min(dpL[i][p].x, i);
		dpL[i][p].y = max(dpL[i][p].y, i);
	}

	rep(j, 2) dpR[n+1][j] = {maxn, -1};
	for(int i=n; 1<=i; --i) {
		rep(j, 2) dpR[i][j] = dpR[i+1][j];
		int p = s[i];

		dpR[i][p].x = min(dpR[i][p].x, i);
		dpR[i][p].y = max(dpR[i][p].y, i);
	}

	rep(j, 2) if(dpR[1][j].y != -1 && dpR[1][j].y - dpR[1][j].x + 1 <= k) {
		cout << "tokitsukaze" << endl;
		return 0;
	}

	bool allS = 1;
	rrep(i, n) if(s[i] != s[1]) allS = 0;
	if(allS) {
		cout << "tokitsukaze" << endl;
		return 0;
	}

	for(int i=k; i<=n; ++i) rep(j, 2) {
		bool lE = 0, rE = 0;
		pp t;

		t = dpL[i-k][1-j];
		if(t.y != -1) {
			lE = 1;
			if(t.y - t.x + 1 > k) {
				cout << "once again" << endl;
				return 0;
			}
		}

		t = dpR[i+1][1-j];
		if(t.y != -1) {
			rE = 1;
			if(t.y - t.x + 1 > k) {
				cout << "once again" << endl;
				return 0;
			}
		}

		if(lE && rE) {
			cout << "once again" << endl;
			return 0;
		}
	}

	cout << "quailty" << endl;
	return 0;
}