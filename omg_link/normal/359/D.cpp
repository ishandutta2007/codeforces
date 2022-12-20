#include <stdio.h>
#include <algorithm>
#define MN 500000
int n,a[MN+5],ansc,ans[MN+5];
int gcd(int a,int b){
	if(a<b) std::swap(a,b);
	return a%b==0?b:gcd(b,a%b);
}
int min(int a,int b){
	return a<b?a:b;
}
struct RMQ{
	int T[MN+5][20];
	int (*cmp)(int a,int b);
	void init(int (*_cmp)(int,int),int a[]){
		cmp=_cmp;
		for(int j=1;j<=n;j++) T[j][0]=a[j];
		for(int i=1;i<=20;i++)
			for(int j=1;j<=n-(1<<i)+1;j++)
				T[j][i]=cmp(T[j][i-1],T[j+(1<<(i-1))][i-1]);
	}
	int query(int l,int r){
		int len=1,k=0;
		while(len<=r-l+1) len<<=1,k++;
		k--; len>>=1;
		return cmp(T[l][k],T[r-len+1][k]);
	}
}GCD,MIN;
void check(int len){
	ansc=0;
	for(int l=1;l+len-1<=n;l++)
		if(GCD.query(l,l+len-1)==MIN.query(l,l+len-1)) ans[++ansc]=l;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	GCD.init(gcd,a);
	MIN.init(min,a);
	int l=1,r=n,mid;
	while(l<=r){
		mid=(l+r)>>1;
		check(mid);
		if(ansc) l=mid+1;
		else r=mid-1;
	}
	check(r);
	printf("%d %d\n",ansc,r-1);
	for(int i=1;i<=ansc;i++)
		printf("%d ",ans[i]);
}