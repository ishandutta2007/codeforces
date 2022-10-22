#include <bits/stdc++.h>
using namespace std;
 
typedef pair<int,int> P;
int num[1000];
P nt[1000][2520];
vector<int> adj[1000];
int p[1000];
int deg[1000][2520];
int cycle[1000][2520];
bool visited[1000][2520];
int n;
bool rv[1000][2520];
 
int ans(int x,int y) {
    if (cycle[x][y]!=-1) {
        return cycle[x][y];
    }
    int sx=x;
    int sy=y;
    while (1) {
        if (visited[x][y]) {
            set<int> s;
            int cnt=0;
            int cx=x;
            int cy=y;
            while (cnt==0||x!=cx||y!=cy) {
                s.insert(x);
                int nx=nt[x][y].first;
                int ny=nt[x][y].second;
                x=nx;
                y=ny;
                cnt++;
            }
            int sz=s.size();
            x=sx;
            y=sy;
            while (cycle[x][y]==-1) {
                visited[x][y]=false;
                cycle[x][y]=sz;
                int nx=nt[x][y].first;
                int ny=nt[x][y].second;
                x=nx;
                y=ny;
            }
            return cycle[sx][sy];
        }
        if (cycle[x][y]!=-1) {
            int ex=x;
            int ey=y;
            x=sx;
            y=sy;
            while (x!=ex||y!=ey) {
                visited[x][y]=false;
                cycle[x][y]=cycle[ex][ey];
                int nx=nt[x][y].first;
                int ny=nt[x][y].second;
                x=nx;
                y=ny;
            }
            return cycle[sx][sy];
        }
        visited[x][y]=true;
        int nx=nt[x][y].first;
        int ny=nt[x][y].second;
        x=nx;
        y=ny;
    }
}
 
int main(void) {
    memset(cycle,-1,sizeof(cycle));
	scanf("%d\n",&n);
	for(int i=0;i<n;i++) {
		scanf("%d ",&p[i]);
		p[i]%=2520;
		if (p[i]<0) {
			p[i]+=2520;
		}
	}
	scanf("\n");
	for(int i=0;i<n;i++) {
		scanf("%d\n",&num[i]);
		for(int j=0;j<num[i];j++) {
			int x;
			scanf("%d ",&x);
			x--;
			adj[i].push_back(x);
		}
		scanf("\n");
	}
	for(int i=0;i<n;i++) {
		for(int j=0;j<2520;j++) {
			nt[i][j]=P(adj[i][(j+p[i])%num[i]],(j+p[i])%2520);
			deg[adj[i][(j+p[i])%num[i]]][(j+p[i])%2520]++;
		}
	}
	int q;
	scanf("%d\n",&q);
	for(int i=0;i<q;i++) {
		int x,y;
		scanf("%d %d\n",&x,&y);
		x--;
		y%=2520;
		if (y<0) {
			y+=2520;
		}
		printf("%d\n",ans(x,y));
	}
}