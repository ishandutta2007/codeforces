#include<bits/stdc++.h>
#define il inline
#define vd void
typedef long long ll;
il ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return x*f;
}
ll a[200010],b[200010],c[200010],d[200010];
ll cnt0[31],cnt1[31];
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	int n=gi();
	for(int i=1;i<=n;++i)b[i]=gi();
	for(int i=1;i<=n;++i)c[i]=gi();
	ll sum=0;
	for(int i=1;i<=n;++i)d[i]=b[i]+c[i],sum+=d[i];
	sum/=2*n;
	for(int i=1;i<=n;++i)a[i]=(d[i]-sum)/n;
	for(int i=1;i<=n;++i)
		for(int j=0;j<31;++j)
			if((a[i]>>j)&1)++cnt1[j];
			else ++cnt0[j];
	for(int i=1;i<=n;++i){
		ll _b=0,_c=0;
		for(int j=0;j<31;++j)
			if((a[i]>>j)&1)_c+=cnt1[j]+cnt0[j]<<j,_b+=cnt1[j]<<j;
			else _c+=cnt1[j]<<j;
		if(_b!=b[i]||_c!=c[i])return puts("-1"),0;
	}
	for(int i=1;i<=n;++i)printf("%lld ",a[i]);puts("");
	return 0;
}