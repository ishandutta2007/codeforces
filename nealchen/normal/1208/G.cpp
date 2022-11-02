#include <cstdio>
#include <cassert>
#include <cstring>
#include <iostream>
#include <algorithm>
#define meow(args...) fprintf(stderr, args)
template<class T1, class T2> inline bool cmin(T1 &a, const T2 &b) {return b<a?(a=b, true):false;}
template<class T1, class T2> inline bool cmax(T1 &a, const T2 &b) {return a<b?(a=b, true):false;}
const int N=1e6+5;
bool vis[N];
int n, k, pr[N], cnt, phi[N];
int main() {
	assert(scanf("%d%d", &n, &k)==2);
	if(k==1) {
		puts("3");
	} else {
		++k;
		for(int i=2; i<=n; ++i) {
			if(!vis[i]) {
				pr[cnt++]=i;
				phi[i]=i-1;
			}
			for(int j=0; j<cnt&&i*pr[j]<=n; ++j) {
				vis[i*pr[j]]=true;
				if(i%pr[j]==0) {
					phi[i*pr[j]]=phi[i]*pr[j];
					break;
				}
				phi[i*pr[j]]=phi[i]*(pr[j]-1);
			}
		}
		std::nth_element(phi+2, phi+2+k, phi+n+1);
		long long ans=1;
		for(int i=2; i<k+2; ++i) ans+=phi[i];
		std::cout<<ans<<std::endl;
	}
	return 0;
}