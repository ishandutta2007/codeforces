#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
typedef long long LL;

int n;
int a[200001];

int main(){
	scanf("%d",&n); n*=2;
	F(i,1,n) scanf("%d",a+i);
	sort(a+1,a+n+1);
	int W=0x3f3f3f3f;
	F(i,2,n/2) W=min(W,a[i+n/2-1]-a[i]);
	LL Ans=min((LL)(a[n]-a[1])*W,(LL)(a[n/2]-a[1])*(a[n]-a[n/2+1]));
	printf("%lld\n",Ans);
	return 0;
}