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
#define R(i,n)			REP(i,n)
#define SORT(v)			sort((v).begin(),(v).end())
#define UN(v)			SORT(v),(v).erase(unique((v).begin(),(v).end()),(v).end())
#define CL(a,b)				memset(a,b,sizeof a)
#define pb				push_back


int getL(int n){
	n--;
	if(n<0) return 1;
	int res = 1;
	n/=7;
	while(n)res++,n/=7;
	return res;
}

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	ll n,m;
	cin>>n>>m;

	int l1 = getL(n);
	int l2 = getL(m);

	ll res = 0;
	if(l1+l2<=7){
		vi t;
		REP(i,7)t.pb(i);
		set<pii> used;
		do{
			ll n1 = 0;
			ll n2 = 0;
			REP(i,l1)n1=n1*7+t[i];
			REP(i,l2)n2=n2*7+t[l1+i];
			if(n1<n && n2<m && !used.count(pii(n1,n2))) res++,used.insert(pii(n1,n2));
		}while(next_permutation(t.begin(),t.end()));
	}
	cout<<res<<endl;


#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}