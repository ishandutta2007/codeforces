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

vi v[2222];
int a[2222];

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	int n;
	cin>>n;
	cout<<"? 1"<<endl;
	cout.flush();
	FOR(i,1,n+1)scanf("%d",&a[i]);
	int n0=0,n1=0;
	FOR(i,1,n+1){
		if(a[i]%2==0)n0++;
		else n1++;
	}

	int tp = 0;
	if(n0<=n1){
		FOR(i,1,n+1)if(a[i]==1){
			v[1].pb(i);
			v[i].pb(1);
		}
	}else{
		tp=1;
	}
	FOR(i,2,n+1)if((a[i]%2)==tp){
		cout<<"? "<<i<<endl;
		cout.flush();
		FOR(j,1,n+1){
			int x;
			scanf("%d",&x);
			if(x==1){
				v[i].pb(j);
				v[j].pb(i);
			}
		}
	}

	cout<<"!"<<endl;
	FOR(i,1,n+1)REP(j,v[i].size())if(i<v[i][j])printf("%d %d\n",i,v[i][j]);

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}