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

int n, m, q;

char s[1010][1010];

int cn[1010][1010];
int cnn;

int ct0[1000*1000+10];
int cc[1000*1000+10];

int dx[5] = {0, 1, 0, -1};
int *dy = dx+1;

int nowtime;

queue<pp> cand;
bitset<1010> cchk[1010];

void w(int i, int j)
{
	if (cn[i][j]) return;
	queue<pp> q;
	++cnn;
	q.emplace(i, j);
	cn[i][j] = cnn;
	ct0[cnn] = nowtime; cc[cnn] = s[i][j];
	while (q.size()) {
		int x, y; tie(x, y) = q.front(); q.pop();
		rep(i, 4) {
			int nx = x+dx[i];
			int ny = y+dy[i];
			if (!(1<=nx && 1<=ny && nx<=n && ny<=m)) continue;
			if (cn[nx][ny]) continue;
			if (s[nx][ny] == s[x][y]) {
				cn[nx][ny] = cnn;
				q.emplace(nx, ny);
			} else if (!cchk[nx][ny]) {
				cchk[nx][ny] = 1;
				cand.emplace(nx, ny);
			}
		}
	}
}

int main()
{
	cppio();
	cin >> n >> m >> q;
	rrep(i, n) {
		cin >> (s[i]+1);
		rrep(j, m) s[i][j] -= '0';
	}

	rrep(i, n) rrep(j, m) if (!cn[i][j]) {
		if (i<n && s[i][j] == s[i+1][j]) {
			w(i, j);
		} else if (j<m && s[i][j] == s[i][j+1]) {
			w(i, j);
		}
	}

	while (cand.size()) {
		++nowtime;
		queue<pp> tmp; swap(cand, tmp);
		while(tmp.size()) {
			pp t = tmp.front(); tmp.pop();
			w(t.x, t.y);
		}
	}

	for(;q--;) {
		int x, y;
		ll tm;
		cin >> x >> y >> tm;
		int c = cn[x][y];
		if (!c || tm < ct0[c]) {
			cout << int(s[x][y]) << '\n';
		} else {
			cout << (cc[c] ^ ((tm ^ ct0[c])&1)) << '\n';
		}
	}

	return 0;
}