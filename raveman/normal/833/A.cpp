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


int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	vi p;
	FOR(i,2,1000){
		bool g = 1;
		for(int j=2;j*j<=i;j++)if(i%j==0){g=0;break;}
		if(g)p.pb(i);
	}
	//cout<<p.size()<<endl;

	int n;
	cin>>n;
	REP(i,n){
		int a,b;
		scanf("%d %d",&a,&b);
		bool g = 1;
		REP(j,p.size()){
			if(a==1 || b==1 || !g)break;
			if(a%p[j]==0){
				int t1 = 0, t2 = 0;
				while(a%p[j]==0)a/=p[j],t1++;
				while(b%p[j]==0)b/=p[j],t2++;
				if ((t1+t2)%3!=0)g=0;
				else{
					int s = (t1+t2)/3;
					if(min(t1,t2)<s)g=0;
				}
			}
		}
		if(a!=1 || b!=1){
			if(b==ll(a)*a || a==ll(b)*b){}
			else g=0;
		}
		if(g)puts("Yes");
		else puts("No");
	}

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}