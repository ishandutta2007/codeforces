#include<bits/stdc++.h>
#define il inline
#define vd void
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
int f[401][401][401],a[401];
int main(){
#ifndef ONLINE_JUDGE
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	int n=gi(),m=gi();
	for(int i=1;i<=n;++i)a[i]=gi();
	for(int l=1;l<=n;++l)
		for(int r=l;r<=n;++r)
			f[l][r][0]=a[r]-a[l];
	for(int k=1;k<=n;++k)
		for(int l=1;l<=n;++l){
			int o=l;
			for(int r=l;r<=n;++r){
				while(o<=r&&(std::max(f[l][o][k-1],a[r]-a[o])>std::max(f[l][o+1][k-1],a[r]-a[o+1])))++o;
				f[l][r][k]=std::max(f[l][o][k-1],a[r]-a[o]);
			}
		}
	ll ans=0,l,r,c,k;
	while(m--){
		l=gi(),r=gi(),c=gi(),k=gi();
		ans=std::max(ans,1ll*c*f[l][r][k]);
		//printf("%lld\n",1ll*c*f[l][r][k]);
	}
	printf("%lld\n",ans);
	return 0;
}