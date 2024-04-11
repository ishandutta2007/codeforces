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

bool u[11111*50];
int n,dd;
int c[55];
int d[11111*50];

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n>>dd;
	u[0]=true;
	REP(i,n){
		cin>>c[i];
		for(int j=11111*50-1;j>=c[i];j--)if(u[j-c[i]])u[j]=true;
	}
	CL(d,-1);
	d[0]=0;
	int best = 0;
	while(1){
		bool found = 0;
		int lst=-1;
		for(int j=best+1;j<=best+dd;j++)if(j<11111*50 && u[j]){
			found=true;
			d[j]=d[best]+1;
			lst=j;
		}
		if(!found) break;
		best=lst;
	}
	cout<<best<<' '<<d[best]<<endl;
	

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}