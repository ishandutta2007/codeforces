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
ll sum[111111];
ll res[111111];


ll getSum(ll p1,ll p2){
	if(p1<=0) return sum[p2];
	return sum[p2] - sum[p1-1];
}

ll solve(int k){
	ll pos = n-2;
	ll res = 0;
	ll curr = k;
	int it = 1;
	while(pos>=0){
		res += getSum(pos-curr+1,pos) * it;
		it++;
		pos-=curr;
		curr*=k;
	}
	return res;
}

int main(){
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n;
	REP(i,n) scanf("%d",a+i);
	sort(a,a+n);
	sum[0]=a[0];
	FOR(i,1,n) sum[i]=sum[i-1]+a[i];
	int q;
	cin>>q;
	CL(res,-1);
	REP(i,q){
		int x;
		scanf("%d",&x);
		if(res[x]==-1)
			res[x] = solve(x);
		if(i) printf(" ");
		cout<<res[x];
	}
	puts("");

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}