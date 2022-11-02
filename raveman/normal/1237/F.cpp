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

const int mod = 998244353;

bool hor[4444],ver[4444];
int h,w,n;
ll f[4444];
ll invf[4444];

ll qp(ll c,ll st){
	ll r=1;
	while(st){
		if(st&1)r*=c,r%=mod;
		c*=c;c%=mod;
		st>>=1;
	}
	return r;
}

ll solve(int n2,int n1,int totaln,ll* n2counts){
	if(n2*2+n1>totaln)return 0;
	return n2counts[n2] * f[totaln-2*n2] % mod * invf[n1] % mod  * invf[totaln-2*n2-n1] % mod;
}

ll horcounts2[4444];
ll vercounts2[4444];

void addstuff(ll* cnt, int n){
	vector<ll> c;
	REP(i,n/2+1)c.pb(f[n-i]*invf[n-i-i]%mod*invf[i]%mod);
	for(int i=4000;i>=0;i--)if(cnt[i]){
		ll t = cnt[i];
		cnt[i]=0;
		REP(j,c.size()){
			cnt[i+j]=(cnt[i+j]+t*c[j])%mod;
		}
	}
}

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	f[0]=1;
	FOR(i,1,4444)f[i]=f[i-1]*i%mod;
	REP(i,4444)invf[i]=qp(f[i],mod-2);

	cin>>h>>w>>n;
	REP(i,n){
		int r1,c1,r2,c2;
		cin>>r1>>c1>>r2>>c2;
		r1--,r2--,c1--,c2--;
		hor[r1]=1;
		hor[r2]=1;
		ver[c1]=1;
		ver[c2]=1;
	}
	int nh=0,nv=0;
	REP(i,h)if(hor[i]==0)nh++;
	REP(i,w)if(ver[i]==0)nv++;

	horcounts2[0]=1;
	vercounts2[0]=1;

	for(int i=0;i<h;i++){
		if(hor[i]==0){
			int num = 0;
			while(i<h && hor[i]==0){
				num++;
				i++;
			}
			addstuff(horcounts2,num);
		}
	}
	for(int i=0;i<w;i++){
		if(ver[i]==0){
			int num = 0;
			while(i<w && ver[i]==0){
				num++;
				i++;
			}
			addstuff(vercounts2,num);
		}
	}

	ll res = 0;
	REP(numhor,nh/2+1)REP(numver,nv/2+1){
		res = (res + solve(numhor,numver,nh,horcounts2) * solve(numver,numhor,nv,vercounts2) % mod * f[numhor] % mod * f[numver] %mod) % mod;
	//	cout<<numhor<<' '<<numver<<' '<<res<<' '<<solve(numhor,numver,nh,horcounts2)<<' '<<solve(numver,numhor,nv,vercounts2)<<endl;
	}
	cout<<res<<endl;


#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}