#include<bits/stdc++.h>
using namespace std;
int T,n,a[555],used[555],tot,f[555];
int main() {
	scanf("%d",&T);
	while(T--) {
		scanf("%d",&n), n *= 2, tot = 0;
		for(int i = 1; i <= n; i++) {
			scanf("%d",&a[i]);
			used[a[i]]++;
			if(used[a[i]] == 1) ++tot, f[tot] = a[i];
		}
		for(int i = 1; i <= tot; i++) printf("%d ",f[i]);
		puts("");
		for(int i = 1; i <= n; i++) used[a[i]]--;
	}
	return 0;
}