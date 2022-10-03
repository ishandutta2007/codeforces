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
typedef pair<int,int> pii;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
int n,ans;
int a[MN],b[MN],c[MN],d[MN];
int main(){
	scanf("%d%*d",&n),ans=n;
	F(i,1,n)scanf("%d",a+i),b[a[i]]=i,++d[a[i]];
	F(i,1,n)c[i]=max(c[i-1],b[a[i]]);
	int lstp=1;
	F(i,1,n)if(i==c[i]){
		int mx=0;
		F(j,lstp,i)mx=max(mx,d[a[j]]);
		ans-=mx;
		lstp=i+1;
	}
	printf("%d\n",ans);
	return 0;
}