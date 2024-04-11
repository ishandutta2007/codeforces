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

int n,m,p;
int a[111111];
int b[111111];

int gcd(int a,int b){
	while(a&&b)
		if(a>b)a%=b;
		else b%=a;
	return a+b;
}

int qp(ll c, int st, int mod){
	ll r = 1;
	while(st){
		if(st&1)r*=c,r%=mod;
		st>>=1;
		c*=c,c%=mod;
	}
	return r;
}

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n>>m>>p;
	REP(i,n)cin>>a[i];
	REP(i,m)scanf("%d",b+i),b[i]%=(p-1);
	int g = b[0];
	REP(i,m) g = gcd(g, b[i]);	
	REP(i,n) a[i]=qp(a[i],g,p);
	vi pr;
	for(ll i=1;i*i<=p-1;i++)if((p-1)%i==0)pr.pb(i),pr.pb((p-1)/i);
	SORT(pr);
	vector<bool> h(pr.size());
	REP(i,n)for(int j=pr.size()-1;j>=0;j--)if(qp(a[i],(p-1)/pr[j],p)==1){h[j]=true;break;}
	REP(j,pr.size())if(h[j])FOR(i,j+1,pr.size())if(pr[i]%pr[j]==0)h[i]=true;
	ll res = 0;
	vector<ll> r(pr.size());
	for(int i=pr.size()-1;i>=0;i--){
		ll& cnt = r[i];
		cnt = (p-1)/pr[i];
		for(int j=i+1;j<pr.size();j++)if(pr[j]%pr[i]==0)cnt-=r[j];
		if(h[i])res += cnt;
	}
	cout<<res<<endl;

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}