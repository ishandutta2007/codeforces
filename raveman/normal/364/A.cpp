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

string s;
ll val[111111];

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	ll a;
	cin>>a;
	string s;
	cin>>s;
	REP(i,s.size()){
		int sum=0;
		FOR(j,i,s.size()){
			sum += s[j]-'0';
			if(sum>=0) val[sum]++;
		}
	}
	ll res = 0;
	if(a==0){
		FOR(i,1,111111) res += val[0] * val[i];
		FOR(i,1,111111) res += val[i] * val[0];
		res += val[0] * val[0];
	}else{
		FOR(i,1,111111)if(a%i==0){
			ll j = a / i;
			if(j<111111)
			res += val[i] * val[j];
		}
	}
	cout<<res<<endl;


#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}