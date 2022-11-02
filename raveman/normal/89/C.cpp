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

int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};

int n,m;
string s[5555];

int getD(int x,int y){
	REP(i,4) if(s[x][y]=="UDLR"[i]) return i;
	return 0;
}

int now;
int u[5555][5555];
vector<vi> v[4];

int getLen(int x,int y,int d){
	if(u[x][y]!=now && s[x][y]!='.') return 0;
	int curr = v[d][x][y];
	int nx = x + curr * dx[d];
	int ny = y + curr * dy[d];
	if(nx<0 || nx>=n || ny<0 || ny>=m) return curr;
	return v[d][x][y] += getLen(nx,ny,d);
}

int dfs(int x,int y){
	u[x][y]=now;
	int d = getD(x,y);
	int len = getLen(x,y,d);
	int nx = x + len * dx[d];
	int ny = y + len * dy[d];
	if(nx<0 || nx>=n || ny<0 || ny>=m) return 1;
	return 1+dfs(nx,ny);
}

int calc(int x,int y){
	now++;
	REP(i,4){
		v[i].resize(n);
		REP(j,n){
			v[i][j].resize(m);
			REP(k,m) v[i][j][k] = 1;
		}
	}
	return dfs(x,y);
}

int main(){ 
#ifdef LocalHost
	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
#endif
	cin>>n>>m;
	REP(i,n)
		cin>>s[i];
	
	int best = 0,num =0 ;
	REP(i,n)REP(j,m)if(s[i][j]!='.'){
		int val = calc(i,j);
		if(val>best) best=val,num=0;
		if(val==best) num++;
		//if(val==10) cout<<i<<' '<<j<<endl;
	}

	cout<<best<<' '<<num<<endl;

#ifdef LocalHost
	cout<<endl<<endl<<"TIME: "<<clock()<<endl;
#endif
	return 0;
}