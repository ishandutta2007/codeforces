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

int n,k;
int a[111111];
int c[111111];
set<pair<ll,int>> s;

ll solve(int pos,int cnt){
	if(cnt>a[pos])return a[pos];

	int t1 = a[pos]/cnt;
	int c1 = cnt;
	int t2 = t1 + 1;
	int c2 = a[pos] - t1*c1;
	c1-=c2;
	//cout<<pos<<' '<<cnt<<' '<<t1<<' '<<t2<<' '<<c1<<' '<<c2<<endl;
	return ll(t1)*t1*c1 + ll(t2)*t2*c2;
}

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n>>k;
	REP(i,n)scanf("%d",a+i),c[i]=1;
	ll sum=0;
	REP(i,n){
		s.insert(make_pair(-solve(i,c[i])+solve(i,c[i]+1),i));
		sum += solve(i,1);
	}
	//cout<<solve(0,1)<<' '<<solve(0,2)<<' '<<solve(0,3)<<endl;
	REP(i,k-n){
		int pos = s.begin()->second;
		//cout<<pos<<' '<<s.begin()->first<<endl;
		sum += s.begin()->first;
		s.erase(s.begin());
		c[pos]++;
		s.insert(make_pair(-solve(pos,c[pos])+solve(pos,c[pos]+1),pos));
	}
	cout<<sum<<endl;

	
#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}