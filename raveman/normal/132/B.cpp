#pragma comment(linker, "/STACK:65777216")
 
#include <algorithm>
#include <iostream>
#include <string>
#include<sstream>
#include<string.h>
#include <cstdio>
#include <vector>
#include <bitset>
#include <cmath>
#include <queue>
#include<stack>
#include <set>
#include <map>
#include<ctime>
 
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef unsigned long long ull;
 
#define FOR(i,a,b) for (int i(a); i < (b); i++)
#define REP(i,n) FOR(i,0,n)
#define SORT(v) sort((v).begin(),(v).end())
#define UN(v) sort((v).begin(),(v).end()),v.erase(unique(v.begin(),v.end()),v.end())
#define CL(a,b) memset(a,b,sizeof(a))
#define pb push_back

int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};

int n,m,t;
char s[55][55];
int c[55][55];
char color[55*55];
int per[55*55][5][5];

void dfs(int x,int y,int comp){
	if(c[x][y]!=-1) return;
	c[x][y]=comp;
	FOR(dx,-1,2)FOR(dy,-1,2)if(abs(dx)+abs(dy)==1){
		int nx = x + dx;
		int ny = y + dy;
		if(nx>=0 && nx<n && ny>=0 && ny<m && s[nx][ny]==s[x][y])
			dfs(nx,ny,comp);
	}
}

bool parsed[55*55];

int main(){
#ifdef LocalHost

    freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
#endif

	cin>>n>>t;
	REP(i,n) cin>>s[i],m=strlen(s[i]);
	int comp=0;
	CL(c,-1);
	REP(i,n)REP(j,m) if(s[i][j]!='0' && c[i][j]==-1){
		color[comp]=s[i][j];
		dfs(i,j,comp);
		comp++;
	}
	CL(per,-1);

	REP(i,n)REP(j,m)if(c[i][j]!=-1 && !parsed[c[i][j]]){
		parsed[c[i][j]]=1;

		REP(dp,4)REP(bc,4){
			int x = i, y = j;
			while(1){
				int nx = x + dx[dp];
				int ny = y + dy[dp];
				if(nx<0 || nx>=n || ny<0 || ny>=m || s[nx][ny]!=s[x][y]) break;
				x = nx, y = ny;
			}

			while(1){
				int nx = x + dx[bc];
				int ny = y + dy[bc];
				if(nx<0 || nx>=n || ny<0 || ny>=m || s[nx][ny]!=s[x][y]) break;
				x = nx, y = ny;
			}

			x = x + dx[dp];
			y = y + dy[dp];

			if(x>=0 && x<n && y>=0 && y<m && s[x][y]!='0'){
				per[c[i][j]][dp][bc] = c[x][y];
			}
		}
	}

	int bpointer = 0;
	int dpointer = 0;
	int bchooser = 3;

	for(;t;t--){
		int val = per[bpointer][dpointer][bchooser];
		if(val==-1){
			if(bchooser == (dpointer+3)%4) bchooser = (dpointer+1)%4;
			else{
				dpointer = (dpointer+1)%4;
				bchooser = (dpointer+3)%4;
			}
		}else{
			bpointer = val;
		}
	}

	cout<<color[bpointer]<<endl;
	
#ifdef LocalHost
    cout<<endl<<endl<<"TIME: "<<clock()<<endl;
#endif
    return 0;
}