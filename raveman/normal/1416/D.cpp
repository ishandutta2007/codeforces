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

int n,m,q;
int p[222222];
bool g[333333];
pii e[333333];
int t[555555];
int x[555555];
int b[555555];
pii mg[555555];

int pp[222222];
set<int>* sz[222222];
set<int> ors[222222];
int P(int x){return pp[x]==x?x:pp[x]=P(pp[x]);}

pii merge(int i){
	int p1 = P(e[i].first);
	int p2 = P(e[i].second);
	if(p1==p2){
		return pii(-1,-1);
	}else{
		int s1 = sz[p1]->size();
		int s2 = sz[p2]->size();
		if(s1<s2)swap(p1,p2);
		pp[p2]=p1;
		for(set<int>::iterator it = sz[p2]->begin();it!=sz[p2]->end();it++)
			sz[p1]->insert(*it);
		return pii(p1,p2);
	}
}

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n>>m>>q;
	REP(i,n)scanf("%d",p+i);
	REP(i,m){
		int x,y;
		scanf("%d %d",&x,&y);
		e[i]=pii(x-1,y-1);
	}
	REP(i,q)scanf("%d %d",t+i,x+i),x[i]--;

	REP(i,q)if(t[i]==2)g[x[i]]=1;

	REP(i,n)pp[i]=i,ors[i].insert(-p[i]),sz[i]=&ors[i];
	REP(i,m)if(!g[i])merge(i);
	vi res;
	for(int i=q-1;i>=0;i--){
		if(t[i]==1){
			b[i] = P(x[i]);
			/*int p1 = P(x[i]-1);
			if(sz[p1]->empty())res.pb(0);
			else{
				res.pb(-(*sz[p1]->begin()));
				sz[p1]->erase(sz[p1]->begin());
			}*/
		}else{
			mg[i]=merge(x[i]);
		}
	}
	REP(i,q){
		if(t[i]==1){
			if(sz[b[i]]->empty()) res.pb(0);
			else{
				res.pb(-(*sz[b[i]]->begin()));
				sz[b[i]]->erase(sz[b[i]]->begin());
			}
		}else{
			int p1 = mg[i].first;
			int p2 = mg[i].second;
			if(p1==-1)continue;
			vi toremove;
			for(set<int>::iterator it = sz[p2]->begin();it!=sz[p2]->end();it++){
				if(!sz[p1]->count(*it))toremove.pb(*it);
				else sz[p1]->erase(*it);
			}
			REP(z,toremove.size())sz[p2]->erase(toremove[z]);
		}
	}
	REP(i,res.size())cout<<res[i]<<'\n';



#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}