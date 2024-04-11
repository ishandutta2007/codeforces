#include<bits/stdc++.h>
#define il inline
#define vd void
typedef long long ll;
il ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
int lg[50010],st[16][50010],num[100010];
ll cnt[100010];
il ll f(ll a,ll b,ll c,ll n){
	if(n<0)return 0;
	if(a==0)return (n+1)*(b/c);
	if(a>=c||b>=c)return f(a%c,b%c,c,n)+n*(n+1)/2*(a/c)+(n+1)*(b/c);
	ll m=(a*n+b)/c;
	return m<=0?0:n*m-f(c,c-b-1,a,m-1);
}
il ll F(ll a,ll b,ll c,ll n){
	if(a<0)b+=a*n,a=-a;
	if(b<0){ll d=(a-b-1)/a;n-=d;b+=a*d;}
	if(n<0)return 0;
	return n*(n+1)/2*(a/c)+(n+1)*(b/c)+f(a%c,b%c,c,n);
}
ll mid;
il ll calc(int l,int r,ll S){
	ll a=num[l],b=num[r],sa=cnt[a],sb=cnt[b];
	if(S+a*sa+b*sb<=mid)return sa*sb;
	return F(-a,mid-S-a,b,sa-1)-F(-a,mid-S-b*sb-a,b,sa-1);
}
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	int n=gi();for(int i=2;i<=n;++i)lg[i]=lg[i>>1]+1;
	for(int i=1;i<=n;++i)st[0][i]=gi();
	for(int i=1;i<=lg[n];++i)
		for(int j=1;j+(1<<i)-1<=n;++j)
			st[i][j]=std::__gcd(st[i-1][j],st[i-1][j+(1<<i-1)]);
	for(int i=1;i<=n;++i){
		int GCD=0;
		for(int l=i,r;l<=n;l=r+1){
			r=l;GCD=std::__gcd(GCD,st[0][l]);
			for(int j=lg[n];~j;--j)if(st[j][r+1]&&st[j][r+1]%GCD==0)r+=1<<j;
			cnt[GCD]+=r-l+1;
		}
	}
	int k=0;
	for(int i=1;i<=100000;++i)if(cnt[i])num[++k]=i;
	ll l=0,r=1e15,m=1ll*n*(n+1)/2,M=1ll*m*(m+1)/2;
	while(l<r){
		mid=((l+r)>>1);
		ll res=0;
		for(int i=1;i<=k;++i){
			ll len=std::min(mid/num[i],cnt[num[i]]);
			res+=cnt[num[i]]*len-len*(len-1)/2;
		}
		for(int l=1,r=2,S=0,s=0;l<k;++l){
			if(num[l]>mid)break;
			while(r<l+1)S+=cnt[num[r]]*num[r],s+=cnt[num[r]],++r;
			res+=s*cnt[num[l]];
			while(r<k&&S+cnt[num[r]]*num[r]<=mid){
				if(l<r)res+=calc(l,r,S);
				S+=cnt[num[r]]*num[r],s+=cnt[num[r]],++r;
			}
			res+=calc(l,r,S);
			S-=cnt[num[l+1]]*num[l+1];s-=cnt[num[l+1]];
		}
		if(res<(M+1)/2)l=mid+1;
		else r=mid;
	}
	printf("%lld\n",l);
	return 0;
}