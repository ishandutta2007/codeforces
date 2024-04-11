#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
#include<set>
using namespace std;


int n, k, a[55];
int main() {
    scanf("%d%d", &n, &k);
    for (int i=0; i<n; i++) scanf("%d", a+i);
    sort(a, a+n);
    int p=0, t=0;
    for (;k;) {
	printf("%d", p+1);
	for (int i=0; i<p; i++) printf(" %d", a[n-i-1]);
	printf(" %d\n", a[t]); t++;
	if (t==n-p) { p++; t=0; }
	k--;
    }
    return 0;
}