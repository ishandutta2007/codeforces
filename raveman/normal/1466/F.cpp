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

const int mod = 1000000007;

int n,m;
vi    v[555555];
int   p[555555];
bool ho[555555];

int P(int x){return p[x]==x?x:p[x]=P(p[x]);}

int   p2[555555];

int P2(int x){return p2[x]==x?x:p2[x]=P2(p2[x]);}

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n>>m;
	REP(i,n){
		int x;
		scanf("%d",&x);
		REP(j,x){
			int y;
			scanf("%d",&y);
			y--;
			v[i].pb(y);
		}
	}

	REP(i,m+1)p[i]=i,p2[i]=i;
	REP(i,n)if(v[i].size()==2){
		int p1 = P(v[i][0]);
		int p2 = P(v[i][1]);
		if(p1!=p2)p[p1]=p2;
	}

	REP(i,n)if(v[i].size()==1)ho[P(v[i][0])]=1;

	int res=1;
	vi r;
	REP(i,n){
		if(v[i].size()==1){
			if(P2(v[i][0])!=m){
				r.pb(i);
				p2[P2(v[i][0])]=m;
			}
		}else{
			int pp1 = P2(v[i][0]);
			int pp2 = P2(v[i][1]);
			if(pp1!=pp2){
				r.pb(i);
				if(pp1==m)p2[pp2]=m;
				else if(pp2==m)p2[pp1]=m;
				else p2[pp1]=pp2;
			}
		}
	}
	REP(i,r.size())res=(res*2)%mod;
	cout<<res<<' '<<r.size()<<endl;
	REP(i,r.size())printf("%d ",r[i]+1);
	puts("");


#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}