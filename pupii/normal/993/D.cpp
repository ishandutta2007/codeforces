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
struct laji{ll a,b;}s[101];
il bool operator <(const laji&a,const laji&b){
	if(a.a^b.a)return a.a>b.a;
	else return a.b<b.b;
}
ll S[55];
ll f[55][55];
il vd chkmn(ll&a,ll b){if(b<a)a=b;}
int main(){
#ifndef ONLINE_JUDGE
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	int n=gi();
	for(int i=1;i<=n;++i)s[i].a=gi()*1000ll;
	for(int i=1;i<=n;++i)s[i].b=gi();
	std::sort(s+1,s+n+1);
	ll l=0,r=1000000000000ll,mid;
	while(l<r){
		mid=((l+r)>>1);
		for(int i=1;i<=n;++i)S[i]=s[i].a-mid*s[i].b+S[i-1];
		memset(f,63,sizeof f);
		f[0][0]=0;
		for(int i=1,p;i<=n;i=p)
			for(int j=0;j<=n;++j){
				p=i;while(s[p].a==s[i].a)++p;
				for(int k=0;k<=p-i&&k<=j;++k)chkmn(f[p-1][j-k+(p-i-k)],f[i-1][j]+S[p-1]-S[i+k-1]);
			}
		ll res=1e18;for(int i=0;i<=n;++i)chkmn(res,f[n][i]);
		if(res>0)l=mid+1;
		else r=mid;
	}
	printf("%lld\n",l);
	return 0;
}