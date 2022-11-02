#include<bits/stdc++.h>
#define LL long long
using namespace std;
int t,n,ans;
LL a[200200],b[200200][20];
int main(){
	//freopen("B.in","r",stdin);
	//freopen("B.out","w",stdout);
	scanf("%d",&t);
	while (t--){
		scanf("%d",&n);
		for (int i=0;i<n;i++)scanf("%lld",&a[i]);
		for (int i=1;i<n;i++){
			b[i][0]=abs(a[i]-a[i-1]);
			//printf("%d ",b[i][0]);
		}
		for (int j=0;j<18;j++)
		for (int i=1;i<n;i++){
			b[i][j+1]=__gcd(b[i][j],b[min(n-1,i+(1<<j))][j]);
		}
		ans=0;
		for (int i=1;i<n;i++){
			LL tmp=b[i][0];
			int nxt=i;
			for (int j=18;j>=0;j--)
			if (__gcd(tmp,b[nxt][j])>1){
				tmp=__gcd(tmp,b[nxt][j]);
				nxt=min(n,nxt+(1<<j));
			}
			ans=max(ans,nxt-i);
		}
		printf("%d\n",ans+1);
	}
}