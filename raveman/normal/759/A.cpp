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
#include<unordered_map>
#include<unordered_set>

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

int p[222222];
int b[222222];
bool u[222222];

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	int n;
	cin>>n;
	REP(i,n)scanf("%d",p+i),p[i]--;
	REP(i,n)scanf("%d",b+i);

	int res = 0;
	int nc=0;
	REP(i,n)if(!u[i]){
		int x = i;
		nc++;
		while(!u[x]){
			u[x]=1;
			x=p[x];
		}
	}
	if(nc>1) res=nc;

	int sum=0;
	REP(i,n)sum+=b[i];
	if(sum%2==0) res++;

	cout<<res<<endl;

#ifdef LocalHost
	//printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}