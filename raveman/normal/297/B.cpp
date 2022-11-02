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

	
int main(){
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	int n,m,k;
	cin>>n>>m>>k;
	vi t(n+m);
	vi a(n);
	REP(i,n)scanf("%d",&a[i]),t[i]=a[i];
	vi b(m);
	REP(i,m)scanf("%d",&b[i]),t[i+n]=b[i];
	SORT(a);SORT(b);
	UN(t);
	REP(i,n) a[i]=lower_bound(t.begin(),t.end(),a[i])-t.begin();
	REP(i,m) b[i]=lower_bound(t.begin(),t.end(),b[i])-t.begin();

	bool can = 0;
	int n1 = 0, n2 = 0;
	int p1 = n - 1, p2 = m -1 ;
	for(int i = t.size()-1;i>=0;i--){
		while(p1>=0 && a[p1]==i) p1--,n1++;
		while(p2>=0 && b[p2]==i) p2--,n2++;
		if(n1>n2){can=1;break;}
	}

	puts(can?"YES":"NO");
	
#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}