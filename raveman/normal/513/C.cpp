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

int n;
int l[5],r[5];

double d[11111];

void solve(int exclude){
	CL(d,0);
	FOR(i,1,11111){
		d[i]=d[i-1];
		FOR(j,1,1<<n){
			if(j&(1<<exclude)) continue;
			double prob = 1;
			REP(k,n){
				if(k==exclude)continue;
				if(j&(1<<k)) {
					if(l[k]<=i && i<=r[k]){
						prob /= (r[k]-l[k]+1.);
					}else prob=0;
				}else{
					prob *= max(0.,(min(r[k],i-1) - l[k]+1)/(r[k]-l[k]+1.));
				}
			}
			//cout<<"add "<<i<<' '<<prob<<endl;
			d[i] += i * prob;
		}
		//cout<<"EX "<<exclude<<" "<<i<<" = " <<d[i]<<endl;
	}
}

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n;
	REP(i,n)cin>>l[i]>>r[i];
	double res = 0;
	REP(i,11111){
		REP(j,1<<n){
			if(j&(j-1)){
				double prob = 1;
				REP(k,n){
					if(j&(1<<k)) {
						if(l[k]<=i && i<=r[k]){
							prob /= (r[k]-l[k]+1.);
						}else prob=0;
					}else{
						prob *= max(0.,(min(r[k],i-1) - l[k]+1)/(r[k]-l[k]+1.));
					}
				}
				res += prob * i;
			}
		}
	}
	REP(i,n){
		solve(i);
		FOR(j,l[i],r[i]+1){
			res += d[j-1] / (r[i]-l[i]+1.);
		}
	//	cout<<i<<" "<<res<<endl;
	}
	printf("%.10lf\n",res);

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}