#include <stdio.h>
#include <algorithm>
#define MN 200000
int n,h,l[MN+5],r[MN+5],d[MN+5],ans;
int bin(int k){
	int l=1,r=n,mid;
	while(l<=r){
		mid=(l+r)>>1;
		if(d[mid]<=k) l=mid+1;
		else r=mid-1;
	}
	return r;
}
int main(){
//	freopen("d.in","r",stdin);
	scanf("%d%d",&n,&h);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&l[i],&r[i]);
	for(int i=2;i<=n;i++){
		d[i]=l[i]-r[i-1]+d[i-1];
//		printf(" - %d\n",d[i]);
	}
	for(int i=1;i<=n;i++){
		h+=d[i]-d[i-1];
		int p=bin(h);
		if(d[p]==h) ans=std::max(ans,l[p]-l[i]);
		else ans=std::max(ans,r[p]+h-d[p]-l[i]);
//		printf("%d %d %d %d\n",h,i,p,ans);
	}
	printf("%d",ans);
}