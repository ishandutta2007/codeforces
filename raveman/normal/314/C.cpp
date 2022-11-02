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

const int mod = 1000000007 ;
int n;
int a[1111111];

int s[1<<20];

void add(int& x,int v){
	x+=v;
	if(x>=mod)x-=mod;
}
void addV(int pos,int val){
	pos+=(1<<19);
	while(pos){
		add(s[pos],val);
		pos>>=1;
	}
}

int getSum(int p1,int p2){
	p1+=(1<<19);
	p2+=(1<<19);
	int sum=0;
	while(p1<=p2){
		if((p1&1)) add(sum, s[p1]);
		if(!(p2&1)) add(sum, s[p2]);
		p1=(p1+1)/2;
		p2=(p2-1)/2;
	}
	return sum;
}

int main(){
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n;
	vector<pii> v;
	REP(i,n)scanf("%d",a+i),v.pb(pii(a[i],i+1));
	SORT(v);
	CL(s,0);
	addV(0,1);
	ll res = 0;
	REP(i,v.size()){
		if(i==0 || v[i-1].first!=v[i].first){
			ll x = getSum(0, v[i].second);
			//cout<<"S" <<0<<' '<<v[i].second<<" = " <<x<<endl;
			x *= v[i].first;
			x%=mod;
			addV(v[i].second,x);
			res += x;
			//cout<<v[i].first<<' '<<x<<endl;
		}else{
			ll x = getSum(v[i-1].second, v[i].second);
			//cout<<"sum " << v[i-1].second<<' '<<v[i].second<<' '<<x<<endl;
			x *= v[i].first;
			x%=mod;
			addV(v[i].second,x);
			res+=x;
			//cout<<v[i].first<<' '<<x<<endl;
		}
	}
	cout<<res%mod<<endl;

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}