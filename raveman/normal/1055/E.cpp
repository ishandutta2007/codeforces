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

int n,s,m,k;
int a[2222];
int l[2222];
int r[2222];

int t[2222];

int d[2222][2222];
int ba[2222];
int ts[2222];

int go(int pos,int sum){
	if(sum<=0) return 0;
	if(pos<0)return 2222;
	if(d[pos][sum]!=-1) return d[pos][sum];
	int res = go(pos-1,sum);
	if(ba[pos]!=-1){
		res=min(res,go(ba[pos]-1,sum-(ts[pos]-(ba[pos]-1>=0?ts[ba[pos]-1]:0)))+1);
	}
	return d[pos][sum]=res;
}

bool good(int val){
	CL(d,-1);
	REP(i,n)t[i]=(a[i]<=val?1:0);
	REP(i,n)ts[i]=t[i]+(i-1>=0?ts[i-1]:0);
	return go(n-1,k)<=m;
}

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n>>s>>m>>k;
	vi u;
	REP(i,n)scanf("%d",a+i),u.pb(a[i]);
	REP(i,s)scanf("%d %d",l+i,r+i),l[i]--,r[i]--;
	UN(u);

	REP(i,n)ba[i]=-1;
	REP(i,n){
		int lm=2222;
		REP(j,s)if(r[j]>=i && l[j]<=i){
			lm=min(lm,l[j]);
		}
		if(lm!=2222){
			ba[i]=lm;
			
		}
	}

	int best=-1;
	int from = 0, to = u.size() - 1;
	while(from<=to){
		int mid = (from+to)/2;
		if(good(u[mid]))best=mid,to=mid-1;
		else from=mid+1;
	}

	if(best==-1)puts("-1");
	else cout<<u[best]<<endl;

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}