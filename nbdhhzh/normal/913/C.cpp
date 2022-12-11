#include<bits/stdc++.h>
#define N 30
using namespace std;
int n,m,i;
long long ans,a[50],A[50];
int main(){
	scanf("%d%d",&n,&m);a[0]=1e9;
	for(i=1;i<=n;i++){
		scanf("%I64d",&a[i]);
		a[i]=min(a[i-1]*2,a[i]);
	}
	A[n]=(m>>(n-1))*a[n];
	ans=A[n]+a[n];
	for(i=n-1;i>=1;i--){
		A[i]=A[i+1];
		if((m>>(i-1))&1)A[i]+=a[i];
		ans=min(ans,A[i]+a[i]);
	}
	ans=min(ans,A[1]);
	printf("%I64d\n",ans);
}