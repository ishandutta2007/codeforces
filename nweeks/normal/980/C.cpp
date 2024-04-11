#include <bits/stdc++.h>
using namespace std;

#define FOR(i, j, n) for (int i(j); i < n; ++i)
#define FORR(v, c) for (auto &v : c)
#define F first
#define S second
#define SQ(x) (x)*(x)
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define dbg(x) cerr<<#x<<" = " << (x) << endl
#define pnl(x) cout << x << '\n'
#define pns(x) cout << x << ' '
#define read(x) cin >> x
#define read2(x,y) cin >> x >> y
#define read3(x, y, z) cin >> x >> y >> z
#define read4(a, b, c, d) cin >> a >> b >> c >> d
#define readv(v) FORR(c,v) read(c)

struct Arrete { int v, c;};
struct Point {int x, y; double distance(Point other) const {return sqrt(SQ(x-other.x)+SQ(y-other.y));}};

typedef	vector<int>	vi;
typedef pair<int,int>	ii;
typedef vector<string>	vs;
typedef vector<ii>	vii;
typedef vector<Arrete>	vg;
typedef vector<long long>	vl;
typedef	long long ll;

const int	NB_D = 4;
const int	DY[] = {-1, 1, 0, 0};
const int	DX[] = {0, 0, -1, 1};

const int MAXN = 1e5;
const int MAXC = 256;
int arr[MAXN];
int N, K;

int group[MAXC];

int		main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	read2(N, K);
	fill(group, group + MAXC, -1);

	FOR(i,0,N)
		read(arr[i]);


	for (int i(0); i < N; ++i)
	{
		if (group[arr[i]] != -1)
		{
			arr[i] = group[arr[i]];
			continue ;
		}

		for (int j(max(0, arr[i] - K + 1));; ++j)
			if (group[j] == -1 or group[j] == j)
			{
				for (int k(j); k <= arr[i]; ++k)
					group[k] = j;
				arr[i] = j;
				break ;
			}
	}

	FOR(i,0,N)
		pns(arr[i]);
	cout << endl;
}