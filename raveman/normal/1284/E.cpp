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

ll n;
int x[3333],y[3333];

bool half(const pii& a){return a.second>=0;}
bool cmp(const pl& a,const pl& b){
	if(half(a)==half(b)) return a.first*b.second<a.second*b.first;
	return half(a)>half(b);
}

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n;
	REP(i,n)cin>>x[i]>>y[i];
	ll res = n * (n-1)*(n-2)*(n-3)*(n-4)/24;
	REP(i,n){
		vector<pl> v;
		REP(j,n)if(i!=j)v.pb(pl(x[j]-x[i],y[j]-y[i]));
		sort(v.begin(),v.end(),cmp);
		int pos = 0;
		REP(j,n-1){
			while(pos-j<n-1 && v[j].first*v[pos%v.size()].second-v[pos%v.size()].first*v[j].second<=0)pos++;
			ll num = pos - j - 1;
			if(num>=3){
				res -= num * (num-1)*(num-2)/6;
			}
		}
	}
	cout<<res<<endl;

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}