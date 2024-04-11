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

int n,m;
int a[555][555];
int b[555][555];

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n>>m;
	REP(i,n)REP(j,m)scanf("%d",&a[i][j]);
	REP(i,n)REP(j,m)scanf("%d",&b[i][j]);

	REP(i,n-1)REP(j,m-1)if(a[i][j]!=b[i][j]){
		a[i][j]^=1;
		a[i+1][j]^=1;
		a[i][j+1]^=1;
		a[i+1][j+1]^=1;
	}
	bool g = 1;
	REP(i,n)REP(j,m)if(a[i][j]!=b[i][j])g=0;
	puts(g?"Yes":"No");
	return 0;
	cin>>n;
	REP(i,n)scanf("%d",a+i);

	ll res = 0;
	cout<<res<<endl;
	
#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}