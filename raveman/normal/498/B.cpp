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

int n,T;

double x[5055][5055];

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n>>T;
	x[0][0] = 1;
	int p,t;
	double res=0;
	REP(i,n){
		cin>>p>>t;
		double pr = p / 100.;
		double ipr = 1 - pr;
		double guess = pow(ipr, t);
		double* x1 = x[i];
		double* x2 = x[i+1];
		double sum = 0;
		for(int j=0;j<=T;j++){
			x2[j] = sum * pr;
			sum = sum * ipr + (j<T?x1[j]:0.);
			if(j-t>=0){
				sum -= x1[j-t]*guess;
				x2[j] += x1[j-t]*guess;
			}
		}

		res += sum  * i;
	}
	REP(i,n+1){
		res+=x[i][T]*i;
		//cout<<"1: " << i << ' ' <<T<<" = "<<x[i][T]<<endl;
	}
	REP(i,T){
		res+=n*x[n][i];
		//cout<<"2: " << n << ' ' <<i<<" = "<<x[n][i]<<endl;
	}
	printf("%.10lf\n",res);

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}