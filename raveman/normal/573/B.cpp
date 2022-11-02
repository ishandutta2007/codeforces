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

int h[111111];
int l[111111];
int r[111111];

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	int n;
	cin>>n;
	REP(i,n)scanf("%d",h+i);

	int mx = 0;
	REP(i,n){
		l[i]=mx;
		mx++;
		mx=min(mx,h[i]);
	}
	mx=0;
	for(int i=n-1;i>=0;i--){
		r[i]=mx;
		mx++;
		mx=min(mx,h[i]);
	}

	int res = 0;
	REP(i,n){
		//cout<<l[i]<<' '<<r[i]<<' '<<h[i]<<endl;
		res=max(res,min(min(l[i],r[i])+1,h[i]));
	}
	cout<<res<<endl;
	

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}