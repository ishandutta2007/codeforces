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
#define CL(a,b)			memset(a,b,sizeof a)
#define pb				push_back	

int n,m,cl,ce,v;
int l[111111];
int e[111111];

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n>>m>>cl>>ce>>v;
	REP(i,cl)scanf("%d",l+i);
	REP(i,ce)scanf("%d",e+i);
	int q;
	cin>>q;
	int x1,x2,y1,y2;
	REP(TC,q){
		scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
		if(x1==x2)printf("%d\n",abs(y1-y2));
		else{
			if(x1>x2)swap(x1,x2);
			if(y1>y2)swap(y1,y2);
			int res = 1e9;
			// l
			int lp = lower_bound(l,l+cl,y1)-l;
			FOR(dx,-1,2)if(dx+lp>=0 && dx+lp<cl){
				res = min(res, abs(l[lp+dx]-y1)+abs(x2-x1)+abs(l[lp+dx]-y2));
			}
			// 
			int ep = lower_bound(e,e+ce,y1)-e;
			FOR(dx,-1,2)if(dx+ep>=0 && dx+ep<ce){
				res = min(res, abs(e[ep+dx]-y1)+(abs(x1-x2)+v-1)/v+abs(e[ep+dx]-y2));
			}
			printf("%d\n",res);
		}
	}

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}