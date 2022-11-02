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

const int mod = 1000000007;

int r[155][155][155][2][2];

int sum[155][155][2][2];
int bb[155][2][2];
int ea[155][2][2];

void add(int &x,int val){
	x+=val;
	if(x>=mod) x-=mod;
	if(x<0) x+=mod;
}
int n,m;

int t[155][155][2][2];
void generatenext(int i){
	memcpy(t,r[i],sizeof t);
	for(int d=m;d>=1;d--)REP(start,m-d+1)REP(i1,2)REP(i2,2){
		if(d>1)add(t[start+1][start+d-1][0][i2],t[start][start+d-1][i1][i2]);
	}
	for(int d=m;d>=1;d--)REP(start,m-d+1)REP(i1,2)REP(i2,2){
		if(d>1)add(t[start][start+d-2][i1][0],t[start][start+d-1][i1][i2]);
	}
	for(int d=1;d<=m;d++)REP(start,m-d+1)REP(i1,2)REP(i2,2){
		if(start-1>=0 && i1)add(t[start-1][start+d-1][i1][i2],t[start][start+d-1][i1][i2]);
	}
	for(int d=1;d<=m;d++)REP(start,m-d+1)REP(i1,2)REP(i2,2){
		if(start+d<m && i2)add(t[start][start+d][i1][i2],t[start][start+d-1][i1][i2]);
	}
	
	memcpy(r[i+1],t,sizeof t);
}

int main(){
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n>>m;
	int res = 0;
	REP(i,n){
		//st1
		if(i)generatenext(i-1);
		//st2
		REP(j,m)FOR(k,j,m)
			add(r[i][j][k][1][1], 1);

		REP(j,m)REP(k,m)REP(i1,2)REP(i2,2)if( r[i][j][k][i1][i2]){
			add(res, r[i][j][k][i1][i2]);
			//cout<<i<<' '<<j<<' '<<k<<' '<<i1<<' '<<i2<<' '<<" = " << r[i][j][k][i1][i2]<<endl;
		}
	}
	cout<<res<<endl;

	
#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}