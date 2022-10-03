#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define MN 1000005
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
int a[MN],f[MN];
ll s[MN];
int main(){
	scanf("%d",&n);
	F(i,1,n)scanf("%d",a+i),s[i]=s[i-1]+a[i];
	f[n]=n;
	dF(i,n-1,1){
		f[i]=i;
		while(f[i]!=n){
			if((s[f[i]]-s[i-1])*(f[f[i]+1]-i+1)>(s[f[f[i]+1]]-s[i-1])*(f[i]-i+1))f[i]=f[f[i]+1];
			else break;
		}
	}
//	F(i,1,n)printf("%d,",f[i]);puts("");
	int pos=1;
	while(pos<=n){
		double ans=(double)(s[f[pos]]-s[pos-1])/(f[pos]-pos+1);
		F(i,pos,f[pos])printf("%.15f\n",ans);
		pos=f[pos]+1;
	}
	return 0;
}