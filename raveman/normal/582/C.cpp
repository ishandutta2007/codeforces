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
int  a[222222];
int  u[422222];
int now;
int  s[222222];

int gcd(int a,int b){
	while(a&&b)if(a>b)a%=b;else b%=a;
	return a+b;
}

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif



	cin>>n;REP(i,n)scanf("%d",a+i);
	//n=200000;REP(i,n)a[i]=1;
	

	ll res = 0;
	FOR(g,1,n+1)if(n%g==0){

		int t = n/g;
		vi p;
		for(int j=2;j*j<=t;j++)if(t%j==0){
			p.pb(j);
			while(t%j==0)t/=j;
		}
		if(t>1)p.pb(t);
		s[0]=0;
		FOR(i,1,n+1){
			s[i]=s[i-1];
			bool pr=1;
			REP(j,p.size())if(i%p[j]==0){pr=0;break;}
			if(pr)s[i]++;
		}

		now++;
		REP(i,g){
			int mx = a[i];
			REP(k,n/g)mx=max(mx,a[i+g*k]);
			REP(k,n/g)if(a[i+g*k]==mx)u[i+g*k]=now;
		}
		REP(i,n)u[n+i]=u[i];
		int p2 = 0;
		REP(i,n){
			p2=max(p2,i);
			if(u[i]==now){
				while(p2<2*n && u[p2]==now)p2++;
				int len = min(n - 1, p2 - i);
				res += s[len/g];
			}
		}
	}
	cout<<res<<endl;

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}