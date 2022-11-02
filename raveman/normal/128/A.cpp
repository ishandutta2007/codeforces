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
 
string s[10][10];
bool u[10][10][10];

bool dfs(int x,int y,int st=0){
	if(st>=9 || x==0 && y==7) return true;
	//cout<<x<<' '<<y<<' '<<st<<endl;
	if(u[x][y][st]) return false;
	u[x][y][st]=true;
	FOR(dx,-1,2)FOR(dy,-1,2){
		int nx = x + dx;
		int ny = y + dy;
		if(nx>=0 && nx<8 && ny>=0 && ny<8){
			if(s[st+1][nx][ny]!='S' && s[st][nx][ny]!='S')
				if(dfs(nx,ny,st+1))
					return 1;
		}
	}
	return 0;
}

int main(){
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif
	
	REP(i,8) cin>>s[0][i];
	s[0][0][7]='.';
	s[0][7][0]='.';
	FOR(i,1,10){
		s[i][0]="........";
		FOR(x,1,8)REP(y,8){
			s[i][x].pb(s[i-1][x-1][y]);
		}
		//cout<<s[1][7]<<endl;
	}
	puts(dfs(7,0)?"WIN":"LOSE");
	 
#ifdef LocalHost
	cout<<endl<<endl<<"TIME: "<<clock()<<endl;
#endif
	return 0;
}