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

int n,k;
int a[333333];
ll  d[5005][5005];

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n>>k;
	REP(i,n)scanf("%d",a+i);
	sort(a,a+n);
	
	CL(d,-1);
	d[0][0]=0;
	for(int i=0;i<k;i++){
		for(int j=0;j<=i;j++)if(d[i][j]!=-1){
			int pos = n/k*i+j;
			//d[i][j] -> d[i+1][j];
			if (d[i+1][j]==-1 || d[i+1][j]> d[i][j]+a[pos+n/k-1]-a[pos])d[i+1][j]=d[i][j]+a[pos+n/k-1]-a[pos];
			//d[i][j] -> d[i+1][j+1];
			if (d[i+1][j+1]==-1 || d[i+1][j+1]> d[i][j]+a[pos+n/k]-a[pos])d[i+1][j+1]=d[i][j]+a[pos+n/k]-a[pos];
		}
	}

	cout<<d[k][n%k]<<endl;

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}