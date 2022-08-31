#include<bits/stdc++.h>
using namespace std;
int T, l, r;
signed main() {
	scanf("%d",&T);
	while(T--) {
		scanf("%d%d",&l,&r);
		if(l * 2 > r) printf("-1 -1\n");
		else printf("%d %d\n", l, l * 2);
	}
    return 0;
}