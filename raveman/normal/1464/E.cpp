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

const int mod = 998244353;

int n,m;
vi v[111111];
int sg[111111];
const int Q=512;

int now;
int u[111111];

int SG(int ver){
	if(sg[ver]!=-1)return sg[ver];
	REP(i,v[ver].size())SG(v[ver][i]);
	now++;
	REP(i,v[ver].size()){
		u[SG(v[ver][i])]=now;
	}
	sg[ver]=0;
	while(u[sg[ver]]==now){
		sg[ver]++;
	}
	return sg[ver];
}

int a[Q][Q];
int b[Q];

ll qp(ll c,ll st){
	ll r=1;
	while(st){
		if(st&1)r*=c,r%=mod;
		c*=c,c%=mod;
		st>>=1;
	}
	return r;
}

bool cu[Q];

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n>>m;
	REP(i,m){
		int x,y;
		scanf("%d %d",&x,&y);
		x--,y--;
		v[x].pb(y);
	}
	CL(sg,-1);
	REP(i,n)if(SG(i)>=Q){
		return 0;
	}
	REP(i,Q){
		a[i][i]=-(n+1)+mod;
		REP(j,n){
			a[i][i^SG(j)]++;
		}
		b[i]=(i>0?mod-1:0);
	}

	REP(i,Q){
		int pos=-1;
		REP(j,Q){
			if(cu[j])continue;
			if(a[j][i]){pos=j;break;}
		}
		if(pos==-1)continue;
		while(pos==-1)puts("FUCK");
		REP(j,Q)swap(a[i][j],a[pos][j]);
		swap(b[i],b[pos]);
		cu[i]=1;

		ll k = qp(a[i][i],mod-2);
		REP(j,Q)a[i][j]=(a[i][j]*k)%mod;
		b[i]=(b[i]*k)%mod;

		REP(j,Q)if(j!=i){
			k = a[j][i];
			REP(z,Q){
				a[j][z] = (a[j][z] - k * a[i][z]) % mod;
				if(a[j][z]<0)a[j][z]+=mod;
			}
			b[j] = (((b[j] - k * b[i]) % mod) + mod )% mod;
		}
	}

	cout<<b[0]<<endl;

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}