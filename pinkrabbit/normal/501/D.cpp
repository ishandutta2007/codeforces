#include<bits/stdc++.h>
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)

int n,q;
int a[200001],b[200001],c[200001];
int bit[262145];
inline void I(int i,int x){for(;i<=262144;i+=i&-i)bit[i]+=x;}
inline int Q(int i){int x=0;for(;i;i-=i&-i)x+=bit[i];return x;}
inline int BS(int x){
	int sum=0, i=262144, ans=262144;
	while(!(i&1)){
		if(sum+bit[ans-(i>>1)]>=x) ans-=i>>1;
		else sum+=bit[ans-(i>>1)];
		i>>=1;
	}
	return ans;
}

int main(){
	scanf("%d",&n);
	F(i,1,n) scanf("%d",a+i), ++a[i];
	F(i,1,n) scanf("%d",b+i), ++b[i];
	F(i,1,n) I(i,1);
	F(i,1,n) I(a[i],-1), a[i]=Q(a[i]);
	F(i,1,n) I(i,1);
	F(i,1,n) I(b[i],-1), b[i]=Q(b[i]);
	int lst=0;
	dF(i,n,1){
		c[i]=a[i]+b[i]+lst;
		if(c[i]>=n-i+1) c[i]-=n-i+1, lst=1;
		else lst=0;
	}
	F(i,1,n) I(i,1);
	F(i,1,n){
		c[i]=BS(c[i]+1);
		I(c[i],-1);
	}
	F(i,1,n) printf("%d ",c[i]-1); puts("");
	return 0;
}