#include<bits/stdc++.h>

using namespace std;
#define ll long long

const int N = 100005;
int n, x[N], y[N];
int main() {
	scanf("%d", &n);
	for(int i=1; i<=n; ++i) scanf("%d%d", x+i, y+i);
	if(n&1) return puts("NO"), 0;
	for(int i=1; i<=n/2; ++i)
		if(x[i+n/2]!=(ll)x[1]+x[n/2+1]-x[i] || y[i+n/2]!=(ll)y[1]+y[n/2+1]-y[i])
			return puts("NO"), 0;
	puts("YES");
	return 0;
}