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

int n;
ll a,b;
ll x[1111111];

int gcd(int a,int b){
	while(a&&b){
		if(a>b)a%=b;
		else b%=a;
	}
	return a+b;
}

ll cost[1111111];
ll cost1[1111111];
ll cost2[1111111];
ll m1[1111111];
ll m2[1111111];

ll solve(int p){
	REP(i,n){
		cost[i] = a;
		if(x[i]%p==0) cost[i]=a;
		else if(x[i]%p==1 || x[i]%p==p-1) cost[i]=a-b;
		else cost[i] = -1e18;
	}
	REP(i,n){
		cost1[i] = cost[i] + (i?cost1[i-1]:0);
		cost1[i] = max(cost1[i],(ll)-1e18);
		m1[i] = cost1[i];
		if(i)m1[i]=max(m1[i],m1[i-1]);
	}
	for(int i=n-1;i>=0;i--){
		cost2[i] = cost[i] + (i+1<n?cost2[i+1]:0);
		cost2[i] = max(cost2[i],(ll)-1e18);
		m2[i] = cost2[i];
		if(i+1<n)m2[i]=max(m2[i],m2[i+1]);
	}
	ll res = cost1[n-1];
	REP(i,n){
		res=max(res,(i-1>=0?m1[i-1]:0)+(i+1<n?m2[i+1]:0));
	}
	return a*n-res;
}

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n>>a>>b;
	REP(i,n)scanf("%d",x+i);
	ll res = a*(n-1);
	if (n>1){
		vector<pii> t;
		t.pb(pii(x[0],x[1]));
		t.pb(pii(x[n-1],x[n-2]));
		t.pb(pii(x[0],x[n-1]));
		set<int> p;
		REP(it,t.size()){
			int a1 = t[it].first;
			int a2 = t[it].second;
			FOR(dx1,-1,2)FOR(dx2,-1,2){
				int na1 = a1 + dx1;
				int na2 = a2 + dx2;
				int g = gcd(na1,na2);
				for(int j=2;j*j<=g;j++){
					if(g%j==0)p.insert(j);
					while(g%j==0)g/=j;
				}
				if(g>1)p.insert(g);
			}
		}
		for(set<int>::iterator it = p.begin();it!=p.end();it++){
			int pr = *it;
			res=min(res,solve(pr));
		}
	}
		cout<<res<<endl;

#ifdef LocalHost
	//printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}