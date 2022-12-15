#include <bits/stdc++.h>
using namespace std;

#define SZ(x) ((int)(x).size())
#define FOR(i, j, n) for (int i(j); i < (n); ++i)
#define FORR(v, c) for (auto &v : (c))
#define F first
#define S second
#define SQ(x) (x)*(x)
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define pnl(x) cout << x << '\n'
#define pns(x) cout << x << ' '
#define read(x) cin >> x
#define read2(x,y) cin >> x >> y
#define read3(x, y, z) cin >> x >> y >> z
#define read4(a, b, c, d) cin >> a >> b >> c >> d
#define readv(v) FORR(c,v) read(c)

typedef	vector<int>	vi;
typedef vector<long long>	vl;
typedef	long long ll;

int manacher(const vector<array<int, 26>> &s)
{
	int n = SZ(s);
	vector<int> d1(n);
	for (int i = 0, l = 0, r = -1; i < n; i++) {
		int k = (i > r) ? 1 : min(d1[l + r - i], r - i + 1);
		while (0 <= i - k && i + k < n && s[i - k] == s[i + k]) {
			k++;
		}
		d1[i] = k--;
		if (i + k > r) {
			l = i - k;
			r = i + k;
		}
	}
	vector<int> d2(n);
	for (int i = 0, l = 0, r = -1; i < n; i++) {
		int k = (i > r) ? 0 : min(d2[l + r - i + 1], r - i + 1);
		while (0 <= i - k - 1 && i + k < n && s[i - k - 1] == s[i + k]) {
			k++;
		}
		d2[i] = k--;
		if (i + k > r) {
			l = i - k - 1;
			r = i + k ;
		}
	}
	int ret(0);
	FOR(i,0,n)
		ret += d1[i] + d2[i];
	return ret;
}

bool is_pal(const array<int, 26> arr)
{
	int cnt(0);
	FOR(i,0,26) cnt+=arr[i]%2;
	return cnt<=1;
}

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int n, m;
	cin >> n >> m;
	vector<string> grid(n);
	FOR(i,0,n)
		read(grid[i]);

	int ans(0);
	FOR(l, 0, m)
	{
		vector<array<int, 26> > occ(n);
		FOR(i,0,n) FOR(c,0,26) occ[i][c]=0;
		FOR(r, l, m)
		{
			FOR(i,0,n)
				occ[i][grid[i][r]-'a']++;
			int lo(0);
			while (lo<n)
			{
				while(lo<n and !is_pal(occ[lo]))
					++lo;
				int up = lo;
				while(up<n and is_pal(occ[up]))
					++up;
				if(lo<n)
				{
					int ret = manacher(vector<array<int,26>>(occ.begin()+lo,occ.begin()+up));
					ans += ret;
				}
				lo=up+1;
			}
		}
	}
	pnl(ans);
}