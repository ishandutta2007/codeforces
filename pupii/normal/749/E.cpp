#include<bits/stdc++.h>
typedef long long ll;
ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
int a[100010],n;
ll C2(int n){return 1ll*n*(n+1)/2;}
ll t1[100010],t2[100010];
void update(ll*t,int x,ll d){while(x<=n)t[x]+=d,x+=x&-x;}
ll query(ll*t,int x){ll r=0;while(x)r+=t[x],x-=x&-x;return r;}
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	n=gi();
	for(int i=1;i<=n;++i)a[i]=gi();
	double ans=0;
	for(int i=n;i;--i){
		ll q1=query(t1,a[i]),q2=query(t2,a[i]);
		ans+=q1+(0.-q1*(n+1)*i+q2*i)/C2(n);
		update(t1,a[i],1),update(t2,a[i],i);
	}
	for(int i=1;i<=n;++i)ans+=1.*C2(i-1)*(n-i+1)/C2(n)/2;
	printf("%.10lf\n",ans);
	return 0;
}