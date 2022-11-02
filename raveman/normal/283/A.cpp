#pragma comment(linker, "/STACK:60777216")  

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

ll a[311111];
ll s[311111];

int main(){
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	int n;
	cin>>n;
	int m = 1;
	double sum = 0;
	REP(i,n){
		int t;
		scanf("%d",&t);
		if(t==1){
			int x,y;
			scanf("%d %d",&x,&y);
			s[x-1]+=y;
			sum += double(x)*y;
		}else if(t==2){
			int x ;
			scanf("%d",&x);
			s[m] = 0;
			a[m] = x;
			m++;
			sum += x;
		}else if(t==3){
			m--;
			sum -= a[m];
			a[m]=0;
			sum -= s[m];
			s[m-1] += s[m];
			s[m]=0;
		}

		printf("%.6lf\n",sum/m);
	}

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}