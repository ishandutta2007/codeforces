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
#define CL(a,b)			memset(a,b,sizeof a)
#define pb				push_back

int n,m;
bool u[555][555];
int col[555];

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n>>m;
	REP(i,m){
		int x,y;
		scanf("%d %d",&x,&y);
		x--,y--;
		u[x][y]=u[y][x]=1;
	}
	CL(col,-1);
	vi b,a,c,t;
	REP(i,n){
		bool ca = true;
		REP(j,n)if(i!=j && !u[i][j])ca=false;
		if(ca)col[i]=1;
	}

	REP(i,n)if(col[i]==-1){
		REP(j,n)if(col[j]==-1 && (i==j || u[i][j]))col[j]=0;
		break;
	}
	REP(i,n)if(col[i]==-1)col[i]=2;
	bool good = true;
	REP(i,n)REP(j,n)if(i!=j){
		if(abs(col[i]-col[j])<=1){
			if(!u[i][j])good=false;
		}else{
			if(u[i][j])good=false;
		}
	}
	if(good){
		puts("Yes");
		REP(i,n)printf("%c","abc"[col[i]]);
		puts("");
	}else{
		puts("No");
	}


#ifdef LocalHost
	//printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}