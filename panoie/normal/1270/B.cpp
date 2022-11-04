#include<bits/stdc++.h>

using namespace std;
#define ll long long

const int N = 200005;
int T, n, a[N];
int main() {
	scanf("%d", &T);
	while(T--){
		scanf("%d", &n);
		for(int i=1; i<=n; ++i) scanf("%d", a+i);
		int mn=2e9, l1=0, mx=-2e9, l2=0, f=0;
		for(int i=1; i<=n; ++i){
			if(a[i]-i<mn) mn=a[i]-i, l1=i;
			if(a[i]+i>mx) mx=a[i]+i, l2=i;
			if(a[i]>=mn+i+1){
				printf("YES\n%d %d\n", l1, i);
				f=1;
				break;
			}
			if(a[i]<=mx-i-1){
				printf("YES\n%d %d\n", l2, i);
				f=1;
				break;
			}
		}
		if(!f) puts("NO");
	}
	return 0;
}