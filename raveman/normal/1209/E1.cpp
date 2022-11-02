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
int a[12][2000];
vi c[12];

int r[12][1<<12];
int d[12][1<<12];


int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	int tc;
	cin>>tc;
	REP(TC,tc){
		cin>>n>>m;
		REP(i,n)REP(j,m)scanf("%d",&a[i][j]);
		REP(i,min(n,m)){
			int mx = 0,ps=-1;
			REP(ii,n)REP(jj,m){
				if(mx<a[ii][jj]){
					mx=a[ii][jj];
					ps=jj;
				}
			}
			c[i].clear();
			REP(j,n)c[i].pb(a[j][ps]),a[j][ps]=0;
		}
		m=min(n,m);
		CL(r,0);
		REP(i,m){
			REP(k,1<<n){
				int sum=0;
				REP(j,n)if(k&(1<<j))sum+=c[i][j];
				int tk = k;
				REP(j,n){
					r[i][tk]=max(r[i][tk],sum);
					tk*=2;
					if(tk&(1<<n))tk^=(1<<n),tk^=1;
				}
			}
		}
		CL(d,0);
		REP(i,m)REP(j,1<<n){
			d[i][j]=max(d[i][j],(i-1>=0?d[i-1][j]:0));
			for(int p=j;p>0;p=((p-1)&j)){
				d[i][j]=max(d[i][j],r[i][p]+(i-1>=0?d[i-1][j^p]:0));
			}
		}
		cout<<d[m-1][(1<<n)-1]<<endl;
	}

#ifdef LocalHost
	//printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}