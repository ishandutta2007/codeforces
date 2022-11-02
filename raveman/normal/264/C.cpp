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

int n,q;
int v[111111];
int c[111111];

pl b1,b2;

ll r[111111];

int main(){
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n>>q;
	REP(i,n) scanf("%d",v+i);
	REP(i,n) scanf("%d",c+i);
	REP(tc,q){
		int _a,_b;
		scanf("%d %d",&_a,&_b);
		ll a= _a,b=_b;
		b1=pl(-1e18,-1);
		b2=pl(-1e18,-2);
		ll best = 0;
		REP(i,n+1) r[i]=-1e18;
		
		REP(i,n){
			ll tb = v[i] * b;

			tb=max(tb, r[c[i]] + v[i]*a);

			if(b1.second!=c[i])
				tb=max(tb,b1.first + b*v[i]);
			if(b2.second!=c[i])
				tb=max(tb,b2.first + b*v[i]);
				

			pl x (tb, c[i]);

			if(b1.second==x.second){
				b1.first=max(b1.first,x.first);
			}else if(b2.second==x.second){
				b2.first=max(b2.first,x.first);
				if(b2>=b1)swap(b2,b1);
			}else{
				if(x>=b2)swap(b2,x);
				if(b2>=b1)swap(b1,b2);
			}

			best=max(best, tb);
			r[c[i]]=max(r[c[i]], tb);
		}

		cout<<best<<endl;
	}
	
#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}