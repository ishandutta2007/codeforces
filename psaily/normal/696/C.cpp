#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<map>
#include<queue>
#include<ctime>
using namespace std;

#define bug(x) cerr<<#x<<'='<<x<<' '
#define debug(x) cerr<<#x<<'='<<x<<endl
#define gcd __gcd

typedef long long ll;
typedef double db;
typedef pair<int,int> pii;

const int mod=1e9+7;
const int maxn=1e5+50;

ll fast_mod(ll x,ll k){
	ll res=1;
	while(k){
		if(k&1)res=res*x%mod;
		k>>=1,x=x*x%mod;
	}
	return res;
}

int n;
ll A[maxn];
ll x,y;
bool is_odd=1;

int main(){
	scanf("%d",&n);
	y=2;
	for(int i=1;i<=n;i++){
		scanf("%lld",&A[i]);
		if(A[i]%2==0)is_odd=0;
	}
	for(int i=1;i<=n;i++)y=fast_mod(y,A[i]);
	y=y*fast_mod(2,mod-2)%mod;
	if(is_odd){
		ll res=y-1;
		if(res<0)res+=mod;
		if(res>=mod)res-=mod;
		x=res*fast_mod(3,mod-2)%mod;
	}else{
		ll res=y+1;
		if(res<0)res+=mod;
		if(res>=mod)res-=mod;
		x=res*fast_mod(3,mod-2)%mod;
	}
	printf("%lld/%lld\n",x,y);
	//bug(x),debug(y);
//	x=1,y=1;
//	for(int i=1;i<=100;i++){
//		x=y-x;
//		if(x%2==0)x/=2;
//		else y*=2;
//		ll g=gcd(x,y);
//		x/=g,y/=g;
//		bug(x),debug(y);
//	}
	return 0;
}