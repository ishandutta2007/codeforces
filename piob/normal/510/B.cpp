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

int n, m;
char buff[53][53];
bool vis[53][53];

bool dfs(int x, int y, int px, int py){
	vis[x][y] = 1;
	FWD(k,0,4){
		int nx = x + dx[k];
		int ny = y + dy[k];
		if(px == nx && py == ny) continue;
		if(nx < 0 || nx >= n) continue;
		if(ny < 0 || ny >= m) continue;
		if(buff[nx][ny] == buff[x][y]){
			if(vis[nx][ny]) return 1;
			if(dfs(nx,ny,x,y)) return 1;
		}
	}
	return 0;
}

int main(){
	scanf("%d %d", &n, &m);
	FWD(i,0,n) scanf("%s", buff[i]);
	FWD(i,0,n) FWD(j,0,m) if(!vis[i][j]){
		if(dfs(i,j,-1,-1)){
			printf("Yes\n");
			return 0;
		}
	}
	printf("No\n");
	return 0;
}