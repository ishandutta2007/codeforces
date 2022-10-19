#include<bits/stdc++.h>

using namespace std;

#define N 300000

int n,m,p,a[N],b[N],ans;

int main(){
	scanf("%d%d%d",&n,&m,&p);
	for (int i=1;i<=n;++i) scanf("%d",a+i);
	for (int i=1;i<n;++i) b[i]=a[i+1]-a[i]-1;
	sort(b+1,b+n);
	ans=n;
	for (int i=1;i<=max(0,n-p);++i) ans+=b[i];
	printf("%d\n",ans);
	
	return 0;
}