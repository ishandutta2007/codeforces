#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define MN 200005
#define ll long long
#define mod 998244353
int t,n,k,c;
int a[MN],s[MN];
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&k),c=0;
		F(i,1,n)scanf("%d",a+i),a[i]&=1,s[i]=s[i-1]^a[i];
		if((s[n]^k)&1){puts("NO");continue;}
		--k;
		F(i,1,n)if(a[i])++c;
		if(c<k){puts("NO");continue;}
		puts("YES");
		F(i,1,n-1)if(k&&a[i])printf("%d ",i),--k;
		printf("%d\n",n);
	}
	return 0;
}