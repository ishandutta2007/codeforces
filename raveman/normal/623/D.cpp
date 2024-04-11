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
#define CL(a,b)				memset(a,b,sizeof a)
#define pb				push_back

int p[111];
double c[111];
int nm[111];
double pnm[111];
int n;

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n;
	REP(i,n)cin>>p[i];
	sort(p,p+n);
	double res = 0;
	REP(i,n)pnm[i]=1;
	priority_queue<pair<double,int>> pq;
	REP(i,n){
		pq.push(make_pair(1e100+p[i],i));
	}
	int numzero = n;
	double rest = 1;
	REP(it,1000000){
		double cost = pq.top().first;
		int pos = pq.top().second;
		pq.pop();
		if(c[pos]==0)numzero--;
		else rest/=c[pos];
		c[pos]=c[pos]+(1-c[pos])*p[pos]/100.;
		rest*=c[pos];
		double mult = it+1;
		if(numzero>0)mult*=0;
		else mult*=rest/c[pos];
		mult*=p[pos]/100.;
		mult*=pnm[pos];
		
		res+=mult;
		//cout<<it<<' '<<mult<<' '<<pos<<' '<<cost<<endl;
		if(mult< (res - 1) * 1e-20) break;
		nm[pos]++;
		pnm[pos]*=(1-p[pos]/100.);
		pq.push(make_pair(p[pos]*pnm[pos]/c[pos],pos));
	}
	printf("%.10lf\n",res);
	

#ifdef LocalHost
	//printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}