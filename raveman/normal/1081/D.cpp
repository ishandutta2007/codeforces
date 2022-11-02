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

int n,m,k;
int p[111111];
int s[111111];
int P(int x){return p[x]==x?x:p[x]=P(p[x]);}

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n>>m>>k;
	REP(i,n)p[i]=i;
	REP(i,k){
		int x;
		scanf("%d",&x);
		x--;
		s[x]=1;
	}
	vector<pair<int,pii>> v;
	REP(i,m){
		int x,y,z;
		scanf("%d %d %d",&x,&y,&z);
		x--,y--;
		v.pb(make_pair(z,pii(x,y)));
	}
	SORT(v);

	REP(i,v.size()){
		int v1 = v[i].second.first;
		int v2 = v[i].second.second;
		v1 = P(v1);
		v2 = P(v2);
		if(v1!=v2){
			p[v1]=v2;
			s[v2]=s[v2]+s[v1];
		}
		if(s[v2]==k){
			REP(j,k)printf("%d ",v[i].first);
			puts("");
			break;
		}
	}
	

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}