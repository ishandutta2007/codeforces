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
typedef pair<pii,int> p3;

#define FOR(i,a,b)		for(int i=(a);i<(b);i++)
#define REP(i,n)		FOR(i,0,n)
#define SORT(v)			sort((v).begin(),(v).end())
#define UN(v)			SORT(v),(v).erase(unique((v).begin(),(v).end()),(v).end())
#define CL(a,b)			memset(a,b,sizeof a)
#define pb				push_back

struct P{
	int in,out,w,s,v;
	void ccin(){
		cin>>in>>out>>w>>s>>v;
	}
	bool operator<(const P& s)const{
		return out-in < s.out-s.in;
	}
};

int r[555][1111];

int mx[1111];

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	int n,S;
	cin>>n>>S;
	//n=500;S=1000;
	vector<P> v(n+1);
	REP(i,n){
		v[i].ccin();
		//v[i].in=rand()%400;
		//v[i].out=v[i].in+rand()%100;
		///v[i].s=1000;
		//v[i].v=1000;
		//v[i].w=rand()%10;

	}
	v[n].in=-1e9;
	v[n].out=1e9;
	v[n].w=0;
	v[n].s=S;
	v[n].v=0;

	SORT(v);

	REP(i,v.size()){
		vector<p3> sg;
		REP(j,i)if(v[i].in <= v[j].in && v[j].out<=v[i].out) sg.pb(p3(pii(v[j].out,v[j].in),j));
		vi allp;
		REP(j,sg.size()) allp.pb(sg[j].first.first);
		REP(j,sg.size()) allp.pb(sg[j].first.second);
		UN(allp);
		REP(j,sg.size()){
			sg[j].first.first=lower_bound(allp.begin(),allp.end(),sg[j].first.first)-allp.begin();
			sg[j].first.second=lower_bound(allp.begin(),allp.end(),sg[j].first.second)-allp.begin();
		}
		SORT(sg);
		REP(j,v[i].w) r[i][j]=0;
		FOR(j,v[i].w,S+1){
			int end = 0;
			mx[0]=0;
			FOR(k,1,allp.size()){
				mx[k]=mx[k-1];
				while(end<sg.size() && sg[end].first.first==k){
					mx[k]=max(mx[k], mx[sg[end].first.second]+r[sg[end].second][min(j-v[i].w,v[i].s)]);
					++end;
				}
			}

			r[i][j] =  v[i].v;
			if (allp.size() > 0){
				r[i][j] += mx[allp.size() -1 ]; 
			}
		}
	}

	cout<<r[n][S]<<endl;

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}