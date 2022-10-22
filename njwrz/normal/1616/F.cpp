#include<bits/stdc++.h>
#define ll long long
#define gmax(x,y) x=max(x,y)
#define gmin(x,y) x=min(x,y)
#define F first
#define S second
#define P pair
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define V vector
#define RE return
#define ALL(a) a.begin(),a.end()
#define MP make_pair
#define PB emplace_back
#define PF emplace_front
#define FILL(a,b) memset(a,b,sizeof(a))
#define lwb lower_bound
#define upb upper_bound
#define lc (x<<1)
#define rc ((x<<1)^1)
#define y1 yyyy1111
using namespace std;
struct data {
	bitset<260> s1, s2;
	int num;
	void clear() {
		s1.reset();
		s2.reset();
		num = 0;
	}
} p[3005];
int n, m;
int col[70][70],pos[70][70],tc[70][70];
P<int, int> ed[300];
bitset<260> to[3], it[3], now;
bitset<260> full;
void mi(int i, int j,int k) {
	int t = (p[i].s1[k] == 1) ? 1 : 2;
	to[0] = full ^ p[i].s1 ^ p[i].s2;
	to[1] = p[i].s1;
	to[2] = p[i].s2;
	int t2 = (p[j].s1[k] == 1) ? 1 : 2;
	it[0] = full ^ p[j].s1 ^ p[j].s2;
	it[1] = p[j].s1;
	it[2] = p[j].s2;
	p[j].s1.reset();
	p[j].s2.reset();
	if (t == t2) {
		p[j].num -= p[i].num;
		p[j].num = (p[j].num % 3 + 3) % 3;
		FOR(i1, 0, 2) {
			FOR(j1, 0, 2)if (i1 != j1) {
				now = to[i1] & it[j1];
				if ((i1 + 1) % 3 == j1) {
					p[j].s1 |= now;
				} else p[j].s2 |= now;
			}
		}
	} else {
		p[j].num -= 2 * p[i].num;
		p[j].num = (p[j].num % 3 + 3) % 3;
		FOR(i1, 0, 2) {
			FOR(j1, 0, 2)if ((j1 - 2 * i1) % 3 != 0) {
				now = to[i1] & it[j1];
				if ((j1 - 2 * i1 + 6) % 3 == 2) {
					p[j].s2 |= now;
				} else p[j].s1 |= now;
			}
		}
	}
}
void solve() {
	FILL(col, 0);FILL(tc,0);
	cin >> n >> m;
	int cnt = 0;
	full.reset();
	FOR(i, 1, m) {
		full[i] = 1;
		int x, y, z;
		cin >> x >> y >> z;
		col[x][y] = col[y][x] = z;
		tc[x][y]=tc[y][x]=z;
		ed[i] = MP(x, y);
		pos[x][y]=pos[y][x]=i;
		if (z != -1) {
			cnt++;
			p[cnt].clear();
			p[cnt].s1[i] = 1;
			p[cnt].num = z % 3;
		}
	}
	FOR(i, 1, m) {
		FOR(j, max(ed[i].F+1,ed[i].S+1), n){
			if (col[ed[i].F][j] != 0 && col[ed[i].S][j] != 0) {
				cnt++;
				p[cnt].clear();
				p[cnt].s1[i] = 1;
				p[cnt].s1[pos[ed[i].F][j]] = 1;
				p[cnt].s1[pos[ed[i].S][j]] = 1;
				p[cnt].num = 0;
			}
		}
	}
	FOR(i, 1, m) {
		int it = 0;
		FOR(j, i, cnt) {
			if (p[j].s1[i] || p[j].s2[i]) {
				it = j;
				break;
			}
		}
		if (!it) {
			cnt++;
			p[cnt].clear();
			p[cnt].s1[i] = 1;
			p[cnt].num = 0;
			it = cnt;
		}
		swap(p[i], p[it]);
		FOR(j, i + 1, cnt)if (p[j].s1[i] || p[j].s2[i]) {
			mi(i, j,i);
		}
	}
	for(int i=m;i>=1;i--){
		rep(j,1,i)if(p[j].s1[i]||p[j].s2[i])mi(i,j,i);
		int t=(p[i].s1[i]==1)?1:2;
		int ts=p[i].num*t%3;
		if(ts==0)ts=3;
		col[ed[i].F][ed[i].S]=ts;
		col[ed[i].S][ed[i].F]=ts;
//		cout<<ts<<'\n';
	}
	FOR(i,1,m)if(tc[ed[i].F][ed[i].S]!=-1&&tc[ed[i].F][ed[i].S]!=col[ed[i].F][ed[i].S]){
		cout<<-1<<'\n';RE ;
	}
	FOR(i, 1, m) {
		FOR(j, 1, n)if (j != ed[i].F && j != ed[i].S) {
			if (col[ed[i].F][j] != 0 && col[ed[i].S][j] != 0) {
				if((col[ed[i].F][j]+col[ed[i].S][j]+col[ed[i].F][ed[i].S])%3!=0){
					cout<<-1<<'\n';
					RE;
				}
			}
		}
	}
	FOR(i,1,m)cout<<col[ed[i].F][ed[i].S]<<' ';
	cout<<'\n';
}
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--)solve();
	RE 0;
}