#include<bits/stdc++.h>
using namespace std;
int t,n,a[100010],b[100010],res;
int cmp(int x,int y){return x>y;}
int check(int x){
	return x*100+a[n-(n+x)/4]>=b[min(n,n+x-(n+x)/4)];
}
int main(){
	//freopen("C.in","r",stdin);
	scanf("%d",&t);
	while (t--){
		scanf("%d",&n);
		for (int i=1;i<=n;i++) scanf("%d",&a[i]);
		for (int i=1;i<=n;i++) scanf("%d",&b[i]);
		sort(a+1,a+n+1,cmp);
		//for (int i=1;i<=n;i++) printf("%d ",a[i]);
		sort(b+1,b+n+1,cmp);
		for (int i=1;i<=n;i++) a[i]=a[i]+a[i-1];
		//for (int i=1;i<=n;i++) printf("%d ",a[i]);
		for (int i=1;i<=n;i++) b[i]=b[i]+b[i-1];
		int l=0,r=n,mid;
		res=n;
		while (l<=r){
			mid=(l+r)/2;
			if (check(mid)){
				r=mid-1;
				res=mid;
			}
			else l=mid+1;
		}
		printf("%d\n",res);
	}
}