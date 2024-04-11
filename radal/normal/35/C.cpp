#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define X first
#define Y second
#define debug(x) cerr << #x << ": " << x << endl;
#define endl '\n'
#define pb push_back
#define mp make_pair
#define rep(i,l,r) for (int i=l; i<r; i++)
#define repr(i,r,l) for (int i=r; i>=l; i--)

using namespace std;

typedef long long  int ll;
typedef pair<int,int> pll;

const long long int N=2e3+30,mod = 1e9+7,inf=1e18;
const long double eps = 0.0001;
int k,n,m;
int dist[N][N];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
vector <pll> root;
void bfs(){
    queue <pll> q;
    for (auto u :  root){
    	dist[u.X][u.Y] = 1;
    	q.push(u);
	}
    while (!q.empty()){
    	pll p = q.front();
    	q.pop();
    	rep(i,0,4){
    		int a,b;
    		a = p.X + dx[i];
    		b = p.Y + dy[i];
    		if (a > 0 && b > 0 && a <= n && b <= m && !dist[a][b]){
    			dist[a][b] = dist[p.X][p.Y]+1;
    			q.push({a,b});
			}
		}
    }
    return;
}
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	cin >> n >> m >> k;
	rep(i,0,k){
		int x,y;
		cin >> x >> y;
		root.pb({x,y});
	}
	bfs();
	int mx = 0,x,y;
	rep(i,1,n+1){
		rep(j,1,m+1){
			if (dist[i][j] > mx){
				mx = dist[i][j];
				x = i;
				y = j;
			}
		}
	}
	cout << x << ' ' << y << endl;
    return 0;
}