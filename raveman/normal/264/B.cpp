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

int n;
int a[111111];

int ml[111111];

int d[111111];
int q[111111];

vi getp(int  x){
	vi r;
	while(x>1){
		if(d[x]==0){
			r.pb(x);
			break;
		}
		r.pb(d[x]);
		x=q[x];
	}
	return r;
}

int main(){
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif


	for(int i=2;i<=100000;i++)if(d[i]==0){
		for(int j=i+i;j<=100000;j+=i) d[j]=i;
	}
	for(int i=2;i<=100000;i++)if(d[i]){
		int t = i;
		while(t%d[i]==0) t/=d[i];
		q[i]=t;
	}

	cin>>n;
	REP(i,n) scanf("%d",a+i);
	sort(a,a+n);

	int res = 1;
	
	REP(i,n){
		vi p = getp(a[i]);
		int mx = 0;
		REP(j,p.size()) mx = max(mx, ml[p[j]]);
		mx++;
		res=max(res,mx);
		REP(j,p.size()) ml[p[j]]=mx;
	}

	cout<<res<<endl;

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}