#include<bits/stdc++.h>
#define il inline
#define vd void
#define rg register
#define ll long long
#define int long long
il int gi(){
	rg int x=0,f=0;rg char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
int a[200010],b[200010];
std::map<int,int>M;
 main(){
	int n=gi(),m=gi(),k=gi();
	for(int i=1;i<=n;++i)a[i]=b[i]=gi();
	std::sort(b+1,b+n+1);
	ll ans=0;
	for(int i=1,j=1;j<=m*k;++i,++j)++M[b[n-i+1]],ans+=b[n-i+1];
	printf("%lld\n",ans);
	int p=0,q=0;
	for(int i=1;i<=n;++i){
		if(M[a[i]])++p,--M[a[i]];
		if(p>=m)printf("%lld ",i),++q,p=0;
		if(q==k-1)break;
	}
	return 0;
}