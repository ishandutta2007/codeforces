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

int n,k;
int a[222222];

ll res;
unordered_map<int,int> m1,m2;

void solve(int l,int r){
	if(l>r) return;

	int m = (l+r)/2;
	int x = 0;
	m1.clear();
	m2.clear();
	m1[0]++;
	int n1=1,n2=0;
	FOR(i,m+1,r+1){
		x ^= a[i];
		m1[x]++;
		n1++;
	}
	x=a[m];
	m2[x]++;
	n2++;
	for(int i=m-1;i>=l;i--){
		x ^= a[i];
		m2[x]++;
		n2++;
	}

	ll nz = 0;
	ll na = 0;
	for(unordered_map<int,int>::iterator it = m1.begin();it!=m1.end();it++){
		int mask = it->first;
		int num = it->second;

		nz += ll(num) * m2[mask];
		na += ll(num) * m2[mask^((1<<k)-1)];
	}

	res += n1 * ll(n2) - min(na,nz);



	solve(l,m-1);
	solve(m+1,r);
}

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n>>k;
	int x = 0;
	m1[x]++;
	REP(i,n){
		scanf("%d",a+i);
		x ^= a[i];
		if(m1[x]>m1[x^((1<<k)-1)]) x ^= ((1<<k)-1);
		res += (i+1) - m1[x];
		m1[x]++;
	}
	//solve(0,n-1);
	cout<<res<<endl;

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif

	return 0;
}