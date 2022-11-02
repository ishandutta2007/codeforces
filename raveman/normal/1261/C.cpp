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

int n,m;
vector<vi> a;
vector<vi> b;

vector<vi> res;

char _tmp[1<<20];

vector<vi> c;
vector<vi> d;

bool good(ll T){
	c.clear();d.clear();
	c.resize(n);d.resize(n);
	REP(i,n)c[i].resize(m),d[i].resize(m);
	REP(i,n)REP(j,m){
		int cx1 = i - T, cy1 = j - T;
		int cx2 = i + T, cy2 = j + T;
		if(cx1>=0 && cy1>=0  && cx2<n && cy2<m){
			int sum = b[cx2][cy2];
			if(cx1-1>=0) sum -= b[cx1-1][cy2];
			if(cy1-1>=0) sum -= b[cx2][cy1-1];
			if(cx1-1>=0 && cy1-1>=0) sum += b[cx1-1][cy1-1];
			if (sum == (1+T+T)*(1+T+T)){
				c[i][j]=1;
			}
		}
	}
	REP(i,n)REP(j,m){
		d[i][j]=c[i][j];
		if(i)d[i][j]+=d[i-1][j];
		if(j)d[i][j]+=d[i][j-1];
		if(i&&j)d[i][j]-=d[i-1][j-1];
	}
	REP(i,n)REP(j,m){
		if(!a[i][j])continue;
		int cx1 = i - T, cy1 = j - T;
		int cx2 = i + T, cy2 = j + T;
		cx1=max(cx1,0);cy1=max(cy1,0);
		cx2=min(cx2,n-1);cy2=min(cy2,m-1);
		int sum = d[cx2][cy2];
		if(cx1-1>=0) sum -= d[cx1-1][cy2];
		if(cy1-1>=0) sum -= d[cx2][cy1-1];
		if(cx1-1>=0 && cy1-1>=0) sum += d[cx1-1][cy1-1];
		if (sum == 0) return 0;
	}
	res=c;
	return 1;
}

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n>>m;
	a.resize(n);b.resize(n);
	REP(i,n)a[i].resize(m),b[i].resize(m);
	REP(i,n){
		scanf(" %s",_tmp);
		REP(j,m)a[i][j]=(_tmp[j]=='.'?0:1);
	}

	REP(i,n)REP(j,m){
		b[i][j]=a[i][j];
		if(i)b[i][j]+=b[i-1][j];
		if(j)b[i][j]+=b[i][j-1];
		if(i&&j)b[i][j]-=b[i-1][j-1];
	}

	int best=-1;
	int f=0,t=min(n,m);
	while(f<=t){
		int s=(f+t)/2;
		if(good(s))best=s,f=s+1;
		else t=s-1;
	}
	cout<<best<<endl;
	REP(i,n){
		REP(j,m)printf("%c",res[i][j]?'X':'.');
		puts("");
	}


#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}