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
#define xy(a) a.x, a.y

const int maxn = int(5e3) + 10;

#define x first
#define y second
using pp=pair<int,int>;
pp operator+(pp a, pp b) { return {a.x+b.x, a.y+b.y}; }
pp operator-(pp a, pp b) { return {a.x-b.x, a.y-b.y}; }
pp operator-(pp a) { return {-a.x, -a.y}; }
pp operator*(int c, pp v) { return {c*v.x, c*v.y}; }
ll operator*(pp u, pp v) { return u.x*1ll*v.x + u.y*1ll*v.y; }

long long cross(pp a, pp b) {
	return b.y*1ll*a.x - b.x*1ll*a.y;
}

long long cross(const pp& a, const pp& b) {
	return b.y*1ll*a.x - b.x*1ll*a.y;
}

int n;
pp p[maxn];

int a[maxn];

bool ok(pp &a, pp &b, pp &c) {
	return (b-a) * (c-b) < 0;
}

int main()
{
	cppio();
	cin >> n;
	rrep(i, n) cin >> p[i].x >> p[i].y;
	iota(a+1, a+n+1, 1);

	while (true) {
		try {
			for (int i=3; i<=n; ++i) {
				int v = a[i];
				if (ok(p[a[i-2]], p[a[i-1]], p[v])) continue;
				if (ok(p[v], p[a[1]], p[a[2]])) {
					int x = v;
					for (int j=1; j<=i; ++j) {
						swap(x, a[j]);
					}
					continue;
				}
				bool chk = 0;
				for (int j=1; j<=i-2; ++j) {
					if (!ok(p[a[j]], p[v], p[a[j+1]])) continue;
					if (1<=j-1 && !ok(p[a[j-1]], p[a[j]], p[v])) continue;
					if (j+2<=i-1 && !ok(p[v], p[a[j+1]], p[a[j+2]])) continue;
					int x = v;
					for (int k=j+1; k<=i; ++k) {
						swap(x, a[k]);
					}
					chk = 1;
					break;
				}
				if (chk) continue;
				throw 0;
			}
			break;
		} catch (int _) {
			random_shuffle(a+1, a+n+1);
		}
	}

	rrep(i, n) cout << a[i] << " \n"[i==n];

	return 0;
}