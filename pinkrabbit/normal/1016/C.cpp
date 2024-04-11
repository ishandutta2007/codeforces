#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
typedef long long LL;

int n;
LL a[300001],b[300001];
LL s[300001],Ans;
LL f[300001];

int main(){
	scanf("%d",&n);
	F(i,1,n) scanf("%lld",a+i);
	F(i,1,n) scanf("%lld",b+i);
	s[n]=a[n]+b[n];
	dF(i,n-1,1) s[i]=s[i+1]+a[i]+b[i];
	f[n]= n&1 ? b[n] : a[n];
	f[n-1]= n&1 ? b[n]+2*a[n]+3*a[n-1] : a[n]+2*b[n]+3*b[n-1];
	dF(i,n-2,1){
		f[i]= i&1 ? f[i+2]+2*s[i+2]+a[i+1]+(2*(n-i+1)-1)*b[i]+2*(n-i)*b[i+1] : f[i+2]+2*s[i+2]+b[i+1]+(2*(n-i+1)-1)*a[i]+2*(n-i)*a[i+1];
	}
	LL S=0;
	F(i,1,n){
		Ans=max(Ans,S+f[i]+(i*2-2)*s[i]);
		S=S+(i&1?(2*i-2)*a[i]+(2*i-1)*b[i]:(2*i-2)*b[i]+(2*i-1)*a[i]);
	}
	printf("%lld",Ans);
	return 0;
}