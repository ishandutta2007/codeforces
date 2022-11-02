#pragma comment(linker, "/STACK:60777216")  

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
typedef vector<ll> vl;

#define FOR(i,a,b)		for(int i=(a);i<(b);i++)	
#define REP(i,n)		FOR(i,0,n)
#define SORT(v)			sort((v).begin(),(v).end())
#define UN(v)			SORT(v),(v).erase(unique((v).begin(),(v).end()),(v).end())
#define CL(a,b)			memset(a,b,sizeof a)
#define pb				push_back

int n;
int a[333333];

struct D{
	ll total;
	vl b,e;
	D(){
		total=0;
	}
};

void merge(vl& res,const vl& t1, const vl& t2){
	int p1=0,p2=0;
	while(p1<t1.size() || p2<t2.size()){
		if(p2>=t2.size() || p1<t1.size() && t1[p1]<=t2[p2])res.pb(t1[p1]),p1++;
		else res.pb(t2[p2]),p2++;
	}
}

D solve(int from,int to){
	D res;
	if(from==to){
		res.total=(a[from]==0?1:0);
		res.b.pb(a[from]);
		res.e.pb(a[from]);
		return res;
	}
	int m = (from+to)/2;
	D res1 = solve(from,m);
	D res2 = solve(m+1,to);
	res.total = res1.total + res2.total;
	int p1=0,p2=0;
	//cout<<"start "<<' '<<from<<' '<<to<<endl;
	while(p1<res1.e.size() && p2<res2.b.size()){
		//cout<<p1<<' '<<p2<<" - "<<endl;
		if(res1.e[p1] < res2.b[p2]) {p1++;continue;}
		if(res1.e[p1] > res2.b[p2]) {p2++;continue;}
		int n1=0,n2=0;
		ll v = res1.e[p1];
		while(p1<res1.e.size() && res1.e[p1]==v)n1++,p1++;
		while(p2<res2.b.size() && res2.b[p2]==v)n2++,p2++;
		//cout<<"e "<<p1<<' '<<p2<<endl;
		res.total += ll(n1)*n2;
	}	

	//cout<<from<<' '<<to<<' '<<m<<' '<<res.total<<endl;
	//REP(i,res1.e.size())cout<<res1.e[i].first<<' ';puts("");
	//REP(i,res2.b.size())cout<<res2.b[i].first<<' ';puts("");

	ll good_l=0, good_u=1e18;

	ll d=0;
	ll s1=0,s2=0;
	for(int i=m;i>=from;i--){
		d=a[i]-d;
		if((i-from)%2)s2+=a[i];
		else s1+=a[i];

		if((m-i)%2==0){
			good_u=min(good_u,d);
		}else{
			good_l=max(good_l,-d);
		}
	}
	vl b2;
	REP(i,res2.b.size())if(res2.b[i]>=good_l && res2.b[i]<=good_u){
		b2.pb(s1-s2+res2.b[i]*((m-from)%2==0?-1:1));
	}
	if(((m-from)%2)==0)reverse(b2.begin(),b2.end());
	merge(res.b,res1.b,b2);

	good_l=0;good_u=1e18;
	d=0;
	s1=0,s2=0;
	for(int i=m+1;i<=to;i++){
		d=a[i]-d;
		if((i-to)%2)s2+=a[i];
		else s1+=a[i];
		
		if((i-(m+1))%2==0){
			good_u=min(good_u,d);
		}else{
			good_l=max(good_l,-d);
		}
	}
	vl e1;
	REP(i,res1.e.size())if(res1.e[i]>=good_l && res1.e[i]<=good_u){
		e1.pb(s1-s2+res1.e[i]*((to-m)%2==0?1:-1));
	}
	if(((to-m)%2)==1)reverse(e1.begin(),e1.end());
	merge(res.e,res2.e,e1);
	//cout<<"end "<<from<<' '<<to<<endl;
	//cout<<res.total<<endl;
	//REP(i,res.b.size())cout<<res.b[i]<<' ';puts("");
	//REP(i,res.e.size())cout<<res.e[i]<<' ';puts("");
	return res;
}

int stupid(bool o=0){
	ll res=0;
	REP(i,n){
		ll d=0;
		FOR(j,i,n){
			d=a[j]-d;
			if(d<0)break;
			if(d==0){
				if(o)cout<<i<<' '<<j<<endl;
				res++;
			}
		}
	}
	return res;
}


int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	int tc;
	cin>>tc;
	REP(TC,tc){
		cin>>n;
		REP(i,n)scanf("%d",a+i);
		D res = solve(0,n-1);
		cout<<res.total<<endl;
	}
		
#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}