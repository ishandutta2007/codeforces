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

int main(){	
#ifdef LocalHost
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	int tc;
	cin>>tc;
	REP(TC,tc){
		int n;
		cin>>n;
		cout<<"? 1 "<<n<<endl;
		cout.flush();
		ll total;
		cin>>total;
		int from=1,to=n;
		int best=-1;
		while(from<=to){
			int m=(from+to)/2;
			cout<<"? "<<m<<" "<<n<<endl;
			cout.flush();
			ll x;
			cin>>x;
			if(x==total){
				best=m;
				from=m+1;
			}else{
				to=m-1;
			}
		}
		cout<<"? "<<best+1<<" "<<n<<endl;
		cout.flush();
		ll total_without_one;
		cin>>total_without_one;
		ll x = (total-total_without_one+1);
		ll y2 = total - x*(x-1)/2;
		//cout<<x<<' '<<y2<<endl;
		ll y = 0;
		ll fr=0;
		ll tt=n;
		while(fr<=tt){
			ll m=(fr+tt)/2;
			//cout<<"test "<<m<<endl;
			if(y2==m*(m-1)/2){y=m;break;}
			if(y2<m*(m-1)/2)tt=m-1;
			else fr=m+1;
		}
		//cout<<y2<<' '<<y<<endl;
		cout<<"! "<<best<<" "<<best+x<<" "<<best+x+y-1<<endl;
	}
		
#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}