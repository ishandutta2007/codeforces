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

int n,m;
set<int> a;
vi v[111111];

bool hasEdge(int p1,int p2){
	REP(i,v[p1].size()) if(v[p1][i]==p2) return true;
	return 0;
}

int d[111111];

int main(){
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n>>m;
	int x,y;
	REP(i,m){
		scanf("%d %d",&x,&y);
		x--,y--;
		v[x].pb(y);
		v[y].pb(x);
	}
	REP(i,n)a.insert(i);
	
	vector<pii> res;
	d[0] = 0;a.erase(0);
	int pos = 0;
	int need = m;
	while(a.size()>=10){
		bool found = 0;
		for(set<int>::iterator it = a.begin();it!=a.end();it++){
			int val = *it;
			if(need==0 || !hasEdge(d[pos],val)){
				if(need){
					need--;
					res.pb(pii(d[pos],val));
				}
				found=1;
				a.erase(val);
				pos++;
				d[pos] = val;
				break;
			}
		}
		if(!found){
			puts("-1");
			return 0;
		}
	}

	pos++;
	int ind = 0;
	for(set<int>::iterator it = a.begin();it!=a.end();it++){d[pos+ind] = *it;++ind;}
//	REP(i,n)cout<<d[i]<<' ';puts("");
	do{
		vector<pii> curr;
		//puts("new");
		//REP(i,n)cout<<d[i]<<' ';puts("");
		REP(i,ind){
			int prev = pos + i - 1;
			if(prev>=0 && curr.size()<need && !hasEdge(d[prev],d[prev+1])){
				//cout<<d[prev-1]<<' '<<d[prev]<<" !" << prev<<endl;
				curr.pb(pii(d[prev],d[prev+1]));
			}
		}
		if(curr.size()<need && !hasEdge(d[n-1],d[0]) && n>1){
			curr.pb(pii(d[0],d[n-1]));
		}
		if(curr.size()==need){
			REP(i,res.size())printf("%d %d\n",res[i].first+1,res[i].second+1);
			REP(i,curr.size())printf("%d %d\n",curr[i].first+1,curr[i].second+1);
			return 0;
		}
	}while(next_permutation(d+pos,d+pos+ind));
	puts("-1");

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}