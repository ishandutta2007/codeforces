#include <stdio.h>
#define MA 1000000

const int mod = 1000000007;

using ll = long long;

int fac[MA+5];
int diff[MA+5];

void init(int n){
	fac[0] = 1;
	for(int i=1;i<=n;i++)
		fac[i] = (ll)fac[i-1]*i%mod;
}

int sum(ll l,ll r){
	return ((l+r)%mod)*((r-l+1)%mod)%mod*500000004%mod;
}

int main(){
	init(MA);
	int n;
	ll totLen = 0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int a;
		scanf("%d",&a);
		diff[a-1]++;
		totLen += a;
	}
	int dis=0,cnt=1;
	ll pre = 0;
	for(int i=MA;i>=0;i--){
		diff[i] += diff[i+2];
		cnt = (ll)cnt*fac[diff[i]]%mod;
		if(i!=0){
			cnt = (ll)cnt*fac[diff[i]]%mod;
			dis = (dis+(ll)(sum(totLen-pre-diff[i]+1,totLen-pre)-sum(pre+1,pre+diff[i]))*i)%mod;
			pre += diff[i];
		}
	}
	dis = (dis+mod)%mod;
	printf("%d %d\n",dis,cnt);
}