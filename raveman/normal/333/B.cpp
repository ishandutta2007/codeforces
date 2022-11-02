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
bool a[1111][1111];

int main(){
#ifdef LocalHost
	freopen("input.txt","r",stdin);
#endif

	cin>>n>>m;
	REP(i,m){
		int x,y;
		scanf("%d %d",&x,&y);
		a[x-1][y-1]=1;
	}
	int res = 0;
	FOR(i,1,n/2){
		int gh1 = 1;
		int gh2 = 1;
		int gv1 = 1;
		int gv2 = 1;
		REP(j,n)if(a[i][j])gh1=0;
		REP(j,n)if(a[n-i-1][j])gh2=0;
		REP(j,n)if(a[j][i])gv1=0;
		REP(j,n)if(a[j][n-i-1])gv2=0;
		res+=gh1+gh2+gv1+gv2;
		/*if(gh1 && gh2)res+=2;
		else if(gv1 && gv2)res+=2;
		else if((gh1||gh2)&&(gv1||gv2)) res+=2;
		else if(gh1 || gv1 || gh2 || gv2)res++;*/
	}
	if(n%2==1){
		bool gh = 1;
		bool gv = 1;
		REP(i,n) if(a[n/2][i])gh=0;
		REP(i,n) if(a[i][n/2])gv=0;
		if(gh||gv)res++;
	}
	cout<<res<<endl;
#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}