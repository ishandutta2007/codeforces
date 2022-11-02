#include<bits/stdc++.h>
using namespace std; 
const int mo=998244353;
int n,a[200020],b[200020],c[200020],dp[200020],sum[200020],res;
int main(){
	//freopen("F.in","r",stdin);
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%d%d%d",&a[i],&b[i],&c[i]);
		dp[i]=a[i]-b[i];
		if (i>1&&b[i]<a[i-1]){
			int l=0,r=i-1,nxt=i-1;
			while (l<=r){
				int mid=(l+r)/2;
				if (a[mid]>b[i]){
					nxt=mid;
					r=mid-1;
				}
				else l=mid+1;
			}
			dp[i]=(dp[i]+sum[i-1])%mo;
			dp[i]=(dp[i]-sum[nxt-1]+mo)%mo;
			//printf("%d ",nxt);
		}
		//printf("%d\n",dp[i]);
		sum[i]=(sum[i-1]+dp[i])%mo;
	}
	res=a[n]+1;
	for (int i=0;i<=n;i++)
	res=(res+dp[i]*c[i])%mo;
	printf("%d\n",res);
}