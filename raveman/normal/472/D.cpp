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

int n;
int a[2222][2222];
int p[2222];
int P(int x){return p[x]==x?x:p[x]=P(p[x]);}

int b[2222][2222];
vector<pii>  m[2222];

bool good(int ver,int currv, int cost,int par=-1){
	//cout<<ver<<' '<<currv<<' '<<cost<<' '<<par<<endl;
	if(a[ver][currv]!=cost)return false;
	REP(i,m[currv].size())if(m[currv][i].first!=par){
		if(!good(ver,m[currv][i].first,cost+m[currv][i].second,currv)){
			return false;
		}
	}
	return true;
}

bool good(){
	REP(i,n)if(!good(i,i,0,-1)) return false;
	return true;
}

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n;
	REP(i,n)p[i]=i;
	vector<pair<int,pii > > v;
	REP(i,n)REP(j,n)scanf("%d",&a[i][j]),v.pb(make_pair(a[i][j],pii(i,j)));
	SORT(v);
	int num = 0;
	REP(i,v.size()){
		if(v[i].first==0)continue;
		if(P(v[i].second.first)==P(v[i].second.second)) continue;
		num++;
		b[v[i].second.first][v[i].second.second]=b[v[i].second.second][v[i].second.first]=v[i].first;
		p[P(v[i].second.first)]=P(v[i].second.second);

		//cout << v[i].second.first<<' '<<v[i].second.second<<endl;


		m[v[i].second.first].pb(pii(v[i].second.second,v[i].first));
		m[v[i].second.second].pb(pii(v[i].second.first,v[i].first));
	}

	if(num==n-1 && good()) puts("YES");
	else puts("NO");


#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}