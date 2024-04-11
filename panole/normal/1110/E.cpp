#include<bits/stdc++.h>
using namespace std;

int n;
long long a[100001],b[100001];

int main()
{
	scanf("%d",&n);
	for (int i=1; i<=n; i++) scanf("%I64d",&a[i]);
	for (int i=1; i<=n; i++) scanf("%I64d",&b[i]);
	if (a[1]!=b[1]||a[n]!=b[n]) {puts("No"); return 0;}
	for (int i=1; i<n; i++) a[i]=a[i+1]-a[i];
	for (int i=1; i<n; i++) b[i]=b[i+1]-b[i];
	sort(a+1,a+n); sort(b+1,b+n);
	for (int i=1; i<n; i++) if (a[i]!=b[i]) {puts("No"); return 0;}
	puts("Yes");
	return 0;
}