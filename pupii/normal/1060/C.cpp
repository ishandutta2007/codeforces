#include<bits/stdc++.h>
#define il inline
#define vd void
#define int long long
typedef long long ll;
il int gi(){
	int x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return x*f;
}
int a[2010],b[2010];
main(){
#ifndef ONLINE_JUDGE
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
#endif
	int n=gi(),m=gi();
	for(int i=1;i<=n;++i)a[i]=a[i-1]+gi();
	for(int i=1;i<=m;++i)b[i]=b[i-1]+gi();
	int ans=0,x=gi();
	for(int i=1;i<=n;++i){
		int p=1;
		for(int j=2;j+i-1<=n;++j)if(a[j+i-1]-a[j-1]<a[p+i-1]-a[p-1])p=j;
		int t=0,S=a[p+i-1]-a[p-1];
		for(int j=1;j<=m;++j){
			while(t<m&&S*(b[t+1]-b[j-1])<=x)++t;
			ans=std::max(ans,i*(t-j+1));
		}
	}
	printf("%lld\n",ans);
	return 0;
}