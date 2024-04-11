#pragma comment(linker, "/STACK:60777216")  

#include <cassert>
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<complex>
#include<vector>
#include<cstring>
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
#include<unordered_map>
#include<unordered_set>

using namespace std;

typedef long double ld;

typedef long long ll;
typedef pair<int,int>	pii;
typedef pair<double,double>	pdd;
typedef vector<int> vi;
typedef vector<ld> vd;
typedef pair<ll,ll> pl;

#define FOR(i,a,b)		for(int i=(a);i<(b);i++)	
#define REP(i,n)		FOR(i,0,n)
#define SORT(v)			sort((v).begin(),(v).end())
#define UN(v)			SORT(v),(v).erase(unique((v).begin(),(v).end()),(v).end())
#define CL(a,b)			memset(a,b,sizeof a)
#define pb				push_back

int r,c;
string s[66];


bool alla(int x,int y,int dx,int dy){
	while(x>=0 && x<r && y>=0 && y<c){
		if(s[x][y]!='A')return 0;
		x+=dx;
		y+=dy;
	}
	return 1;
}

bool anya(int x,int y,int dx,int dy){
	while(x>=0 && x<r && y>=0 && y<c){
		if(s[x][y]=='A')return 1;
		x+=dx;
		y+=dy;
	}
	return 0;
}

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	int tc;
	cin>>tc;
	REP(TC,tc){
		cin>>r>>c;
		REP(i,r){
			char _w[111];
			scanf("%s",_w);
			s[i]=_w;
		}

		int hasa=0;
		REP(i,r)REP(j,c)if(s[i][j]=='A')hasa++;
		if(!hasa){puts("MORTAL");continue;}
		if(hasa==r*c){puts("0");continue;}

		int res=4;

		//3
		if(anya(0,0,1,0) || anya(0,0,0,1) || anya(r-1,c-1,0,-1) ||anya(r-1,c-1,-1,0))res=3;
		
		//2
		REP(i,r)if(alla(i,0,0,1))res=2;
		REP(i,c)if(alla(0,i,1,0))res=2;
		if(s[0][0]=='A' || s[0][c-1]=='A' || s[r-1][0]=='A' || s[r-1][c-1]=='A')res=2;

		//1
		if(alla(0,0,1,0) || alla(0,0,0,1) || alla(r-1,c-1,0,-1) || alla(r-1,c-1,-1,0))res=1;
		
		cout<<res<<endl;
	}

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}