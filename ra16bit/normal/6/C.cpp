#include <cstdio>
using namespace std;
int n,a[200000],i,l,s,r,t;
int main() {
	scanf("%d",&n);
	for (i=0; i<n; i++) scanf("%d",&a[i]);
	l=0; s=0; r=n-1; t=0;
	while (l<=r) {
		if (s==t) {
			s+=a[l]; l++; 
			if (l<=r) { t+=a[r]; r--; }
		} else if (s<t) {
			s+=a[l]; l++;
		} else if (s>t) {
			t+=a[r]; r--;
		}
	}
	printf("%d %d\n",l,n-l);
	return 0;
}