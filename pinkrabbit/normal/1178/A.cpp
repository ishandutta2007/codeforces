#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define MN 300005
#define MM 600005
#define ll long long
#define mod 998244353
int n;
int a[MN],b[MN],s,k;
int main(){
	scanf("%d",&n);
	F(i,1,n)scanf("%d",a+i),s+=a[i],b[i]=a[i];
	sort(a+2,a+n+1);
	int j=0;
	while(j<n&&(k+a[j+1])*2<=s)k+=a[++j];
	k+=a[++j];
	if(j==1)return puts("1\n1"),0;
	if(a[1]<a[j]*2)return puts("0"),0;
	while(j<n&&a[j+1]==a[j])++j;
	printf("%d\n%d",j,1);
	F(i,2,n)if(b[i]<=a[j])printf(" %d",i);
	puts("");
	return 0;
}