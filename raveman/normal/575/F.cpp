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

vi x;
int n,X;
int l[5555];
int r[5555];

ll d1[11111];
ll d2[11111];

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	
	cin>>n>>X;
	x.pb(X);
	REP(i,n){
		cin>>l[i]>>r[i];
		x.pb(l[i]);
		x.pb(r[i]);
	}
	UN(x);

	int t = x.size();
	REP(i,t)d1[i]=1e18;
	d1[lower_bound(x.begin(),x.end(),X)-x.begin()]=0;

	REP(i,n){
		REP(j,t)d2[j]=1e18;

		ll bt=1e18;
		REP(j,t){
			if(j)bt+=x[j]-x[j-1];
			bt=min(bt,d1[j]);
			d2[j]=min(d2[j],bt);
		}
		bt=1e18;
		for(int j=t-1;j>=0;j--){
			if(j+1<t)bt+=x[j+1]-x[j];
			bt=min(bt,d1[j]);
			d2[j]=min(d2[j],bt);
		}

		REP(j,t){
			if(x[j]<l[i])d2[j]+=l[i]-x[j];
			if(x[j]>r[i])d2[j]+=x[j]-r[i];
		}

		memcpy(d1,d2,sizeof d1);
	}

	ll best=d1[0];
	REP(i,t)best=min(best,d1[i]);
	cout<<best<<endl;

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}