//#pragma comment(linker, "/STACK:60777216")  

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
typedef pair<int,pii>	p3;
typedef pair<ll,ll> pl;
typedef pair<int,pl>	p3l;
typedef pair<double,double>	pdd;
typedef vector<int> vi;
typedef vector<ld> vd;

#define FOR(i,a,b)		for(int i=(a);i<(b);i++)	
#define REP(i,n)		FOR(i,0,n)
#define SORT(v)			sort((v).begin(),(v).end())
#define UN(v)			SORT(v),(v).erase(unique((v).begin(),(v).end()),(v).end())
#define CL(a,b)			memset(a,b,sizeof a)
#define pb				push_back

int a[222222];
int as[222222];
int b[222222];
int bs[222222];

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	int tc;
	cin>>tc;
	REP(TC,tc){
		int n;
		cin>>n;
		REP(i,n)scanf("%d",&a[i]);
		REP(i,n)scanf("%d",&b[i]);
		FOR(i,n,222222){
			a[i]=100;
			b[i]=0;
		}
		sort(a,a+n);
		sort(b,b+n);
		REP(i,222222){
			as[i]=a[i];
			if(i)as[i]+=as[i-1];
		}
		REP(i,n){
			bs[i]=b[i];
			if(i)bs[i]+=bs[i-1];
		}
		for(int r=n;;r++){
			int c = r - (r/4);
			int ms = as[r-1]-(r-1-c>=0?as[r-1-c]:0);
			int is = bs[n-1]-(n-1-c>=0?bs[n-1-c]:0);
			//cout<<ms<<' '<<is<<' '<<c<<endl;
			if(ms>=is){
				cout<<r-n<<endl;
				break;
			}
		}
	}


#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}