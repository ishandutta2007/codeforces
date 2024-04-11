#include<cstdio>
#include<algorithm>
int n,m,q,mj;
long long a[100011],b[100011],c[100011],sum;
long long Abs(long long x){return x<0?-x:x;}
int main(){
	scanf("%d%d%d",&n,&m,&q); mj=m-n;
	for(int i=1,f=1;i<=n;++i,f^=1) scanf("%I64d",a+i),sum+=f?a[i]:-a[i];
	for(int i=1;i<=m;++i) scanf("%I64d",b+i);
	for(int i=1,f=0;i<=n;++i,f^=1) c[0]+=f?b[i]:-b[i];
	for(int i=1;i<=mj;++i) c[i]=-c[i-1]-b[i]+((n&1)?-b[i+n]:b[i+n]);
	std::sort(c,c+mj+1);
//	for(int i=0;i<=mj;++i) printf("%I64d ",c[i]); puts("");
	int l,r,x,len,mid;
	long long ans;
	l=0, r=mj, ans=9999999999999999ll;
	while(l<=r){
		mid=(l+r)>>1;
		if(c[mid]<-sum) l=mid+1;
		else r=mid-1;
		if(Abs(c[mid]+sum)<ans) ans=Abs(c[mid]+sum);
	}
	printf("%I64d\n",ans);
	for(int i=1;i<=q;++i){
		scanf("%d%d%d",&l,&r,&x);
		len=r-l+1;
		if(len&1) sum+=(l&1)?x:-x;
//		printf("\t%I64d\n",sum);
		l=0, r=mj, ans=9999999999999999ll;
		while(l<=r){
			mid=(l+r)>>1;
			if(c[mid]<-sum) l=mid+1;
			else r=mid-1;
			if(Abs(c[mid]+sum)<ans) ans=Abs(c[mid]+sum);
		}
		printf("%I64d\n",ans);
	}
	return 0;
}