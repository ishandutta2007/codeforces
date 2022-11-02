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

int n,m,k,p;
vector<vi> a,b;

vector<ll> solve(vector<vi>& a,int n,int m){
	priority_queue<ll> q;
	REP(i,a.size()){
		ll sum =0;
		REP(j,a[i].size()) sum+=a[i][j];
		q.push(sum);
	}
	vector<ll> t;
	t.pb(0);
	ll sum = 0;
	REP(i,k){
		ll val = q.top();
		sum+=val;
		q.pop();
		t.pb(sum);
		q.push(val-a[0].size() * ll(p));
	}
	return t;
}

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n>>m>>k>>p;
	REP(i,n)a.pb(vi(m));
	REP(i,m)b.pb(vi(n));
	REP(i,n)REP(j,m)scanf("%d",&a[i][j]),b[j][i]=a[i][j];

	vector<ll> t1 = solve(a,n,m);
	vector<ll> t2 = solve(b,m,n);

	ll res = -1e18;

	REP(i,k+1){
		res=max(res,t1[i]+t2[k-i]-p*ll(i)*ll(k-i));
	}

	cout<<res<<endl;

	

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}