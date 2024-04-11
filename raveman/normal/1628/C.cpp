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
typedef pair<int,pii>	p3;
typedef pair<ll,ll> pl;
typedef pair<int,pl>	p3l;
typedef pair<double,double>	pdd;
typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;

#define FOR(i,a,b)		for(int i=(a);i<(b);i++)	
#define REP(i,n)		FOR(i,0,n)
#define SORT(v)			sort((v).begin(),(v).end())
#define UN(v)			SORT(v),(v).erase(unique((v).begin(),(v).end()),(v).end())
#define CL(a,b)			memset(a,b,sizeof a)
#define pb				push_back

int n;
int a[1111][1111];
int b[1111][1111];

int solve(){
	vi p;
	p.pb(0);
	for(int sum=0;sum<=n+n;sum+=2){
		vi t;
		for(int i=n-1;i>=0;i--){
			int j=sum-i;
			if(j>=0 && j<n){
				t.pb(a[i][j]);
			}
		}
		if(t.size()==0)continue;
		if(t.size()%2!=1)puts("fuck");
		int x=0;
		for(int i=0;i<t.size();i+=2)x^=t[i];
		x^=p.back();
		p.pb(x);
	}
	int r=0;
	REP(i,p.size())r^=p[i];
	return r;
}

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif
	int tc;
	cin>>tc;
	REP(TC,tc){
		cin>>n;
		REP(i,n)REP(j,n)scanf("%d",&a[i][j]);
		int r = solve();
		memcpy(b,a,sizeof a);
		REP(i,n)REP(j,n){
			a[i][j]=b[j][n-1-i];
		}
		r ^= solve();
		cout<<r<<endl;
	}

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}