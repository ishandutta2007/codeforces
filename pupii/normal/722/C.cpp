#include<bits/stdc++.h>
typedef long long ll;
ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
std::multiset<ll,std::greater<ll>>st;
int fa[100010];ll ans[100010],sum[100010];
int a[100010],p[100010],y[100010];
int hd(int x){return fa[x]==x?fa[x]:fa[x]=hd(fa[x]);}
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	int n=gi();
	for(int i=1;i<=n;++i)a[i]=gi();
	for(int i=1;i<=n;++i)p[i]=gi();
	for(int i=1;i<=n;++i)fa[i]=i;
	for(int _=n,i;_;--_){
		i=p[_];
		ans[_]=*st.begin();
		int L=hd(i-1),R=hd(i+1);ll ns=a[i];
		if(i==1||!y[i-1])L=-1;
		if(i==n||!y[i+1])R=-1;
		if(~L)ns+=sum[L],st.erase(st.find(sum[L]));
		if(~R)ns+=sum[R],st.erase(st.find(sum[R]));
		fa[i]=fa[R]=i-1;
		sum[hd(i)]=ns;
		st.insert(ns);
		y[i]=1;
	}
	for(int i=1;i<=n;++i)printf("%lld\n",ans[i]);
	return 0;
}