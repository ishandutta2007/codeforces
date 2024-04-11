//#pragma comment(linker, "/STACK:60777216")  

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

int r[1111111];

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	int n,q;
	cin>>n>>q;
	int even=0,odd=0;
	int t;
	REP(i,q){
		scanf("%d",&t);
		if(t==1){
			scanf("%d",&t);
			even=(even+n+n+t)%n;
			odd=(odd+n+n+t)%n;
		}else if(t==2){
			if((0+even)%2==0) even=(even+1)%n;
			else even=(even+n-1)%n;
			if((1+odd)%2==0) odd=(odd+1)%n;
			else odd=(odd+n-1)%n;
		}
	}
	REP(i,n){
		int pos = i;
		if(i%2==0) pos = (pos+even)%n;
		else pos = (pos + odd)%n;
		r[pos] = i;
	}
	REP(i,n){
		if(i)printf(" ");
		printf("%d",r[i]+1);
	}
	puts("");


#ifdef LocalHost
	//printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}