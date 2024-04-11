#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define MN 100005
int n,m,k;
int a[MN],b[MN];
int main(){
	scanf("%d%d%d",&n,&m,&k);
	F(i,1,n)scanf("%d",a+i);
	F(i,1,n-1)b[i]=a[i+1]-a[i]-1;
	sort(b+1,b+n);
	long long s=n;
	F(i,1,n-k)s+=b[i];
	printf("%lld\n",s);
	return 0;
}