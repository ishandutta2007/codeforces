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
set<int> v[222222];
vi v2[222222];

vi invm[222222];
bool  p[222222];
int val[222222];

set<int> ua;

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n>>m;	
	CL(val,-1);
	queue<int> trivial_variable;
	REP(i,n){
		int x,t;
		scanf("%d",&x);		
		REP(j,x){
			scanf("%d",&t);
			v[i].insert(t);
			v2[i].pb(t);
			invm[abs(t)].pb(i);

			if(x==1){
				p[i]=true;
				//cout<<"here "<<i<<endl;
				if(val[abs(t)]!=-1 && val[abs(t)]!=(t>0?1:0)) {
					puts("NO");
					return 0;
				}
				
				if(val[abs(t)]==-1){					
					val[abs(t)] = t>0?1:0;
					trivial_variable.push(abs(t));
				}
			}
		}		
	}

	FOR(i,1,m+1){
		ua.insert(i);
		if(val[i]!=-1)continue;
		if(invm[i].size()==0){
			val[i]=0;
			trivial_variable.push(i);
			continue;
		}
		if(invm[i].size()==1){
			int t1 = invm[i][0];
			val[i]=v[t1].count(i)?1:0;
			trivial_variable.push(i);
			continue;
		}

		if(invm[i].size()==2){
			int t1 = invm[i][0];
			int t2 = invm[i][1];
			if(v[t1].count(i) && v[t2].count(i)){
				val[i]=1;
				trivial_variable.push(i);
				continue;
			}
			if(v[t1].count(-i) && v[t2].count(-i)){
				val[i]=0;
				trivial_variable.push(i);
				continue;
			}
		}
	}

	for(int iter=0;iter<m;iter++){
		int ver = -1;
		if (!trivial_variable.empty()) {
			ver = trivial_variable.front();
			trivial_variable.pop();
		}else{
			ver = *ua.begin();
			val[ver] = 1;
		}
		ua.erase(ver);
		//cout<<ver<<' '<<val[ver]<<endl;
		REP(i,invm[ver].size()){
			int pos = invm[ver][i];
			if(p[pos])continue;			
			if (v[pos].count(ver) && val[ver]==1 || v[pos].count(-ver) && val[ver]==0){
				p[pos] = true;
				// sat
				v[pos].erase(ver);
				v[pos].erase(-ver);
				for(set<int>::iterator it = v[pos].begin();it!=v[pos].end();it++){
					int ver2 = *it;
					int nval = ver2>0?1:0;
					ver2=abs(ver2);
					if (val[ver2]==-1){
						val[ver2] = 1 - nval;
						trivial_variable.push(ver2);
					}
				}
			} else {
				// !sat
				v[pos].erase(ver);
				v[pos].erase(-ver);
				if (v[pos].size() == 1){
					int ver2 = *v[pos].begin();
					int nval = ver2>0?1:0;
					//cout<<ver2<<' '<<nval<<endl;
					if (val[abs(ver2)]!=-1 && val[abs(ver2)] !=nval){
						puts("NO");
						return 0;
					}
					if (val[abs(ver2)]==-1){
						val[abs(ver2)]= nval;
						trivial_variable.push(abs(ver2));
					}
				}
			}
		}
	}
	REP(i,n){
		bool sat = false;
		REP(j,v2[i].size()){
			if(v2[i][j] > 0 && val[v2[i][j]]==1) sat=true;
			if(v2[i][j] <0 && val[-v2[i][j]]==0) sat=true;
		}
		if(!sat){
			puts("NO");
			return 0;
		}
	}
	puts("YES");
	REP(i,m){
		while(val[i+1]==-1);
		printf("%d",val[i+1]);
	}
	puts("");

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}