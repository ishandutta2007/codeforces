// LUOGU_RID: 91337851
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
inline ll read(){
	ll x=0;
	bool f=0;
	char c=getchar();
	while(!isdigit(c)){
		if(c=='-') f=1;
		c=getchar();
	}
	while(isdigit(c)){
		x=x*10+c-'0';
		c=getchar();
	}
	return f?-x:x;
}
const int maxn=1e6+5;
int n,x,y,z,a[maxn],m=0,b[maxn],s[maxn];
bool c[maxn];
ll ans=0;
pair<int,ll> chk(ll k){
	int p=1,p2=1;
	for(int i=1;i<=m;i++) p*=a[b[i]];
	int cnt=0;
	ll res=p;
	for(int i=0;i<=m;i++){
		if(i&&!c[i]) p2*=a[b[i]];
		int x;
		if(p2==1||(__int128)k*p2>(1ll*p*p2-p)*2e9) x=b[i+1];
		else x=lower_bound(a+b[i]+1,a+b[i+1],((__int128)k*p2-1)/(1ll*p*p2-p)+1)-a;
		cnt+=b[i+1]-x;
		res+=1ll*s[x]*p+1ll*(s[b[i]+1]-s[x])*p/p2;
	}
	return {cnt,res};
}
ll solve(){
	int xx=x;
	for(int i=1;i<=m;i++) if(c[i]) xx-=z;
	if(xx<0) return 0;
	xx/=y;
	ll l=1,r=4e18;
	while(l<r){
		ll mid=l+(r-l)/2;
		if(chk(mid).first<=xx) r=mid;
		else l=mid+1;
	}
	auto p=chk(r);
	int sss=0;
	for(int i=1;i<=m;i++) sss+=c[i];
	return p.second+(r-1)*(min(xx,n-m)-p.first);
}
void dfs(int x,int mx){
	if(x>m){
		ans=max(ans,solve());
		return;
	}
	c[x]=0;
	dfs(x+1,max(mx,a[b[x]]));
	if(a[b[x]]>mx){
		c[x]=1;
		dfs(x+1,mx);
	}
}
int main(){
#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif
	n=read();
	x=read();
	y=read();
	z=read();
	for(int i=1;i<=n;i++){
		char c[5];
		scanf("%s",c);
		a[i]=read();
		if(c[0]=='*'){
			if(a[i]==1) a[i]=0;
			else b[++m]=i;
		}
	}
	b[m+1]=n+1;
	for(int i=0;i<=m;i++){
		sort(a+b[i]+1,a+b[i+1]);
		for(int j=b[i+1]-1;j>b[i];j--) s[j]=s[j+1]+a[j];
	}
	dfs(1,0);
	printf("%lld\n",ans);
#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
#endif
	return 0;
}