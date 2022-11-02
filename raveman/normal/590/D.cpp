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

int n,k,s;
int a[155];

int d1[151][6000];
int d2[151][6000];

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n>>k>>s;
	REP(i,n)cin>>a[i];	
	CL(d1,-1);
	CL(d2,-1);
	d1[0][0]=0;
	int lim = min(6000,s+1),t;
	REP(i,n){
		CL(d2,-1);
		REP(j,i+2)REP(z,lim){
			d2[j][z]=d1[j][z];
			if(j && z-(i+1-j)>=0){
				if(d1[j-1][z-(i+1-j)]!=-1){
					if(d2[j][z]==-1 || d2[j][z]>d1[j-1][z-(i+1-j)]+a[i]){
						//cout<<i<<' '<<j<<' '<<z<<endl;
						d2[j][z]=d1[j-1][z-(i+1-j)]+a[i];
					}
				}
			}
		}
		//if(i==0)cout<<d2[1][0]<<' '<<d1[0][0]<<endl;
		memcpy(d1,d2,sizeof d1);
	}
	int best=1e9;
	
	REP(i,lim)if(d2[k][i]!=-1)best=min(best,d2[k][i]);
	cout<<best<<endl;

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}