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

int n,m;
string s[155];
bool has[155];
int  m_l[155],m_r[155];

int d[155][155][2][2][2];

int solve(int x,int y,int dir,int s_l,int s_r){
	if(x+1==n && s_l && s_r) return 0;
	if(d[x][y][dir][s_l][s_r]!=-1) return d[x][y][dir][s_l][s_r];
	
	int val = 1000000000;
	int ny = y + (dir==0?1:-1);
	if(ny<m && ny>=0) val = min(val, 1 + solve(x, ny, dir, s_l || (m_l[x] == ny), s_r || (m_r[x] == ny)));
	if(s_l && s_r)
		val = min(val,1+solve(x+1,y,1-dir,!has[x+1] || y==m_l[x+1],!has[x+1] || y==m_r[x+1]));
	
	
	return d[x][y][dir][s_l][s_r] = val;
}

int main(){ 

#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif
	
	CL(d,-1);
	cin>>n>>m;
	int last_row = -1;
	REP(i,n){
		cin>>s[i];
		REP(j,m){
			if(s[i][j]=='W'){
				last_row = i;
				if(!has[i]) m_l[i] = j;
				has[i] = true;
				m_r[i] = j;
			}
		}
	}
	if(last_row==-1) puts("0");
	else{
		n = last_row + 1;
		cout<<solve(0,0,0,has[0]?0:1,has[0]?0:1)<<endl;
	}

#ifdef LocalHost
	cout<<endl<<endl<<"TIME: "<<clock()<<endl;
#endif
	return 0;
}