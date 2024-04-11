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
#define CL(a,b)				memset(a,b,sizeof a)
#define pb				push_back

const int mod = 1000000007;
int r[202][102][1001];
int a[201];

void add(int& x,int y){
	x+=y;
	if(x>=mod)x-=mod;
}

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	int n,k;
	cin>>n>>k;
	REP(i,n)cin>>a[i];

//	n=6;k=1000;
	//REP(i,n)a[i]=1;

	sort(a,a+n);
	int mx = n/2;

	r[0][0][0]=1;
	int t;
	REP(i,n)REP(j,mx+1)REP(w,k+1)if(t=r[i][j][w]){
		// open
		if(j<mx && i+1<n){
			int nw = w+(a[i+1]-a[i])*(j+1);
			if(nw<=k){
				add(r[i+1][j+1][nw],t);
			}
		}
		// close
		if(j){
			int nw = w + (a[i+1]-a[i])*(j-1);
			if(nw<=k && nw>=0){
				add(r[i+1][j-1][nw],t*ll(j)%mod);
			}
		}
		// other
		{
			int nw = w + (a[i+1]-a[i])*j;
			if(nw>=0 && nw<=k){
				add(r[i+1][j][nw],t*ll(j+1)%mod);
			}
		}
	}

	int res = 0;
	REP(i,k+1)add(res,r[n][0][i]);
	cout<<res<<endl;



#ifdef LocalHost
	//printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}