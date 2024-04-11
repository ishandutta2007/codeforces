//#pragma comment(linker, "/STACK:60777216")  

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
typedef pair<ll,ll> pl;
typedef pair<int,pl>	p3l;
typedef pair<double,double>	pdd;
typedef vector<int> vi;
typedef vector<ld> vd;

#define FOR(i,a,b)		for(int i=(a);i<(b);i++)	
#define REP(i,n)		FOR(i,0,n)
#define SORT(v)			sort((v).begin(),(v).end())
#define UN(v)			SORT(v),(v).erase(unique((v).begin(),(v).end()),(v).end())
#define CL(a,b)			memset(a,b,sizeof a)
#define pb				push_back

int solve(vi v,int pw=30){
	if(pw<0)return 0;
	vi v0,v1;
	REP(j,v.size())if(v[j]&(1<<pw))v1.pb(v[j]);
	else v0.pb(v[j]);
	if(v1.size()<=1 && v0.size()<=1)return 0;
	if(v0.size()<=1) return solve(v1,pw-1);
	if(v1.size()<=1) return solve(v0,pw-1);

	int t1 = v1.size() - 1 + solve(v0,pw-1);
	int t2 = v0.size() - 1 + solve(v1,pw-1);
	return min(t1,t2);
}

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	int n;
	cin>>n;
	vi v;
	REP(i,n){
		int x;
		scanf("%d",&x);
		v.pb(x);
	}
	cout<<solve(v)<<endl;

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}