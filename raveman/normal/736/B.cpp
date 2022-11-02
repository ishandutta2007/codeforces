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
#define CL(a,b)				memset(a,b,sizeof a)
#define pb				push_back

int d[1000000];

int solve(int x){
	for(int i=x-1;i>=1;i--)if(x%i==0)return i;
	return 1;
}

bool isp(int n){
	for(int j=2;j*j<=n;j++)if(n%j==0)return 0;
	return 1;
}

int solve2(int n){
	if(isp(n)) return 1;//cout<<1<<endl;
	else if(isp(n-2) || n%2==0) return 2;//cout<<2<<endl;
	else return 3;//cout<<3<<endl;
	return -1;
}

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	int n;
	cin>>n;
	cout<<solve2(n)<<endl;
	/*d[2]=1;
	for(int i=3;i<100000;i++){
		if(i%100==0)cout<<i<<endl;
		d[i]=solve(i);
		for(int j=2;j<=i;j++)if(i-j>=2)d[i]=min(d[i],solve(j)+d[i-j]);
		if(d[i]!=solve2(i))
		cout<<i<<": "<<d[i]<<endl;
	}*/


	
#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}