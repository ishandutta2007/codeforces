#include <bits/stdc++.h>
using namespace std;
int a[201010];
int main(){
	int n;scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d",a+i);
	int M=2012345678;
	long long ans=0;
	for(int i=n;i--;){
		a[i]=min(a[i],M-1);
		if(a[i]<0)a[i]=0;
		M=a[i];
		ans+=a[i];
	}
	printf("%lld\n",ans);
}