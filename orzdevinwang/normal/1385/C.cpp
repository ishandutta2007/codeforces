#include<bits/stdc++.h>
using namespace std;
int T,n,a[200009],tot;
int main() {
	scanf("%d",&T);
	while(T--) {
		scanf("%d",&n), tot = n-1;
		for(int i = 1; i <= n; i++) scanf("%d",&a[i]);
		while(a[tot] >= a[tot+1] && tot != 0) --tot;
		while(a[tot] <= a[tot+1] && tot != 0) --tot;
		printf("%d\n",tot);
	}
	return 0;
}