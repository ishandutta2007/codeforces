#include<bits/stdc++.h>
#define il inline
#define vd void
#define mod 998244353
typedef long long ll;
il ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
int n,k,a[1010],f[1010][1010];
il vd add(int&a,int b){a=a+b>=mod?a+b-mod:a+b;}
il int solve(int x){//beauty >= x
	for(int i=1,p=1;i<=n;++i){
		memset(f[i]+1,0,4*k);
		while(p<=n&&a[i]-a[p]>=x)++p;
		for(int j=1;j<=k;++j)add(f[i][j],f[i-1][j]),add(f[i][j],f[p-1][j-1]+(j==1));
	}
	return f[n][k];
}
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	n=gi(),k=gi();
	for(int i=1;i<=n;++i)a[i]=gi();
	std::sort(a+1,a+n+1);
	int ans=0;
	for(int i=1;i*(k-1)<=a[n];++i)add(ans,solve(i));
	printf("%d\n",ans);
	return 0;
}