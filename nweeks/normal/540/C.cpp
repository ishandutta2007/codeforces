#include<bits/stdc++.h>

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define pb push_back
#define mp make_pair
#define eps 1e-9
#define PI  3.14159265358979323846
#define ACCEPTED return 0;
#define name "tusu"
		
using namespace std;

int r1, c1, n, m, r, c;
bool vis[501][501]={false}, res=false;

char a[501][501];

void DFS(int x, int y){
	if(x<0 || y<0 || x>=n || y>=m) return;
	if(x==r1 && y==c1){
		int cnt=0;
		if(x>0 && a[x-1][y] == '.'){
			cnt++;
		}
		if(y>0 && a[x][y-1]=='.'){
			cnt++;
		}
		if(y+1<m &&  a[x][y+1]=='.'){
			cnt++;
		}
		if(x+1<n &&  a[x+1][y]=='.'){
			cnt++;
		}
		if(a[x][y]=='.' and abs(r1 - r) + abs(c1 - c) > 1){
			if(cnt>=2) res=true;
		}
		else if (a[x][y] == 'X' and cnt >= 1 ) res=true;	
		return;
	}
	vis[x][y]=true;
	if(a[x][y]=='X' && (r!=x || c!=y)){
		return ;
	}
	else{
		if(x>0 && vis[x-1][y]==false){
			DFS(x-1, y);
		}
		if(y>0 && vis[x][y-1]==false){
			DFS(x, y-1);
		}
		if(y+1<m && vis[x][y+1]==false){
			DFS(x, y+1);
		}
		if(x+1<n && vis[x+1][y]==false){
			DFS(x+1, y);
		}		
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	string s; 
	for(int i=0; i<n; i++)
		for (int j=0; j<m; ++j)
			cin >> a[i][j];
	cin >> r >> c >> r1 >> c1;
	r--, c--, r1--, c1--;
	if (abs(r-r1) + abs(c-c1) == 1 )
	{
		if (a[r1][c1] == 'X')
			cout << "YES" << endl;
		else if (r1 > 0 and a[r1-1][c1]=='.')
			cout << "YES" << endl;
		else if (c1 > 0 and a[r1][c1-1] == '.')
			cout << "YES" << endl;
		else if (r1+1 < n and a[r1+1][c1] == '.')
			cout << "YES" << endl;
		else if (c1 + 1 < m and a[r1][c1+1] == '.')
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
		return 0;
	}
	
	DFS(r, c);
	cout << (res==true ? "YES" : "NO");
	return 0;
}