#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define MN 1000005
#define ll long long
int n,m;
int a[MN],s[MN],t[MN];
int r[MN],l[MN];
ll ans;
int main(){
	scanf("%d%d",&n,&m);
	F(i,1,n)scanf("%d",a+i);
	F(i,1,n)if(!s[a[i]])s[a[i]]=i;
	dF(i,n,1)if(!t[a[i]])t[a[i]]=i;
	r[1]=0;
	F(i,2,m)r[i]=s[i-1]?r[i-1]>s[i-1]?n+1:t[i-1]:r[i-1];
	l[m]=n+1;
	dF(i,m-1,1)l[i]=s[i+1]?l[i+1]<t[i+1]?0:s[i+1]:l[i+1];
	int j=m;
	dF(i,m,1){
		while(j>=i&&l[j]>r[i])--j;
		ans+=m-j;
	}
	printf("%lld\n",ans);
	return 0;
}