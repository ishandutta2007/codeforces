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

int q[111111];
int a[111111];

int main(){
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	int m;
	cin>>m;
	REP(i,m) scanf("%d",q+i);
	sort(q,q+m);

	int Q = q[0];

	int n;
	cin>>n;
	REP(i,n) scanf("%d",a+i);
	sort(a,a+n);
	reverse(a,a+n);

	int res = 0;
	REP(i,n) res += a[i];
	for(int pos = 0; pos < n ; pos += Q+2){
		int v1 = pos + Q;
		int v2= pos + Q + 1;
		if(v1<n) res -= a[v1];
		if(v2<n) res -= a[v2];
	}
	cout<<res<<endl;


#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}