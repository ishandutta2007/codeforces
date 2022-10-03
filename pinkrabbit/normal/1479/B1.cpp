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
int n,m,q,k;
int a[MN],b[MN],c[MN],d[MN];
int main(){
	scanf("%d",&n);
	F(i,1,n)scanf("%d",a+i);
	F(i,1,n){
		if(a[i]==b[m])++c[m];
		else b[++m]=a[i],c[m]=1;
	}
//	F(i,1,m)printf("(%d,%d)\n",b[i],c[i]);
	int ans=m,lst=-99;
	F(i,1,m)if(c[i]>1)d[++k]=i;
	ans+=k;
	F(i,2,k)if(b[d[i-1]]==b[d[i]]){
		int ok=0;
		F(j,d[i-1]+1,d[i]-1)
			if(b[j]!=b[d[i]]&&b[j-1]!=b[j+1])
				ok=1;
		if(!ok)--ans;
	}
	printf("%d\n",ans);
	return 0;
}