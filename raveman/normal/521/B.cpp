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

const ll mod = 1000000000+9;

int m;
int x[111111];
int y[111111];
map<pii,int> id;
set<int> v[111111];
set<int> vg[111111];

bool u[111111];
set<int> c;

bool canremove(int i){
	bool all_st = true;
	for(set<int>::iterator it = vg[i].begin();it!=vg[i].end();++it){
		int val = *it;
		if(v[val].size()==1) all_st=false;
	}
	//cout<<"check " << i<< " " <<all_st<<' '<<v[4].size()<<' '<<vg[4].size()<<endl;
	return all_st;
}

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>m;
	REP(i,m)scanf("%d %d",x+i,y+i),id[pii(x[i],y[i])]=i;

	REP(i,m){
		FOR(dx,-1,2){
			int nx = x[i] + dx;
			int ny = y[i] - 1;
			if(id.count(pii(nx,ny))){
				v[i].insert(id[pii(nx,ny)]);
				vg[id[pii(nx,ny)]].insert(i);
			}
		}
	}
	REP(i,m)if(canremove(i)) c.insert(i);

	ll res = 0;
	int step = 0;

	while(!c.empty()){
		int curr = 0;
		if(step%2==0){
			set<int>::iterator it = c.end();
			--it;
			curr = *it;
			c.erase(it);
		}else{
			curr = *c.begin();
			c.erase(c.begin());
		}
		//cout<<"PICK "<<curr<<endl;
		res = res * m + curr;
		res %= mod;
		u[curr]=true;
		for(set<int>::iterator it = v[curr].begin();it!=v[curr].end();++it){
			c.erase(*it);
			vg[*it].erase(curr);
		}
		for(set<int>::iterator it = vg[curr].begin();it!=vg[curr].end();++it){
			c.erase(*it);
			v[*it].erase(curr);
		}
		for(set<int>::iterator it = v[curr].begin();it!=v[curr].end();++it){
			if(canremove(*it)) c.insert(*it);
		}
		for(set<int>::iterator it = vg[curr].begin();it!=vg[curr].end();++it){
			if(canremove(*it)) c.insert(*it);
		}
		for(int dx=-2;dx<=2;dx++){
			int nx = x[curr]+ dx;
			int ny = y[curr];
			if(id.count(pii(nx,ny))){
				int t = id[pii(nx,ny)];
				if(!u[t]){
					c.erase(t);
					if(canremove(t)) c.insert(t);
				}
			}
		}
		step++;
	}


	cout<<res<<endl;
	
#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}