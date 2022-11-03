#include<bits/stdc++.h>
#define il inline
#define vd void
#define rg register
#define ll long long
#define int long long
il ll gi(){
	rg int x=0,f=0;rg char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
int a[100010],ans[100010];
main(){
	int n=gi();
	for(int i=1;i<=n;++i)a[i]=gi();
	std::sort(a+1,a+n+1);
	int p=0;
	for(int i=1;i<=n;++i)
		if(i&1)ans[++p]=a[i];
		else ans[n-p+1]=a[i];
	for(int i=1;i<=n;++i)printf("%d ",ans[i]);
	return 0;
}