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

int n,h;
int a[111111];

vector<pii> v;

int best = 1e9;
vi xx;

void go(vi t){
	int val = 1e9;
	int mx = 1e9;
	int mn = 0;

	

	val = mx - mn;


	if(val<best){
		best=val;
		xx=t;
	}
}

int main(){
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif
	
	cin>>n>>h;
	REP(i,n) scanf("%d",a+i),v.pb(pii(a[i],i));
	SORT(v);

	xx=vi(n,0);
	best = v[n-1].first + v[n-2].first - v[0].first - v[1].first;

	int to=-1;
	for(int i=1;i<n;i++){
		int mn = v[0].first + v[1].first + h;
		if(i+1<n) mn = min(mn, v[0].first + v[i+1].first);
		if(i>=2) mn = min(mn, v[1].first + v[2].first);
		
		int mx = 0;
		if(i<n-2) mx = max(0, v[n-2].first + v[n-1].first);
		if(i<n-1) mx = max(mx, v[n-1].first + v[i].first + h);
		if(i==n-1) mx = max(mx, v[n-1].first + v[n-2].first),mx=max(mx,v[n-1].first+v[0].first+h);

		if(mx - mn < best){
			//cout<<mn<<' '<<mx<<' '<<i<<endl;
			best = mx - mn;
			to=i;
		}
	}
	if(to!=-1){
		FOR(i,1,to+1) xx[i]=1;
	}

	cout<<best<<endl;
	vi z(n);
	REP(i,n) z[v[i].second]=xx[i];
	REP(i,n){
		if(i) printf(" ");
		printf("%d",z[i]+1);
	}
	puts("");

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}