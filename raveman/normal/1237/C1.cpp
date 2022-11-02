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
typedef pair<double,double>	pdd;
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
struct P{
	P(){
		x=y=z=id=-1;
	}
	int x,y,z;
	int id;
};

bool cmp1(const P& p1, const P& p2){
	return p1.x < p2.x;
}
bool cmp2(const P& p1, const P& p2){
	return p1.y < p2.y;
}
bool cmp3(const P& p1, const P& p2){
	return p1.z < p2.z;
}

void solve2(vector<P> q, vector<P>& remainder){
	sort(q.begin(),q.end(),cmp3);
	while(q.size()>=2){
		cout<<q.back().id+1<<' '<<q[q.size()-2].id+1<<'\n';
		q.pop_back();
		q.pop_back();
	}
	while(!q.empty())remainder.pb(q.back()),q.pop_back();
}

void solve(vector<P> p, vector<P>& remainder){
	sort(p.begin(),p.end(),cmp2);
	vector<P> q;
	while(!p.empty()){
		vector<P> p2;
		p2.pb(p.back());p.pop_back();
		while(!p.empty() && p.back().y==p2.back().y)p2.pb(p.back()),p.pop_back();
		solve2(p2,q);
	}
	while(q.size()>=2){
		cout<<q.back().id+1<<' '<<q[q.size()-2].id+1<<'\n';
		q.pop_back();
		q.pop_back();
	}
	while(!q.empty())remainder.pb(q.back()),q.pop_back();
}

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n;
	vector<P> p;
	p.resize(n);
	REP(i,n){
		scanf("%d %d %d",&p[i].x,&p[i].y,&p[i].z);
		p[i].id=i;
	}
	sort(p.begin(),p.end(),cmp1);
	vector<P> q;
	while(!p.empty()){
		vector<P> p2;
		p2.pb(p.back());p.pop_back();
		while(!p.empty() && p.back().x==p2.back().x)p2.pb(p.back()),p.pop_back();
		solve(p2,q);
	}
	while(q.size()>=2){
		cout<<q.back().id+1<<' '<<q[q.size()-2].id+1<<'\n';
		q.pop_back();
		q.pop_back();
	}
	
#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}