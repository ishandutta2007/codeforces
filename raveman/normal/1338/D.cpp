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

int b;
vi v[111111];

pii dfs(int ver,int par=-1){
	pii res;
	vi dont,other;
	REP(i,v[ver].size()){
		if(v[ver][i]==par)continue;
		pii t = dfs(v[ver][i],ver);
		dont.pb(t.second);
		other.pb(max(t.first,t.second));
	}
	SORT(dont);
	SORT(other);
	int tmp = 0;
	// first - take it
	int t1 = 1;
	if(dont.size()>0) t1+= dont.back();
	if(dont.size()>1) t1+= dont[dont.size()-2];
	// second - don't take it
	int t2 = 0;
	if(other.size()>0)t2+=other.back();
	if(other.size()>1)t2+=other[other.size()-2];
	if(other.size()>2)t2+=other.size()-2;
	if(par!=-1)t2++;
	b=max(b,t1);
	b=max(b,t2);


	// first
	res.first=1;
	if(dont.size()>0)res.first+=dont.back();
	//second
	res.second=0;
	if(other.size()>0)res.second+=other.back();
	if(other.size()>1)res.second+=other.size()-1;

	return res;
}

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	int n;
	cin>>n;
	REP(i,n-1){
		int x,y;
		scanf("%d %d",&x,&y);
		x--,y--;
		v[x].pb(y);
		v[y].pb(x);
	}
	
	if(0&&n==100000){
		REP(i,n)if(v[i].size()>1){
			b=0;
			pii t= dfs(i);
			if(b==229)
			cout<<max(b,max(t.first,t.second))<<' '<<v[i].size()<<endl;
		}
	}
	REP(i,n)if(v[i].size()>1){
		b=0;
		pii t = dfs(i);
		break;
	}
	//REP(i,10)dfs(rand()%n);
	cout<<b<<endl;

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}