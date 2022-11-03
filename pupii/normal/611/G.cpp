#include<bits/stdc++.h>
#define pr std::pair<int,int>
#define fi first
#define se second
#define mod 1000000007
typedef long long ll;
ll gi(){
	ll x=0;bool f=1;char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
struct qwq{ll x,y;}v[1000010];
ll operator^(const qwq&a,const qwq&b){return a.x*b.y-a.y*b.x;}
int sV1[1000010],sV1i[1000010];
struct mqwq{int x,y;};
int operator^(const mqwq&a,const mqwq&b){return (1ll*a.x*b.y-1ll*a.y*b.x%mod+mod)%mod;}
mqwq sV2[1000010],sV2i[1000010];
mqwq reduce(qwq x){return{x.x%mod,x.y%mod};}
mqwq operator*(const mqwq&a,int b){return{1ll*a.x*b%mod,1ll*a.y*b%mod};}
void inc(int&a,int b){a=a+b>=mod?a+b-mod:a+b;}
int sum(int a,int b){return a+b>=mod?a+b-mod:a+b;}
int sub(int a,int b){return a>=b?a-b:a+mod-b;}
mqwq operator+(const mqwq&a,const mqwq&b){return{sum(a.x,b.x),sum(a.y,b.y)};}
mqwq operator-(const mqwq&a,const mqwq&b){return{sub(a.x,b.x),sub(a.y,b.y)};}
ll tri(int a,int b,int c){return(v[c]^v[a])+(v[a]^v[b])+(v[b]^v[c]);}
int main(){
	int n=gi();
	for(int i=1;i<=n;++i)v[i].x=gi()+1000000001,v[i].y=gi()+1000000001;
	std::reverse(v+1,v+n+1);
	for(int i=1;i<=n;++i)v[i+n]=v[i];
	v[0]=v[n],v[n+n+1]=v[1];
	for(int i=1;i<=n+n;++i)sV1[i]=((v[i]^v[i+1])%mod+mod)%mod,sV1i[i]=1ll*sV1[i]*i%mod;
	for(int i=1;i<=n+n;++i)sV2[i]=reduce(v[i]),sV2i[i]=sV2[i]*i;
	for(int i=1;i<=n+n;++i)inc(sV1[i],sV1[i-1]),inc(sV1i[i],sV1i[i-1]),inc(sV2[i].x,sV2[i-1].x),inc(sV2[i].y,sV2[i-1].y),inc(sV2i[i].x,sV2i[i-1].x),inc(sV2i[i].y,sV2i[i-1].y);
	ll S=0;
	for(int i=1;i<=n;++i)S+=(v[i-1]^v[i]);
	int ans=0;ll Sq=0,SS=0;
	for(int l=1,r=2;l<=n;++l){
		while(Sq+tri(l,r,r+1)<=S/2)Sq+=tri(l,r,r+1),++r;
		ans=(ans+1ll*r*(sV1[r-1]-sV1[l]+mod)%mod-sV1i[r-1]+sV1i[l]+mod)%mod;
		mqwq vl=reduce(v[l]);
		ans=(ans+(vl^((sV2[r-1]-sV2[l])*r-sV2i[r-1]+sV2i[l])))%mod;
		ans=(ans+(((sV2[r]-sV2[l+1])*(r+1)-sV2i[r]+sV2i[l+1])^vl))%mod;
		SS=SS+r-l-1;Sq-=tri(l,l+1,r);
	}
	ans=(S%mod*(SS%mod)%mod-2*ans%mod+mod)%mod;
	printf("%d\n",ans);
	return 0;
}