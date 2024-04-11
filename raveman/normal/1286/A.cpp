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

int n;
int a[111];

int d[111][111][2];

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n;
	REP(i,n)cin>>a[i];

	CL(d,-1);

	if(a[0]==0 || a[0]%2==0)d[0][1][0]=0;
	if(a[0]==0 || a[0]%2==1)d[0][0][1]=0;

	REP(i,n-1)REP(j,n)REP(t,2)if(d[i][j][t]!=-1){
		// 0
		if(a[i+1]==0 || a[i+1]%2==0){
			int &z = d[i+1][j+1][0];
			if(z==-1 || z>d[i][j][t]+t){
				z=d[i][j][t]+t;
			}
		}
		// 1
		if(a[i+1]==0 || a[i+1]%2==1){
			int &z = d[i+1][j][1];	
			if(z==-1 || z>d[i][j][t]+1-t){
				z=d[i][j][t]+1-t;
			}
		}
	}
	int res=1000;
	REP(t,2)if(d[n-1][n/2][t]!=-1)res=min(res,d[n-1][n/2][t]);
	cout<<res<<endl;


#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}