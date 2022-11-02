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

const int MAXN = 400+5;
const int MAX = 155;
bool vis[MAXN][MAXN][35][8];
bool ans[MAXN][MAXN];
int n,t[MAXN];

struct Node{
	int x,y,d,dep;
	Node(int x=0,int y=0,int d=0,int dep=0) : x(x),y(y),d(d),dep(dep) {}
};

std::queue<Node> q;
const int dx[] = {0,-1,-1,-1,0,1,1,1};
const int dy[] = {1,1,0,-1,-1,-1,0,1};

int main(){
	scanf("%d",&n);//n = 2;
	FOR(i,1,n) scanf("%d",t+i);t[1]--;
	q.push(Node(MAX,MAX,0,1));ans[MAX][MAX] = 1;
	while(!q.empty()){
		Node v = q.front();q.pop();
		if(vis[v.x][v.y][v.dep][v.d]) continue;
		if(v.dep > n) continue;
		vis[v.x][v.y][v.dep][v.d] = 1;
		int xx = v.x,yy = v.y,dx = ::dx[v.d],dy = ::dy[v.d];
		// DEBUG(v.dep);
		FOR(i,1,t[v.dep]){
			xx += dx;yy += dy;
			ans[xx][yy] = 1;
		}
		if(v.dep == n) continue;
		q.push(Node(xx,yy,(v.d+1)%8,v.dep+1));
		q.push(Node(xx,yy,(v.d+7)%8,v.dep+1));
	}
	int res = 0;
	FOR(i,0,MAXN-1) FOR(j,0,MAXN-1) res += ans[i][j];
	printf("%d\n",res);
	return 0;
}