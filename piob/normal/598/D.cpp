#include <bits/stdc++.h>
#define REP(a,b) for(int a=0; a<(b); ++a)
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define FWDS(a,b,c,d) for(int a=(b); a<(c); a+=d)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define ALL(a) (a).begin(), (a).end()
#define SIZE(a) ((int)(a).size())
#define VAR(x) #x ": " << x << " "
#define popcount __builtin_popcount
#define popcountll __builtin_popcountll
#define gcd __gcd
#define x first
#define y second
#define st first
#define nd second
#define pb push_back

using namespace std;

template<typename T> ostream& operator<<(ostream &out, const vector<T> &v){ out << "{"; for(const T &a : v) out << a << ", "; out << "}"; return out; }
template<typename S, typename T> ostream& operator<<(ostream &out, const pair<S,T> &p){ out << "(" << p.st << ", " << p.nd << ")"; return out; }

typedef long long LL;
typedef pair<int, int> PII;
typedef long double K;
typedef vector<int> VI;

const int dx[] = {0,0,-1,1}; //1,1,-1,1};
const int dy[] = {-1,1,0,0}; //1,-1,1,-1};

const int mod = 1000000007;

const K M_PI = acos(-1);

int n, m, q;
char mp[1010][1010];
int id[1010][1010];
int cur, ps;
int res[1010*1010];

void dfs(int x, int y){
	id[x][y] = ps;
	FWD(d,0,4){
		int nx = x + dx[d];
		int ny = y + dy[d];
		if(mp[nx][ny] == '*')
			++cur;
		else if(id[nx][ny] == 0)
			dfs(nx, ny);
	}
}

int main(){
	scanf("%d %d %d", &n, &m, &q);
	FWD(i,0,n) scanf("%s", mp[i]);
	FWD(i,0,n)
		FWD(j,0,m)
			if(id[i][j] == 0 && mp[i][j] == '.'){
				++ps;
				cur = 0;
				dfs(i, j);
				res[ps] = cur;
			}
	FWD(i,0,q){
		int x, y;
		scanf("%d %d", &x, &y);
		printf("%d\n", res[id[x-1][y-1]]);
	}
	return 0;
}