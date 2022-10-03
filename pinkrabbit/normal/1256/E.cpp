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
#define mp make_pair
#define fi first
#define se second
int n,m;
int a[MN],p[MN],f[MN],g[MN],b[MN];
int main(){
	scanf("%d",&n);
	F(i,1,n)scanf("%d",a+i),p[i]=i;
	sort(p+1,p+n+1,[](int i,int j){return a[i]<a[j];});
	F(j,1,n){
		f[j]=0x3f3f3f3f,g[j]=-1;
		if(j>=3&&f[j]>f[j-3]+a[p[j]]-a[p[j-2]])f[j]=f[j-3]+a[p[j]]-a[p[j-2]],g[j]=3;
		if(j>=4&&f[j]>f[j-4]+a[p[j]]-a[p[j-3]])f[j]=f[j-4]+a[p[j]]-a[p[j-3]],g[j]=4;
		if(j>=5&&f[j]>f[j-5]+a[p[j]]-a[p[j-4]])f[j]=f[j-5]+a[p[j]]-a[p[j-4]],g[j]=5;
	}
	int k=n;
	while(k){
		++m;
		F2(j,0,g[k])b[p[k-j]]=m;
		k-=g[k];
	}
	printf("%d %d\n",f[n],m);
	F(i,1,n)printf("%d ",b[i]);
	return 0;
}