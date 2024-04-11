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

const int mod = 1000000000+7;

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	int n;
	string s;
	cin>>n;
	cin>>s;
	int k1=0,k2=0,k3=0,k4=0;
	REP(i,n){
		if(s[i]=='A')k1++;
		if(s[i]=='C')k2++;
		if(s[i]=='G')k3++;
		if(s[i]=='T')k4++;
	}
	int mn = max(max(k1,k2),max(k3,k4));
	int num = (k1==mn?1:0)+(k2==mn?1:0)+(k3==mn?1:0)+(k4==mn?1:0);
	ll res = 1;
	REP(i,n)res*=num,res%=mod;
	cout<<res<<endl;
	
#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}