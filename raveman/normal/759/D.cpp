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
#define CL(a,b)				memset(a,b,sizeof a)
#define pb				push_back

const int mod = 1000000007;

int n;
string s;

int d[5555][5555];
int c[5555][5555];
int nx[5555][26];

inline void add(int& x,int v){
	x+=v;
	if(x>=mod)x-=mod;
}

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	REP(i,5555){
		c[i][i]=c[i][0]=1;
		FOR(j,1,i)c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod;
	}

	cin>>n>>s;
	CL(nx,-1);
	for(int i=n-1;i>=0;i--){
		memcpy(nx[i],nx[i+1],sizeof nx[i]);
		nx[i][s[i]-'a']=i;
	}
	d[0][0]=1;
	int v,z;
	REP(i,n)REP(len,n)if(v=d[i][len]){
		int forb = (i>=1?s[i-1]-'a':-1);
		REP(l,26)if((z=nx[i][l])!=-1 && l!=forb){
			add(d[z+1][len+1],d[i][len]);
		}
	}
	ll res = 0;
	FOR(i,1,n+1)REP(len,n+1)if(v=d[i][len]){
		int sum = n - len;
		res = (res + ll(v) * c[sum+len-1][len-1]) % mod;
	}
	cout<<res<<endl;

#ifdef LocalHost
	//printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}