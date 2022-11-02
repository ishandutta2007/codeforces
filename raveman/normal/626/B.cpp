#pragma comment(linker, "/STACK:60777216")  

#include <cassert>
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<complex>
#include<vector>
#include<set>
#include<map>
#include<cmath>
#include<queue>
#include<string>
#include<cstdlib>
#include<memory.h>
#include<ctime>
#include<bitset>
#include<fstream>
#include<queue>
#include<stack>

using namespace std;

typedef long double ld;

typedef long long ll;
typedef pair<int,int>	pii;
typedef pair<ld,ld>	pdd;
typedef vector<int> vi;
typedef vector<ld> vd;
typedef pair<ll,ll> pl;

#define FOR(i,a,b)		for(int i=(a);i<(b);i++)
#define REP(i,n)		FOR(i,0,n)
#define SORT(v)			sort((v).begin(),(v).end())
#define UN(v)			SORT(v),(v).erase(unique((v).begin(),(v).end()),(v).end())
#define CL(a,b)				memset(a,b,sizeof a)
#define pb				push_back

bool u[222][222][222];
void dfs(int a,int b,int c){
	if(u[a][b][c])return;
	u[a][b][c]=1;
	if(a>=2)dfs(a-1,b,c);
	if(b>=2)dfs(a,b-1,c);
	if(c>=2)dfs(a,b,c-1);
	if(a>=1&&b>=1)dfs(a-1,b-1,c+1);
	if(a>=1&&c>=1)dfs(a-1,b+1,c-1);
	if(b>=1&&c>=1)dfs(a+1,b-1,c-1);
}

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	int n;
	cin>>n;
	string s;
	cin>>s;
	int r=0,b=0,g=0;
	REP(i,n){
		if(s[i]=='B')b++;
		else if(s[i]=='G')g++;
		else r++;
	}
	dfs(r,b,g);
	if(u[0][1][0])printf("B");
	if(u[0][0][1])printf("G");
	if(u[1][0][0])printf("R");
	puts("");

#ifdef LocalHost
	//printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}