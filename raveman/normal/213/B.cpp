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

typedef long long ll;
typedef pair<int,int>	pii;
typedef pair<double,double>	pdd;
typedef vector<int> vi;
typedef vector<double> vd;
typedef pair<ll,ll> pl;

#define FOR(i,a,b)		for(int i=(a);i<(b);i++)
#define REP(i,n)		FOR(i,0,n)
#define SORT(v)			sort((v).begin(),(v).end())
#define UN(v)			SORT(v),(v).erase(unique((v).begin(),(v).end()),(v).end())
#define CL(a,b)			memset(a,b,sizeof a)
#define pb				push_back

const int mod = 1000000007 ;
int a[11];

int c[111][111];

ll d[111][11];

ll solve(int n){
	int sum = 0;
	REP(i,10) sum += a[i];
	if(sum>n) return 0;
	CL(d,0);
	d[n][0] = 1;
	for(int i=n;i>=0;i--)for(int j=0;j<10;j++)if(d[i][j]){
		ll t = d[i][j];
		for(int k=a[j];k<=i;k++){
			d[i-k][j+1] += t * c[i][k];
			d[i-k][j+1] %= mod;
		}
	}
	return d[0][10];
}

int main(){
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	REP(i,111){
		c[i][i]=c[i][0]=1;
		FOR(j,1,i) c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
	}

	int n;
	cin>>n;
	REP(i,10) cin>>a[i];

	ll res = 0;
	FOR(i,1,n+1)FOR(d,1,10){
		int prev = a[d];
		a[d] = max(0, a[d] - 1);
		res += solve(i-1);
		res %= mod;
		a[d] = prev;
	}
	cout<<res<<endl;

#ifdef LocalHost
	printf("TIME: %.3lf\n",double(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}