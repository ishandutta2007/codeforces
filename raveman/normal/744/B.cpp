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
#include<unordered_map>
#include<unordered_set>

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
#define CL(a,b)				memset(a,b,sizeof a)
#define pb				push_back

int n;
vector<vi> q;

void solve(vector<vi> v){
	REP(i,v.size())if(v[i].size()<2){
		v.erase(v.begin()+i);
		i--;
	}
	if(v.size()==0) return;
	vi qq1,qq2;
	vector<vi> nv;
	REP(i,v.size()){
		vi t1,t2;
		REP(j,v[i].size()){
			if(j<v[i].size()/2) qq1.pb(v[i][j]),t1.pb(v[i][j]);
			else qq2.pb(v[i][j]),t2.pb(v[i][j]);
		}
		nv.pb(t1);
		nv.pb(t2);
	}
	q.pb(qq1);
	q.pb(qq2);
	solve(nv);
}

int r[22][1111];

int main(){	
#ifdef LocalHost
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n;
	vi v;
	REP(i,n)v.pb(i);
	vector<vi> a;
	a.pb(v);
	solve(a);
	
	REP(i,q.size()){
		cout<<q[i].size()<<endl;
		REP(j,q[i].size()) cout<<q[i][j]+1<<' ';
		cout<<endl;
		cout.flush();

		REP(j,n)cin>>r[i][j];
	}
	cout<<"-1"<<endl;
	REP(i,n){
		if(i)cout<<' ';
		int rs = 1e9;
		REP(j,q.size()){
			bool h = 0;
			REP(k,q[j].size())if(q[j][k]==i)h=1;
			if(!h)rs=min(rs,r[j][i]);
		}
		cout<<rs;
	}
	cout<<endl;
	cout.flush();

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}