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
#define CL(a,b)			memset(a,b,sizeof a)
#define pb				push_back

int pn[111];
int on[111];

bool good(int number){
	int num_active = number;
	int num_inactive = 0;
	FOR(i,1,111){
		//cout<<i<<' '<<num_active<<' '<<num_inactive<<' '<<on[i]<<' '<<pn[i]<<endl;
		int need = on[i];
		if(need>num_active) return 0;
		num_active -= need;
		num_inactive += need;

		int x = min(num_active, pn[i]);
		if(i==1 && x!=number) return 0;

		num_inactive += num_active - x;
		num_active = x;

		int y = min(num_inactive, pn[i] - x);
		num_inactive = y;
		int rest = pn[i] - x - y;
		if(rest>num_active) return 0;

		num_active -= rest;//= x - (rest-num_active);
		num_inactive += rest;

	}
	return 1;
}

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	int n;
	cin>>n;
	REP(i,n){
		ll x;
		cin>>x;
		if (x&(x-1)){
			ll y = 1;
			int t = 1;
			while (x>y){
				y*=2;
				t++;
			}
			on[t]++;
		}else{
			int t = 0;
			while(x){
				x>>=1;
				t++;
			}
			pn[t]++;
		}
	}

//	cout<<good(8)<<endl;
	//return 0;
	bool f = 1;
	FOR(i,1,n+1){
		if(good(i)){
			if(!f)printf(" ");
			f=0;
			printf("%d",i);
		}
	}
	if(f)puts("-1");
	else puts("");

#ifdef LocalHost
	//printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}