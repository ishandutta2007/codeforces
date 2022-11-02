//#pragma comment(linker, "/STACK:60777216")  

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

#define FOR(i,a,b)		for(int i=(a);i<(b);i++)	
#define REP(i,n)		FOR(i,0,n)
#define SORT(v)			sort((v).begin(),(v).end())
#define UN(v)			SORT(v),(v).erase(unique((v).begin(),(v).end()),(v).end())
#define CL(a,b)			memset(a,b,sizeof a)
#define pb				push_back

int k;
ll f[6];
int q;
ll a[1<<20];

vector<ll> v[1<<20];

ll getmax(int pos,int num,int mod,int power){
	int vi = pos % mod;
	if(v[vi].empty()) return 0;
	int sz = v[vi].size()/2;

	int p2 = pos / mod;
	int p1 = max(0, p2 - num);

	ll sub = 3*f[power] * (sz-1 - p2);
	//cout<<p1<<' '<<p2<<' '<<v[vi][sz]<<' '<<sz<<' '<<sub<<endl;
	p1 += sz;
	p2 += sz;
	ll res=-1e18;
	while(p1<=p2){
		//cout<<p1<<' '<<p2<<' '<<vi<<' '<<v[vi].size()<<endl;
		if(p1&1)res=max(res,v[vi][p1]);
		if(!(p2&1))res=max(res,v[vi][p2]);
		p1=(p1+1)>>1;
		p2=(p2-1)>>1;
	}

	res -= sub;
	return res;
}

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>k;
	REP(i,6)cin>>f[i];

	FOR(i,1,(1<<20))a[i]=-1e18;
	
	int pw = 9;
	int dd = 1;
	REP(power,6){
		REP(i,1<<20)v[i].clear();
		for(int i=0;i<(1<<20);i++){
			v[i%pw].pb(a[i]);
		}
		
		REP(i,1<<20)if(v[i].size()){
			ll add=0;
			while(v[i].size()&(v[i].size()-1))v[i].pb(0);
			int sz = v[i].size();
			for(int j=sz-1;j>=0;j--){
				v[i][j]+=add;
				add+=3*f[power];
			}
			vector<ll> tmp = v[i];
			v[i].clear();
			v[i].resize(2*sz);
			REP(j,sz)v[i][j+sz]=tmp[j];
			for(int j=sz-1;j>=0;j--){
				v[i][j]=max(v[i][j*2],v[i][j*2+1]);
			}
		}

		for(int i=999999;i>=0;i--){
			if(k>0)a[i] = max(a[i], getmax(i,k-1,pw,power));
			if(k>1 && i-3*dd>=0)a[i] = max(a[i], getmax(i-3*dd,k-2,pw,power)+f[power]);
			if(k>1 && i-6*dd>=0)a[i] = max(a[i], getmax(i-6*dd,k-2,pw,power)+2*f[power]);
		}
		for(int i=999999;i>=0;i--){
			REP(j,10){
				if(i-j*dd>=0)a[i] = max(a[i], a[i-j*dd]+f[power]*(j%3==0?(j/3):0));
			}
		}
		pw *= 10;
		dd*=10;
	}
	//REP(i,65)cout<<a[i]<<' ';puts("");

	cin>>q;
	REP(i,q){
		int n;
		scanf("%d",&n);
		cout<<a[n]<<"\n";
	}



#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}