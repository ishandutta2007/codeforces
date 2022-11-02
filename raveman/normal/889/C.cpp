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

int k;
ll F[1111111];
const ll mod = 1000000007;

ll qp(ll c, ll st){
	ll r=1;
	while(st){
		if(st&1)r*=c,r%=mod;
		c*=c,c%=mod;
		st>>=1;
	}
	return r;
}

ll s2[1111111];

ll solve2(int n){
	if(k+1>=n)return 0;
	if(s2[n]!=-1)return s2[n];
	ll f = F[n-1-1-k];
	ll tmp = qp(n-1, mod-2);
	tmp *= (1 - solve2(n-1-k)*qp(f,mod-2)%mod);
	tmp%=mod;
	if(tmp<0)tmp+=mod;
	ll res = tmp;
	res *= F[n-2];res%=mod;
	res += solve2(n-1);
	res%=mod;
	res *= (n-1);
	res%=mod;
	return s2[n]=res;
}

/*ll solve2(int n,int k){
	ll res = 0;
	ll f = 1;
	for(int t=k+1;t<n;t++){
		ll tmp = qp(t, mod-2);

		if(t-1-k>1){
			f*=(t-1-k);
			f%=mod;
		}
		
		tmp *= (1 - solve2(t-k,k)*qp(f,mod-2)%mod);
		tmp%=mod;
		if(tmp<0)tmp+=mod;
		res += tmp;
		if(res>=mod)res-=mod;
	}
	FOR(i,1,n)res*=i,res%=mod;
	if(k<n)
	cout<<n<<' '<<k<<" = " <<res<<' '<<solve2(n-1,k)*(n-1)+<<endl;
	return res;
}
*/
ll solve(int n,int k){
	ll res = 0;
	ll f = 1;
	for(int t=k+1;t<n;t++){
		ll tmp = n-t;
		tmp *= qp(t, mod-2);
		tmp %= mod;

		if((t-1-k)>1){
			f*=(t-1-k);f%=mod;
		}
		
		tmp *= (1 - solve2(t-k)*qp(f,mod-2)%mod);
		tmp%=mod;
		if(tmp<0)tmp+=mod;
		res += tmp;
		if(res>=mod)res-=mod;
	}
	FOR(i,1,n)res*=i,res%=mod;
	return res;
}

ll stupid(int n,int k){
	ll res = 0;
	vi p;
	REP(i,n)p.pb(i);
	do{
		int mx = -1;
		int offset = 0;
		REP(i,p.size()){
			if(p[i]>mx){
				mx=p[i];
				offset=0;
			}else{
				offset++;
				if(offset==k)break;
			}
		}
		if(mx!=n-1)res++;
	}while(next_permutation(p.begin(),p.end()));
	return res;
}

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif
	CL(s2,-1);
	F[0]=1;
	FOR(i,1,1111111)F[i]=F[i-1]*i%mod;

//	int n,k;
	int n;
	cin>>n>>k;
	cout<<solve(n,k)<<endl;
//	for(n=5;n<=10;n++)for(k=1;k<=10;k++)
	//	if(solve(n,k)!=stupid(n,k))
	//cout<<n<<' '<<k<<"=  "<<solve(n,k)<<' '<<stupid(n,k)<<endl;

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}