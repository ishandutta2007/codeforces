#include <cstdio>
#include <vector>
#include <cassert>
#include <cstdint>
#include <cstring>
#include <algorithm>
#define meow(args...) fprintf(stderr, args)
const int N=1e5;
uint32_t P=1e9+7;

int phi[N*2+1], minp[N*2+1], rad[N*2+1];
bool vis[N*2+1];
uint32_t pw[N+1];
std::vector<int> pr;

uint64_t power(uint64_t a, uint32_t b) {
	uint64_t ans=1;
	for(; b; a=a*a%P, b>>=1) if(b&1) ans=ans*a%P;
	return ans;
}
int partial_phi(int n, int s) {
	if(n==0) return 0;
	if(s==1) return n;
	int p=minp[s];
	return partial_phi(n, s/p)-partial_phi(n/p, s/p);
}
int main() {
	int n, k;
	assert(scanf("%d%d", &n, &k)==2);
	uint64_t invk=power(k, P-2);
	pw[0]=1;
	for(int i=1; i<=n; ++i) pw[i]=pw[i-1]*invk%P;
	phi[1]=1;
	rad[1]=1;
	for(int i=2; i<=2*n; ++i) {
		if(!vis[i]) {
			pr.push_back(i);
			minp[i]=i;
			phi[i]=i-1;
			rad[i]=i;
		}
		for(int j=0; j<pr.size()&&i*pr[j]<=2*n; ++j) {
			vis[i*pr[j]]=1;
			minp[i*pr[j]]=pr[j];
			if(i%pr[j]==0) {
				phi[i*pr[j]]=phi[i]*pr[j];
				rad[i*pr[j]]=rad[i];
				break;
			}
			phi[i*pr[j]]=phi[i]*(pr[j]-1);
			rad[i*pr[j]]=rad[i]*pr[j];
		}
	}
	uint32_t ans=0;
	for(int d=1; d<n; ++d) {
		int m=(n-1)/d;
		for(int s=2; s<=m; ++s) ans=(ans+(uint64_t)phi[s]*pw[n-d])%P;
		for(int s=m+1; s<=m*2; ++s) ans=(ans+(uint64_t)(partial_phi(m, rad[s])-partial_phi(s-m-1, rad[s]))*pw[std::min(2*n-d*s, n-d)])%P;
	}
	printf("%u\n", ans);
	return 0;
}