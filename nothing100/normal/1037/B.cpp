#include<bits/stdc++.h>
#define LL long long
using namespace std;
int n,s,a[200020];
LL ans;
int main(){
	scanf("%d%d",&n,&s);
	for (int i=0;i<n;i++) scanf("%d",&a[i]);
	sort(a,a+n);
	int mid=(n>>1);
	for (int i=0;i<=mid;i++)
	if (a[i]>s) ans+=(a[i]-s);
	for (int i=mid;i<n;i++)
	if (a[i]<s) ans+=(s-a[i]);
	printf("%lld\n",ans);
}