#include <bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define X first
#define Y second
#define debug(x) cerr << #x << ": " << x << endl;
#define ll long long int
#define endl '\n'
#define mp make_pair
#define pb push_back
#define rep(i,l,r) for (ll i=l; i<r; i++)
#define repr(i,r,l) for (int i=r; i>=l; i--)
using namespace std;
const long long int N=5e2+30,inf = 1e18;
bool visited[N][N];
vector <pair<char,pair<short int,short int> > > ans;
char c[N][N];
void d(int x,int y,int n,int m,pair<int,int> par){
    if (visited[x][y]) return;
	visited[x][y] = 1;
	bool f=0;
	if (x && !visited[x-1][y] && c[x-1][y] == '.'){
	 //   cout << x << "   " << y;
		if (!f) ans.pb({'B',{x+1,y+1}});
		f=1;
		d(x-1,y,n,m,{x,y});
	}
	if (y && !visited[x][y-1] && c[x][y-1] == '.'){
	    //cout << x << y;
		if (!f) ans.pb({'B',{x+1,y+1}});
		f=1;
		d(x,y-1,n,m,{x,y});
	}
	if (x < n-1 && !visited[x+1][y] && c[x+1][y] == '.'){
		if (!f) ans.pb({'B',{x+1,y+1}});
		f=1;
		d(x+1,y,n,m,{x,y});
	}
	if (y < m-1 && !visited[x][y+1] && c[x][y+1] == '.'){
		if (!f) ans.pb({'B',{x+1,y+1}});
		f=1;
		d(x,y+1,n,m,{x,y});
	}
	if (par.X != -1 && f){
		ans.pb({'D',{x+1,y+1}});
		ans.pb({'R',{x+1,y+1}});
	}
	if (par.X != -1 && !f){
		ans.pb({'R',{x+1,y+1}});
	}
	if (par.X == -1 && !f){
	    ans.pb({'B',{x+1,y+1}});
	}
}
int main(){
	int n,m;
	cin >> n >> m;
	rep(i,0,n){
		rep(j,0,m) cin >> c[i][j];
	}
	rep(x,0,n){
		rep(y,0,m){
			if (!visited[x][y] && c[x][y] == '.'){
				d(x,y,n,m,{-1,-1});
		//		dfs(x,y,{-1,-1});
			}
		}
	}
	cout << ans.size() << endl;
	for (auto u : ans){
	    cout << u.X << ' ' << u.Y.X << ' ' << u.Y.Y << endl;
	}
}