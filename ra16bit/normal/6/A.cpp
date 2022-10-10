#include <cstdio>
using namespace std;
int a[5],i,j,k;
bool s,t;
int main() {
	for (i=0; i<4; i++) scanf("%d",&a[i]);
	for (i=0; i<4; i++) for (j=i+1; j<4; j++) for (k=j+1; k<4; k++) {
		if (a[i]<a[j]+a[k] && a[j]<a[i]+a[k] && a[k]<a[i]+a[j]) t=true;
		if (a[i]<=a[j]+a[k] && a[j]<=a[i]+a[k] && a[k]<=a[i]+a[j]) s=true;
	}
	if (t) puts("TRIANGLE"); else
		if (s) puts("SEGMENT"); else
			puts("IMPOSSIBLE");
	return 0;
}