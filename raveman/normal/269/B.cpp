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
double x[5555];
int s[5555];
int d[5555][5555];

int go(int pos,int color){
	if(color==0) return pos+1;
	if(pos<0) return 0;
	if(d[pos][color]!=-1)
		return d[pos][color];
	int res = 1e9;
	if(s[pos]==color)
		res=min(res,go(pos-1,color));
	res=min(res,go(pos-1,color)+1);
	res=min(res,go(pos,color-1));
	return d[pos][color]=res;
}

int main(){
#ifdef LocalHost
	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
#endif

	cin>>n>>m;
	REP(i,n) scanf("%d %lf",s+i,x+i);
	CL(d,-1);

	cout<<go(n-1,m)<<endl;

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}