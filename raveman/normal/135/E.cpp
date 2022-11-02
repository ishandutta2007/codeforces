#pragma comment(linker, "/STACK:65777216")
 
#include <algorithm>
#include <iostream>
#include <string>
#include<sstream>
#include<string.h>
#include <cstdio>
#include <vector>
#include <bitset>
#include <cmath>
#include <queue>
#include<stack>
#include <set>
#include <map>
#include<ctime>
 
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef unsigned long long ull;
 
#define FOR(i,a,b) for (int i(a); i < (b); i++)
#define REP(i,n) FOR(i,0,n)
#define SORT(v) sort((v).begin(),(v).end())
#define UN(v) sort((v).begin(),(v).end()),v.erase(unique(v.begin(),v.end()),v.end())
#define CL(a,b) memset(a,b,sizeof(a))
#define pb push_back

const int mod = 1000000007;

int qp(ll c,int st){
	ll r = 1;
	while(st){
		if(st&1) r*=c,r%=mod;
		c*=c,c%=mod;
		st>>=1;
	}
	return r;
}

int f[1111111];
int inv[1111111];

int c(int n,int m){
	if(n<0 || m<0 || m>n) return 0;
	ll res = f[n];
	res *= inv[m];res%=mod;
	res *= inv[n-m];res%=mod;
	return res;
}

int main(){
#ifdef LocalHost
    freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
#endif

	inv[1]=inv[0]=f[0]=1;
	FOR(i,1,1111111) f[i]=f[i-1]*ll(i)%mod;
	FOR(i,2,1111111) inv[i]=(mod+(-ll(mod/i)*inv[mod%i]%mod))%mod;
	FOR(i,1,1111111) inv[i]=inv[i-1]*ll(inv[i])%mod;
	
	int k,w;
	cin>>k>>w;

	int ink = qp(k,mod-2);
	ll st = -1;

	int ans = 0;
	for(int len=w+1;;len++){
		int lenw = 2*w - len;
		if(lenw>0){
			int lenx = w - lenw;
			if(lenx>k){
				len = 2*w-1;
				continue;
			}
			if(lenw==1){
				REP(same,lenx+1){
					ll t = c(k,same);
					t *= c(k-same,lenx-same); t%=mod;
					t *= c(k-lenx,lenx-same); t%=mod;
					if(!t) continue;
					t *= f[lenx]; t%=mod;
					t *= f[lenx]; t%=mod;
					t *= (lenx+lenx-same); t%=mod;
					ans += t; if(ans>=mod) ans -= mod;
				}
			}else{
				if(st==-1) st = qp(k,lenw-2);
				else st *= ink, st%=mod;
				
				ll t = st;
				t *= c(k,lenx); t%=mod;
				if(!t) continue;
				t *= c(k,lenx); t%=mod;
				if(!t) continue;
				t *= f[lenx]; t%=mod;
				t *= f[lenx]; t%=mod;
				t *= ((k*ll(k)-ll(k-lenx)*(k-lenx))%mod); t%=mod;
				ans += t; if(ans>=mod) ans -= mod;
			}
		}else{
			int lenw = len - w - w;
			if(lenw > k) break;

			ll t = c(k,lenw);
			t *= c(k-lenw,w); t%=mod;
			t *= c(k-lenw,w); t%=mod;
			if(!t) continue;
			t *= f[w]; t%=mod;
			t *= f[w]; t%=mod;
			t *= f[lenw]; t%=mod;
			ans += t; if(ans>=mod) ans -= mod;
			
			t = c(k,lenw);
			t *= c(k-lenw,1); t%=mod;
			t *= c(k-lenw-1,1); t%=mod;
			t *= c(k-lenw-2,w-1); t%=mod;
			t *= c(k-lenw-2,w-1); t%=mod;
			if(!t) continue;
			t *= f[w-1]; t%=mod;
			t *= f[w-1]; t%=mod;
			t *= f[lenw]; t%=mod;
			ans -= t; if(ans<0) ans += mod;
		}
	}
	cout<<ans<<endl;
	
#ifdef LocalHost
	cout<<endl<<endl<<"TIME: "<<clock()<<endl;
#endif
    return 0;
}