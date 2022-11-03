#include<bits/stdc++.h>
typedef long long ll;
ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
int n,m,a[100010],b[100010],t[100010];
void update(int x){while(x)++t[x],x-=x&-x;}
int query(int x){int r=0;while(x<=n)r+=t[x],x+=x&-x;return r;}
int main(){
	int T=gi();
	while(T--){
		n=gi(),m=gi();
		for(int i=1;i<=n;++i)a[gi()]=i,t[i]=0;
		for(int i=1;i<=m;++i)b[i]=a[gi()];
		ll ans=m;
		for(int i=1,r=0;i<=m;++i){
			r=query(b[i]);
			if(!r)ans+=(b[i]-i)*2;
			update(b[i]);
		}
		printf("%lld\n",ans);
	}
	return 0;
}