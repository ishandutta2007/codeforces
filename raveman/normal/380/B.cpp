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
int tp[7777];
int l[7777];
int r[7777];
int x[7777];
int t[7777];
int v[7777];
int u[1111111];
int now;

vi op[7777];

int d[2222222];

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	FOR(i,1,2222222){
		d[i]=d[i-1]+1;
		if((i&(i-1))==0)d[i]++;
	}
	cin>>n>>m;
	REP(i,m){
		scanf("%d",tp+i);
		if(tp[i]==1){
			scanf("%d %d %d %d",t+i,l+i,r+i,x+i);
			op[t[i]].pb(i);
		}else{
			scanf("%d %d",t+i,v+i);
			int from = v[i];
			int to = v[i];
			int res = 0;
			now++;
			for(int j=t[i];j<=n;j++){
				REP(z,op[j].size()) if(from>r[op[j][z]] || to<l[op[j][z]]) continue;
				else{
					if(u[x[op[j][z]]]!=now){
						res++;
						u[x[op[j][z]]]=now;
					}
				}
				int n1 = d[from - 1];
				int n2 = d[to];
				from = n1 + 1;
				to = n2;
			}
			printf("%d\n",res);
		}
	}

	/*return 0;
	cin>>n;
	REP(i,n)scanf("%d",b+i);
	double sum = 0;
	REP(i,n)FOR(j,i,n){
		vi t;
		FOR(k,i,j+1)t.pb(b[k]);
		SORT(t);
		double x =0;
		REP(k,t.size()) x=(x+t[k])/2;
		sum += x;

	}
	printf("%.10lf\n",sum/n/n);

	*/
#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}