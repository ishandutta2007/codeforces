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

double d[101][1001];

double pw[101];
pii a[101];
int n;
double c,t;

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	pw[0]=1/0.9;
	FOR(i,1,101)pw[i]=pw[i-1]/0.9,pw[i]=min(pw[i],1e10);

	int tc;
	cin>>tc;
	REP(TC,tc){
		cin>>n;
		cin>>c>>t;
		REP(i,n)cin>>a[i].first>>a[i].second;
		sort(a,a+n);
		reverse(a,a+n);

		double v;
		REP(i,101)REP(j,1001)d[i][j]=-1;
		d[0][0]=0;
		REP(i,n){
			for(int j=i;j>=0;j--)FOR(k,j,10*j+1)if((v=d[j][k])>=0){
				// take
				double &r = d[j+1][k+a[i].second];
				if(r<0 || r>v+a[i].first*pw[j]) r = v + a[i].first * pw[j];
			}
		}
		int res = 0;
		REP(i,101)REP(j,1001)if((v=d[i][j])>=0){
			//cout<<i<<' '<<j<<' '<<v<<endl;
			double rt = t - i * 10;

			if (v<=rt) res =max(res,j);
			//rt = A + B

			//v/(1+c*A) <= rt-A
			//v <= (rt-A)*(1+c*A)
			//v <= rt+rt*c*A-A-c*A*A
			// c*A*A+A-rt*c*A-rt+v<=0
			// AAc+A(1-rt*c)-rt+v<=0
			// A in [0, rt]

			double x = -(1-rt*c)/2 /c;
			//cout<<"A="<<x<<endl;
			if(x>=0 && x<=rt){
				if (v/(1+c*x)<=rt-x){
			//		cout<<"YES "<<v/(1+c*x)<<' '<<rt-x<<endl;
					res=max(res,j);
				}
			}
		}
		cout<<res<<endl;
	}

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}