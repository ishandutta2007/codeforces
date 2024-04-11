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
typedef pair<double,double>	pdd;
typedef vector<int> vi;
typedef vector<ld> vd;
typedef pair<ll,ll> pl;

#define FOR(i,a,b)		for(int i=(a);i<(b);i++)	
#define REP(i,n)		FOR(i,0,n)
#define SORT(v)			sort((v).begin(),(v).end())
#define UN(v)			SORT(v),(v).erase(unique((v).begin(),(v).end()),(v).end())
#define CL(a,b)			memset(a,b,sizeof a)
#define pb				push_back

ll d[22][1000];
int f[22][1000];

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	ll n;
	cin>>n;
	d[0][0]=1;
	ll res=1000;
	REP(i,10)REP(j,1000)if(d[i][j]){
		REP(k,1000)if(j+k<1000){
			if (i==9 && d[i][j]*k>=n) res=min(res,(ll)j+k);
			if(d[i+1][j+k]<d[i][j]*k){
				d[i+1][j+k]=min(n,d[i][j]*k);
				f[i+1][j+k]=j;
			}
		}
	}
	int pos = res;
	int k = 9;
	string x = "codeforces";
	string w="";
	for(int k=10;k>=1;k--){
		int df = pos - f[k][pos];
		//cout<<k<<' '<<df<<endl;
		REP(i,df)w.pb(x[k-1]);
		pos=f[k][pos];
	}
	reverse(w.begin(),w.end());
	cout<<w<<endl;

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}