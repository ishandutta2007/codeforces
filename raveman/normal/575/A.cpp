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

int n,m;
ll s[55555];
pl sr[55555];
ll k,p;

const int SUBPERIOD = 50;
const int SUBPERIOD2 = SUBPERIOD * 5;
const int SUBPERIOD3 = SUBPERIOD2 * 5;

struct M{
	ll a[2][2];
	M(){CL(a,0);}
	M pom(M x){
		M r;
		REP(i,2)REP(j,2){
			ll sum=0;
			REP(k,2)sum=(sum+a[i][k]*x.a[k][j])%p;
			r.a[i][j]=sum;
		}
		return r;
	}
	void out(){
		puts("==begin==");
		REP(i,2){
			cout<<a[i][0]<<' '<<a[i][1]<<endl;
		}
		puts("==end==");
	}
};

M full_transform;
M pt[55555];
M pt2[55555];
M pt3[55555];

M process(int from, int to){
	M r;
	r.a[0][0]=r.a[1][1]=1;
	for(int i=from;i<=to;i++){
		M t;
		t.a[1][0]=1;
		t.a[0][0]=s[(i-1+n)%n];
		t.a[0][1]=s[(i-2+n+n)%n];
		r=t.pom(r);
	}
	return r;
}

ll S(ll pos){
	int ps=lower_bound(sr,sr+m,pl(pos,0))-sr;
	if(ps>=0 && ps<m){
		if(sr[ps].first==pos)return sr[ps].second;
	}
	return s[pos%n];
}

void applyone(ll pos, ll& f0, ll& f1) {
	ll tf1 = (f1 * S(pos-1) + f0 * S(pos-2))%p;
	f0=f1;
	f1=tf1;
}

M qp(M c, ll st){
	M r;
	r.a[0][0]=r.a[1][1]=1;
	while(st){
		if(st&1)r=r.pom(c);
		c=c.pom(c);
		st>>=1;
	}
	return r;
}

int it;
void apply(ll from, ll to, ll& f0, ll& f1){
	while(from<to){
		it++;
		if(from%n==n-1 && from+n<to){
			//puts("here");
			ll t = (to-from) / n;
			M trans = qp(full_transform, t);

			ll tf0 = f0;
			ll tf1 = f1;

			//cout<<f0<<' '<<f1<<endl;

			//trans.out();

			f1 = (trans.a[0][0] * tf1 + trans.a[0][1] * tf0)%p;
			f0 = (trans.a[1][0] * tf1 + trans.a[1][1] * tf0)%p;

			//cout<<f0<<' '<<f1<<endl;

			from += t * n;
		}else if((from%n)%SUBPERIOD3==SUBPERIOD3-1 && from+SUBPERIOD3<=to && (from%n+SUBPERIOD3<n)){
			M& trans = pt3[((from+1)%n)/SUBPERIOD3];

			ll tf0 = f0;
			ll tf1 = f1;

			f1 = (trans.a[0][0] * tf1 + trans.a[0][1] * tf0)%p;
			f0 = (trans.a[1][0] * tf1 + trans.a[1][1] * tf0)%p;

			from += SUBPERIOD3;
		}else if((from%n)%SUBPERIOD2==SUBPERIOD2-1 && from+SUBPERIOD2<=to && (from%n+SUBPERIOD2<n)){
			M& trans = pt2[((from+1)%n)/SUBPERIOD2];

			ll tf0 = f0;
			ll tf1 = f1;

			f1 = (trans.a[0][0] * tf1 + trans.a[0][1] * tf0)%p;
			f0 = (trans.a[1][0] * tf1 + trans.a[1][1] * tf0)%p;

			from += SUBPERIOD2;
		}else if((from%n)%SUBPERIOD==SUBPERIOD-1 && from+SUBPERIOD<=to && (from%n+SUBPERIOD<n)){
			M& trans = pt[((from+1)%n)/SUBPERIOD];

			ll tf0 = f0;
			ll tf1 = f1;

			f1 = (trans.a[0][0] * tf1 + trans.a[0][1] * tf0)%p;
			f0 = (trans.a[1][0] * tf1 + trans.a[1][1] * tf0)%p;

			from += SUBPERIOD;
		}else{
			applyone(from+1,f0,f1);		
			from++;
		}
	}
	//cout<<"apply "<<from<<' '<<to<<" == "<<it<<endl;
}

ll stupid(){
	//return;
	cout<<"stupid ";
	ll f0=0;
	ll f1=1;
	for(ll i=2;i<=k;i++){
		applyone(i,f0,f1);
	}
	cout<<f1;
	puts("");
	return f1;
}

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	bool DEBUG = 0;
	cin>>k>>p;
	cin>>n;
	REP(i,n){
		if(!DEBUG)scanf("%d",s+i);
		else s[i]=rand()+1;
	}
	cin>>m;
	REP(i,m){
		if(!DEBUG)cin>>sr[i].first>>sr[i].second;
		else {sr[i].first=i*n+n+1;sr[i].second=rand()+1;}
	}
	sort(sr,sr+m);
	while(m>0 && sr[m-1].first>k)m--;


	//ll st = stupid();

	if(m==0 || sr[m-1].first!=k){
		sr[m].first=k;
		sr[m].second=0;
		++m;
	}

	REP(i,n){
		if(i%SUBPERIOD==0){
			pt[i/SUBPERIOD] = process(i, min(n-1,i+SUBPERIOD-1));
		}
		if(i%SUBPERIOD2==0){
			pt2[i/SUBPERIOD2] = process(i, min(n-1,i+SUBPERIOD2-1));
		}
		if(i%SUBPERIOD3==0){
			pt3[i/SUBPERIOD3] = process(i, min(n-1,i+SUBPERIOD3-1));
		}
	}
	full_transform = process(0, n-1);
	//full_transform.out();

	if(k==0)puts("0");
	else if(k==1)cout<<1%p<<endl;//puts("1");
	else{
		ll pos = 1;
		ll f0 = 0;
		ll f1 = 1;
		int spos = 0;
		while(pos<k){
			ll nextpos = sr[spos].first;
			if(pos<nextpos){
				apply(pos,nextpos, f0,f1);
				pos=nextpos;
			}else{
				applyone(pos+1,f0,f1);
				pos++;				
			}
			while(spos<m && sr[spos].first<=pos-2)spos++;
		}
		cout<<f1<<endl;		
		//cout<<it<<endl;
	}

	

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}