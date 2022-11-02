#include <bits/stdc++.h>

#define fi first
#define se second
#define db double
#define U unsigned
#define P std::pair<int,int>
#define LL long long
#define pb push_back
#define MP std::make_pair
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 300 + 5;
const int MAXM = 2e6 + 5;
int c[MAXN][MAXN];
int n,m,q;
const int dx[] = {0,0,1,-1};
const int dy[] = {1,-1,0,0};
int f[MAXM<<1],N,ans[MAXM];

struct Node{
	int x,y,c;
	Node(int x=0,int y=0,int c=0) : x(x),y(y),c(c) {}
}a[MAXM];

int id[MAXN][MAXN],tot;

inline int find(int x){
	return x == f[x] ? x : f[x] = find(f[x]);
}

inline bool merge(int x,int y){
	x = find(x);y = find(y);
	if(x == y) return 0;
	f[x] = y;return 1;
}

int main(){
	scanf("%d%d%d",&n,&m,&q);
	FOR(i,1,q) scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].c);
	tot = 0;FOR(i,1,n) FOR(j,1,m) id[i][j] = ++tot,f[tot] = tot;
	FOR(i,1,q){
		int x = a[i].x,y = a[i].y,z = a[i].c;
		if(c[x][y] == z){a[i] = Node(x,y,z);continue;}
		id[x][y] = ++tot;f[tot] = tot;a[i] = Node(x,y,c[x][y]);c[x][y] = z;
		int t = 0;
		FOR(k,0,3){
			int xx = x+dx[k],yy = y+dy[k];
			if(xx >= 1 && xx <= n && yy >= 1 && yy <= m && c[xx][yy] == c[x][y]){
				t += merge(id[x][y],id[xx][yy]);
			}
		}
		ans[i] = 1-t;
	}
	tot = 0;FOR(i,1,n) FOR(j,1,m) id[i][j] = ++tot,f[tot] = tot;
	FOR(i,1,n) FOR(j,1,m) FOR(k,0,3){
		int ii = i+dx[k],jj = j+dy[k];
		if(ii >= 1 && ii <= n && jj >= 1 && jj <= m && c[ii][jj] == c[i][j]){
			merge(id[ii][jj],id[i][j]);
		}
	}
	ROF(i,q,1){
		int x = a[i].x,y = a[i].y,z = a[i].c;
		if(c[x][y] == z) continue;
		id[x][y] = ++tot;f[tot] = tot;c[x][y] = z;
		int t = 0;
		FOR(k,0,3){
			int xx = x+dx[k],yy = y+dy[k];
			if(xx >= 1 && xx <= n && yy >= 1 && yy <= m && c[xx][yy] == c[x][y]){
				t += merge(id[x][y],id[xx][yy]);
			}
		}
		ans[i] += t-1;
	}
	ans[0] = 1;FOR(i,1,q) ans[i] += ans[i-1],printf("%d\n",ans[i]);puts("");
	return 0;
}