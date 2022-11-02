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


int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	int n,k;
	int n0=0,n1=0;
	cin>>n>>k;
	REP(i,n){
		int x;
		scanf("%d",&x);
		if(x%2)n1++;
		else n0++;
	}

	int moves = n - k;

	if(moves==0){
		puts(n1%2==0?"Daenerys":"Stannis");
		return 0;
	}

	if(moves%2==0){

		int fm = moves / 2;
		//cout<<fm<<endl;
		if(n0<=fm && (n1-fm-(fm-n0))%2==1) puts("Stannis");
		else puts("Daenerys");
	}else{
		int fm = moves / 2;
		if(n1<=fm)puts("Daenerys");
		else if(n0<=fm && (n1-(fm+1)-(fm-n0))%2==0)puts("Daenerys");
		else puts("Stannis");
	}

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}