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
typedef pair<int,pii>	p3;
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



int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	int tc;
	cin>>tc;
	REP(TC,tc){
		int n,k;
		cin>>n>>k;
		string s;
		cin>>s;
		bool g=1;
		REP(i,k){
			bool c0=1,c1=1;
			for(int j=i;j<n;j+=k){
				if(s[j]=='1')c0=0;
				if(s[j]=='0')c1=0;
			}
			if(!c0 && !c1)g=0;
			if(!c0)s[i]='1';
			if(!c1)s[i]='0';
		}
		int n0=0,n1=0;
		REP(i,k)if(s[i]=='0')n0++;
		else if(s[i]=='1')n1++;
		if(n0>k/2 || n1>k/2)g=0;
		puts(g?"YES":"NO");
	}


#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}