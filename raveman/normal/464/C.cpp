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

const int mod = 1000000007;

ll qp(ll c, ll st){
	ll r= 1;
	while(st){
		if(st&1)r*=c,r%=mod;
		c*=c,c%=mod;
		st>>=1;
	}
	return r;
}

string s;
int n;
char tmp[111111];
char   f[111111];
string t[111111];
ll     r[111111];
ll     w[111111];

int pos[11];

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>t[0];
	cin>>n;
	
	REP(i,n){
		scanf(" %s",tmp);
		f[i+1]=tmp[0];
		int x = strlen(tmp);
		FOR(j,3,x)t[i+1].pb(tmp[j]);		
	}
	for(int i=n+1;i<=n+10;i++){
		w[i]=1;
		r[i]=i-(n+1);
		pos[i-(n+1)] = i;
	}
	//cout<<pos[1]<<' '<<r[2]<<endl;
	for(int i=n;i>=0;i--){
		REP(j,t[i].size()){
			int digit = t[i][j]-'0';
			int ps = pos[digit];

			ll len = w[ps];
			ll o = r[ps];
			///cout<<len<<' '<<o<<' '<<digit<<' '<<ps<<endl;
			r[i] = (r[i] * qp(10,len) + o )% mod;
			w[i] += len;
			w[i] = w[i]%(mod-1);
		}
		if(i){
			pos[f[i]-'0']=i;
		}
	}
	cout<<r[0]<<endl;

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}