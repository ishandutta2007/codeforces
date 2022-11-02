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

ll gcd(ll a,ll b){
	while(a&&b)
		if(a>b)a%=b;
		else b%=a;
	return a+b;
}

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	//0,y1 x2,0 x3,y3

	//(x2-0)*(y3-y1)-(x3-x2)*(0-y1)

	ll n,m,k;
	cin>>n>>m>>k;
	ll tn=n,tm=m;

	ll g = gcd(n, k);
	n/=g;k/=g;
	
	g = gcd(m,k);
	m/=g,k/=g;

	if(k==1) {
		k*=2;
		if(n*2<=tn) n*=2;
		else m*=2;
	}

	if(k!=2) puts("NO");
	else{
		puts("YES");
		cout<<n<<" 0"<<endl;
		cout<<"0 0"<<endl;
		cout<<"0 "<<m<<endl;
	}

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}