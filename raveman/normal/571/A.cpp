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

	int a,b,c,l;
	cin>>a>>b>>c>>l;

	ll res = (l+2)*ll(l+1)*ll(l+3)/6;
	for(int i=1;i<=1000000;i++){
		if(a<=i){
			int t = min(i-c-b,l - (i-a));
			if(t>=0){
				res -= (t+1)*ll(t+2)/2;
			}
		}
		if(b<=i){
			int t = min(i-a-c,l - (i-b));
			if(t>=0){
				res -= (t+1)*ll(t+2)/2;
			}
		}
		if(c<=i){
			int t = min(i-a-b,l - (i-c));
			if(t>=0){
				res -= (t+1)*ll(t+2)/2;
			}
		}
	}
	cout<<res<<endl;

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}