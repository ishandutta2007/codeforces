#include<bits/stdc++.h>

using namespace std;
#define ll long long

const int N = 1000005;
int n, top, a[N], stk[N];
ll s[N];
int main() {
	scanf("%d", &n);
	for(int i=1; i<=n; ++i) scanf("%d", a+i), s[i]=s[i-1]+a[i];
	for(int i=1; i<=n; ++i){
		while(top && (i-stk[top])*(s[stk[top]]-s[stk[top-1]])>(stk[top]-stk[top-1])*(s[i]-s[stk[top]])) --top;
		stk[++top]=i;
	}
	for(int i=1; i<=top; ++i){
		double x=(double)(s[stk[i]]-s[stk[i-1]])/(stk[i]-stk[i-1]);
		for(int j=stk[i-1]; j<stk[i]; ++j) printf("%.12lf\n", x);
	}
	return 0;
}