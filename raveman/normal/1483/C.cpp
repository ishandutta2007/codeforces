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

int n;
int h[333333];
int b[333333];
ll  r[333333];

ll  s[1<<20];

ll getmax(int p1,int p2){
	p1+=(1<<19);
	p2+=(1<<19);
	ll v=s[p1];
	while(p1<=p2){
		v=max(v,s[p1]);
		v=max(v,s[p2]);
		p1=(p1+1)>>1;
		p2=(p2-1)>>1;
	}
	return v;
}

void setval(int pos, ll v){
	pos+=(1<<19);
	while(pos){
		s[pos]=max(s[pos],v);
		pos>>=1;
	}
}

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n;
	REP(i,n)scanf("%d",h+i);
	REP(i,n)scanf("%d",b+i);
	
	vi t;

	REP(i,1<<20)s[i]=-1e18;

	r[0]=0;
	setval(0,0);
	REP(i,n){
		r[i+1]=r[i]+b[i];

		while(!t.empty()){
			if(h[t.back()]>h[i])t.pop_back();
			else break;
		}
		if(!t.empty()){
			r[i+1]=max(r[i+1],r[t.back()+1]);
			r[i+1]=max(r[i+1],b[i]+getmax(t.back()+1,i));
		}else{
			r[i+1]=max(r[i+1],b[i]+getmax(0,i));
		}

		setval(i+1,r[i+1]);
		t.pb(i);
	}

	cout<<r[n]<<endl;
	//REP(i,n+1)cout<<r[i]<<' ';puts("");

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}