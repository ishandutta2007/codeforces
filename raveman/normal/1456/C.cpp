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

int n,k;
int c[555555];

ll r[555555];

map<pair<pl,vi>,ll> w[55];

ll stupid(ll cs,ll cv,vi v,int k){
	if(v.empty()) return cv;
	if(w[k][make_pair(pl(cs,cv), v)])
		return w[k][make_pair(pl(cs,cv), v)]; 

	ll best=-1e18;
	if(k>0){
		best=stupid(0,cv,v,k-1);
	}
	REP(i,v.size()){
		vi t=v;
		t.erase(t.begin()+i);
		best=max(best,stupid(cs+v[i],cv+cs,t,k));
	}

	return w[k][make_pair(pl(cs,cv), v)]=best;
}

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n>>k;
	REP(i,n)scanf("%d",c+i);

//start:
	//n=rand()%10+1;
	//k=1;//rand()%(n+1);
	//REP(i,n)c[i]=rand()%20-15;
	
	sort(c,c+n);
	reverse(c,c+n);
	ll res=0;
	REP(i,n)res+=c[i]*ll(n-i-1);

	if(k>0){
		map<int,int> gs;
		gs[0]=k+1;
		for(int i=n-1;i>=0;i--){
			if(i+k+1>=n){
				r[i]=0;
			}else{
				int smallest_group = gs.begin()->first;
				gs[smallest_group] --;
				gs[smallest_group+1] ++;
				if(gs[smallest_group]==0)gs.erase(gs.begin());
				r[i]=(smallest_group+1)*ll(c[i]);
				r[i]+=r[i+1];
			}
		}

		//REP(i,n)cout<<r[i]<<' ';puts("");


		ll t=0,cs=0;
		REP(i,n){
			res=max(res,t+cs*(ll(n-i-k-1+k)/(k+1))+r[i]);
			//cout<<i<<" : "<<t+r[i]<<endl;
			cs+=c[i];
			t+=cs;
		}
	}

	cout<<res<<endl;
	//return 0;
	/*
	vi v;
	REP(i,n)v.pb(c[i]);
	
	ll tt = stupid(0,0,v,k);
	cout<<tt<<endl;
	if(tt==res){
		puts("OK");
		goto start;
	}
	cout<<n<<' '<<k<<endl;
	REP(i,n)cout<<c[i]<<' ';puts("");
	*/
#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}