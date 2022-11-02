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

int n,k;
int a[222];

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n>>k;
	REP(i,n)cin>>a[i];
	ll best = a[0];
	vi t1,t2;
	for(int l=0;l<n;l++)
		for(int r=l;r<n;r++){
			t1.clear(),t2.clear();
			ll sum = 0;
			REP(i,n)if(i>=l&&i<=r)t1.pb(a[i]),sum+=a[i];else t2.pb(a[i]);
			SORT(t1);SORT(t2);
			best=max(best,sum);
			for(int j=1;j<=min(k,(int)min(t1.size(),t2.size()));j++){
				sum -= t1[j-1];
				sum += t2[t2.size()-j];
				best=max(best,sum);
			}
		}
	cout<<best<<endl;

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}