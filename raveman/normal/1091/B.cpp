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

int n;
int x[1111],y[1111];
int a[1111],b[1111];
pii t1[1111];
pii t2[1111];

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n;
	REP(i,n)cin>>x[i]>>y[i];
	REP(i,n)cin>>a[i]>>b[i],t1[i]=pii(a[i],b[i]);
	sort(t1,t1+n);
	REP(i,n){
		int X = x[0] + a[i];
		int Y = y[0] + b[i];

		REP(j,n){
			t2[j]=pii(X-x[j],Y-y[j]);
		}
		sort(t2,t2+n);
		bool g = 1;
		REP(j,n)if(t1[j]!=t2[j]){g=0;break;}
		if(g){
			cout<<X<<' '<<Y<<endl;
			break;
		}
	}

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}