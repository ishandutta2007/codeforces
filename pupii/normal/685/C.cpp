#include<bits/stdc++.h>
typedef long long ll;
ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
int n;
ll x[100010],y[100010],z[100010];
ll solve(ll X,ll Y,ll Z){
	ll ret=0;
	for(int i=1;i<=n;++i)ret=std::max(ret,llabs(x[i]-X)+llabs(y[i]-Y)+llabs(z[i]-Z));
	return ret;
}
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	int T=gi();
	while(T--){
		n=gi();
		for(int i=1;i<=n;++i)x[i]=gi(),y[i]=gi(),z[i]=gi();
		if(n==1){printf("%lld %lld %lld\n",x[1],y[1],z[1]);continue;}
		ll X=0,Y=0,Z=0,ans=solve(X,Y,Z);
		for(ll d=1e18;d;){
			bool f=1;
			for(ll x=-d;f&&x<=d;x+=d)
				for(ll y=-d;f&&y<=d;y+=d)
					for(ll z=-d;f&&z<=d;z+=d){
						ll res=solve(X+x,Y+y,Z+z);
						if(res<ans)ans=res,X+=x,Y+=y,Z+=z,f=0;
					}
			if(f)d>>=1;
		}
		printf("%lld %lld %lld\n",X,Y,Z);
	}
	return 0;
}