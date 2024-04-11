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

int n;
int a[111111];
set<int> p;
set<int> m1;

int gcd(int a,int b){
	while(a&&b)
		if(a>b)a%=b;
		else b%=a;
	return a+b;
}

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	int tc;
	cin>>tc;
	REP(TC,tc){
		cin>>n;
		p.clear();
		m1.clear();
		REP(i,n)scanf("%d",a+i),p.insert(i);
		vi d;
		REP(i,n)if(gcd(a[i],a[(i+1)%n])==1)m1.insert(i);

		int pos = 0;
		while(!m1.empty()){
			set<int>::iterator it = m1.lower_bound(pos);
			if(it==m1.end())it=m1.begin();
			int g1 = *it;
			m1.erase(it);

			it = p.lower_bound(g1+1);
			if(it==p.end())it=p.begin();
			
			int op = *it;
			p.erase(it);
			m1.erase(op);


			d.pb(op);

			if(p.empty())break;

			it=p.lower_bound(op);
			if(it==p.end())it=p.begin();

			int nop = *it;

			if(gcd(a[g1],a[nop])==1)m1.insert(g1);

			pos = nop;
		}
		
		cout<<d.size();
		REP(i,d.size())printf(" %d",d[i]+1);puts("");
	}


#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}