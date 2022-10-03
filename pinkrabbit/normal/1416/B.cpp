#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define MN 300005
#define MM 600005
#define ll long long
#define mod 998244353
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
typedef pair<int,int> pii;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
int n,a[MN];
int main(){int tests=1;scanf("%d",&tests);
while(tests--){
	int s=0;
	scanf("%d",&n);
	F(i,1,n)scanf("%d",a+i),s+=a[i];
	if(s%n){puts("-1");continue;}
	if(n==1){puts("0");continue;}
	s/=n;
	printf("%d\n",3*n-2);
	F(i,1,n){
		int z=a[i]/i;
		printf("%d %d %d\n",i,i%n+1,z);
		a[i]-=z*i;
		a[i%n+1]+=z*i;
	}
	debug("a[]: ");F(i,1,n)debug("%d%c",a[i]," \n"[i==n]);
	F(i,2,n)if(a[i]>s){
		printf("1 %d %d\n",i,i+s-a[i]);
		printf("%d 1 1\n",i);
	}
	F(i,2,n)if(a[i]<=s){
		printf("1 %d %d\n",i,s-a[i]);
		printf("%d 1 0\n",i);
	}
}	return 0;
}