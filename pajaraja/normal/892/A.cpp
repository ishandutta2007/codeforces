#include <bits/stdc++.h>
using namespace std;
long long a[100007],b[100007];
int main()
{
	int n;
	long long s=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	for(int i=0;i<n;i++) scanf("%d",&b[i]);
	for(int i=0;i<n;i++) s+=a[i];
	sort(b,b+n,greater<int>());
	if(b[0]+b[1]>=s) printf("YES");
	else printf("NO");
}