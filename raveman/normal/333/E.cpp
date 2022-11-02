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
int x[3333],y[3333];

int d[3333][3333];
#include<bitset>
ll bs[3000][50];
int aa[3333*3333/2];
int pos_a;
vi v;
int glob;
int ps1,ps2;

bool good(int r){
	REP(i,n){
		CL(bs[i],0);
		ps2 = ps1 = 0;
		REP(j,i){
			if(d[j][i]>=r){
				REP(inter,ps1+1)if(bs[i][inter]&bs[j][inter]) return 1;
				bs[i][ps1]|=(1ll<<ps2);
			}
			if((++ps2)==60)ps2=0,++ps1;
		}
	}
	return 0;
}

int main(){
#ifdef LocalHost
	freopen("input.txt","r",stdin);
#endif

	cin>>n;
	//n=3000;
	REP(i,n) scanf("%d %d",x+i,y+i);
	REP(i,n)REP(j,i){
		aa[pos_a] = d[i][j]=d[j][i]=(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
		pos_a++;
	}
	sort(aa,aa+pos_a);
	int a = 0, b = pos_a-1;
	double best=0;
	while(a<=b){
		int s = (a+b)/2;
		if(good(aa[s])) best=aa[s],a=s+1;
		else b=s-1;
	}
	printf("%.10lf\n",sqrt(best)/2.0);

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}