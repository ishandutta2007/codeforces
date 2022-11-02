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

int gcd(int a,int b){
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

	int n,m,x,y,a,b;
	cin>>n>>m>>x>>y>>a>>b;
	int g = gcd(a,b);
	a/=g,b/=g;

	int w = min(n/a,m/b);
	a*=w,b*=w;

	int x1 = x - (a+1)/2;
	int y1 = y - (b+1)/2;
	x1=max(x1,0);
	y1=max(y1,0);
	x1=min(x1,n-a);
	y1=min(y1,m-b);

	cout<<x1<<' '<<y1<<' '<<x1+a<<' '<<y1+b<<endl;

#ifdef LocalHost
//	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}