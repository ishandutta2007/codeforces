#include<bits/stdc++.h>
using namespace std;
int l,r,ls;
long long m;
int T;
int main() {
	scanf("%d",&T);
	while(T--) {
		scanf("%d%d%lld",&l,&r,&m);
		for(int i = l; i <= r; i++) {
			ls = m % i;
			if(ls+l <= r && m != ls) {
				printf("%d %d %d\n",i,l+ls,l);
				break;
			}
			else {
				ls -= i;
				if(l - ls > r) continue;
				printf("%d %d %d\n",i,l,l-ls);
				break;
			}
		}
	}
	return 0;
}