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

string s;
int    a[1<<20];
double d[1<<20];
double nl[1<<20];
int    f[1<<20];
int n;

double best;
string str;

double go(int pos){
	if(pos==n){
		return 1;
	}else{
		double best=0;
		int c=0;
		for(int i=pos;i<n;i++){
			c=10*c+a[i];
			double r = pow(c,go(i+1));
			best=max(best,r);
		}
		return best;
	}
}

double mysolve(){
	if(n==1)return a[0];
	double x = max(a[n-2]*10.0+a[n-1],pow(a[n-2]+0.,a[n-1]));
	for(int i=n-3;i>=0;i--)x=pow(a[i],x);
	return x;
}

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	int tc;
	cin>>tc;
	REP(TC,tc){
		int n;
		ll w;
		cin>>n>>w;
		vector<pii> v;
		REP(i,n){
			int x;
			scanf("%d",&x);
			v.pb(pii(x,i));
		}
		SORT(v);
		ll c = 0;
		vi r;
		for(int i=n-1;i>=0;i--){
			if(c+v[i].first<=w){
				c+=v[i].first;
				r.pb(v[i].second);
			}
		}
		if(c>=(w+1)/2 && c<=w){
			cout<<r.size()<<endl;
			REP(i,r.size())cout<<r[i]+1<<' ';
			puts("");
		}else puts("-1");
	}

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}