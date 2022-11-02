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

int n,l,r;
int c[222222];

int cl[222222];
int cr[222222];

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	int tc;
	cin>>tc;
	REP(TC,tc){
		cin>>n>>l>>r;
		REP(i,n)scanf("%d",c+i),c[i]--;

		REP(i,n)cl[i]=cr[i]=0;
		REP(i,n)if(i<l)cl[c[i]]++;
		else cr[c[i]]++;

		int il=0;
		int pl=0;
		int ir=0;
		int pr=0;

		REP(i,n){
			int t = min(cl[i],cr[i]);
			cl[i]-=t;
			cr[i]-=t;
			if(cl[i]>0){
				if(cl[i]%2==1)il++;
				pl+=cl[i]/2;
			}else if(cr[i]>0){
				if(cr[i]%2==1)ir++;
				pr+=cr[i]/2;
			}
		}
		int cost=0;
		while(il>ir && pr>0){
			pr--;
			ir+=2;
		}
		while(ir>il && pl>0){
			pl--;
			il+=2;
		}

		cost+=pr;
		cost+=pl;

		int t = min(il,ir);
		cost+=t;
		il-=t;
		ir-=t;
		cost+=(il+ir);

		cout<<cost<<endl;
	}

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}