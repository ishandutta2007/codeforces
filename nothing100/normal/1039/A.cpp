#include<bits/stdc++.h>
#define LL long long
using namespace std;
LL a[200020],ans[200020],t;
int n,b[200020];
int main(){
	scanf("%d%lld",&n,&t);
	for (int i=1;i<=n;i++) scanf("%lld",&a[i]);
	for (int i=1;i<=n;i++) scanf("%d",&b[i]);
	for (int i=1;i<=n;i++) ans[i]=a[i]+t;
	for (int i=2;i<=n;i++)
	if (b[i-1]>b[i]){
		printf("No\n");
		return 0;
	}
	for (int i=1;i<=n;i++)
	if (b[i]<i){
		printf("No\n");
		return 0;
	}
	for (int i=1;i<=n;i++)
		if (b[i]>i) ans[i]=ans[i+1];
	for (int i=2;i<=n;i++) ans[i]=max(ans[i],ans[i-1]+1);
    for (int i=1;i<n;i++)
	if (b[i]!=n&&ans[b[i]]>=a[b[i]+1]+t){
		printf("No\n");
		return 0;
	}
	printf("Yes\n");
	for (int i=1;i<=n;i++)
	printf("%lld ",ans[i]);
}