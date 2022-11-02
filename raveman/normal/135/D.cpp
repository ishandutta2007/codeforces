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

char s[1111][1111];
int n,m;
int best;

int now;
int v[1111][1111];

vector<pii> c;
bool u[1111][1111];

void dfs(int x,int y){
	if(u[x][y]) return;
	u[x][y]=true;
	
	
	FOR(dx,-1,2)FOR(dy,-1,2){
		int nx = dx + x;
		int ny = dy + y;
		if(nx>=0 && nx<n && ny>=0 && ny<m)
			if(s[nx][ny]=='0') dfs(nx,ny);
			else c.pb(pii(nx,ny));
		else c.pb(pii(-1,-1));
	}
}

int startx,starty;
int dfs2(int x,int y,int prevx=-1,int prevy=-1){
	if(x==startx && y==starty && prevx!=-1) return 0;
	int res = 1;
	FOR(dx,-1,2)FOR(dy,-1,2)if(abs(dx)+abs(dy)==1){
		int nx = x +dx;
		int ny = y + dy;
		if(nx>=0 && nx<n && ny>=0 && ny<m && v[nx][ny]==v[x][y])
			if(nx!=prevx || ny!=prevy){
				res += dfs2(nx,ny,x,y);


				if(prevx==-1) return res;
			}
	}
	return res;
}

int main(){
#ifdef LocalHost
    freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
#endif

	cin>>n>>m;
	REP(i,n) scanf(" %s",s[i]);
	FOR(i,1,n)FOR(j,1,m)if(s[i][j]=='1' && s[i][j-1]=='1' && s[i-1][j-1]=='1' && s[i-1][j]=='1') best = 4;
	REP(i,n)REP(j,m)if(s[i][j]=='0' && !u[i][j]){
		c.clear();
		dfs(i,j);
		now++;
		bool good = 1;
		int num=0;
		REP(k,c.size()) 
			if(c[k].first==-1) {good=0;break;}
			else if(v[c[k].first][c[k].second]!=now)
				v[c[k].first][c[k].second]=now,num++;
			
		REP(k,c.size()){
			int num = 0;
			FOR(dx,-1,2)FOR(dy,-1,2)if(abs(dx)+abs(dy)==1){
				int nx = c[k].first + dx;
				int ny = c[k].second + dy;
				if(nx>=0 && nx<n && ny>=0 && ny<m && s[nx][ny]=='1')
					if(v[nx][ny]==now)
						num++;
			}
			if(num!=2) {good=0;break;}
		}

		if(good && num>4){
			startx=c[0].first;
			starty=c[0].second;
			if(dfs2(c[0].first,c[0].second)==num) best = max(best, num);
		}
	}

	cout<<best<<endl;
	
#ifdef LocalHost
	cout<<endl<<endl<<"TIME: "<<clock()<<endl;
#endif
    return 0;
}