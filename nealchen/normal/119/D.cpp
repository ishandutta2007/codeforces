#include <stdio.h>
#include <string.h>
#include <algorithm>
#define meow(args...) fprintf(stderr, args)
const int N=1e6+5;
int self[N];
void match(register const char *s, register const char *t, register int *ans)
{
	register int m=0, k, i, l;
	for(l=0; s[l] && s[l]==t[l]; ++l);
	ans[0]=l;
	for(i=1; s[i]; ++i) {
		for(l = i<m ? std::min(self[i-k], m-i) : 0; s[l] && s[l]==t[i+l]; ++l);
		ans[i]=l;
		if(i+l>m) {
			m=i+l;
			k=i;
		}
	}
}
char a[N], b[N];
int n, lcp[N], rev[N], min[N];
int main()
{
	register int i, j, k, curmin, x=-1, y=-1;
	scanf("%[^\n]%*c%[^\n]", a, b);
	n=curmin=strlen(a);
	if(n==strlen(b)) {
		match(b, b, self);
		match(b, a, lcp);
		for(i=0, j=n-1; i<j; ++i, --j) std::swap(a[i], a[j]);
		match(a, a, self);
		match(a, b, rev);
		for(i=0; i<=n; ++i) min[i]=n;
		for(i=0; i<n; ++i) min[i+rev[i]]=std::min(min[i+rev[i]], i);
		curmin=min[n];
		for(i=n-1; i>=0 && a[i]==b[i]; --i) {
			curmin=std::min(min[i], curmin);
			if(curmin<=lcp[n-i] && curmin<i) {
				x=n-i-1;
				y=n-i+curmin;
			}
		}
	}
	printf("%d %d\n", x, y);
	return 0;
}