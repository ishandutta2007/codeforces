#include<bits/stdc++.h>

using namespace std;

typedef long long LL;
#define N 420000

const LL B1=233,mod1=998244353,B2=377,mod2=1000000007;
LL n0,n1,ans,pw1[N],pw2[N],ipw1[N],ipw2[N];
char s0[N],s1[N];
bool vis[N];

LL inv1(LL x){return x==1?1:(mod1-mod1/x)*inv1(mod1%x)%mod1;}
LL inv2(LL x){return x==1?1:(mod2-mod2/x)*inv2(mod2%x)%mod2;}

struct Hash{
	LL a1,a2,b;
	Hash(LL a1=0,LL a2=0,LL b=0):a1(a1),a2(a2),b(b){}
	bool operator < (const Hash &p) const{
		if (a1!=p.a1) return a1<p.a1;
		if (a2!=p.a2) return a2<p.a2;
		return b<p.b;
	}
	bool operator == (const Hash &p) const{
		return a1==p.a1&&a2==p.a2&&b==p.b;
	}
	Hash operator + (const Hash &p) const{
		return Hash((a1*pw1[p.b]+p.a1)%mod1,(a2*pw2[p.b]+p.a2)%mod2,b+p.b);
	}
	Hash operator << (const Hash &p) const{
		return Hash((a1-p.a1*pw1[b-p.b]%mod1+mod1)%mod1,(a2-p.a2*pw2[b-p.b]%mod2+mod2)%mod2,b-p.b);
	}
	Hash operator >> (const Hash &p) const{
		return Hash((a1-p.a1+mod1)*ipw1[p.b]%mod1,(a2-p.a2+mod2)*ipw2[p.b]%mod2,b-p.b);
	}
};
map<Hash,LL> c[2][2];
map<Hash,bool> vis0,vis1;

Hash gethash(char x){return Hash(x,x,1);}

struct PAM{
	LL n,p,np,cnt,fa[N],par[N][30],len[N],c[N][30],f[N],F[N];
	Hash g[N],h[N],H[N];
	Hash qry(LL l,LL r){
		return h[r]<<h[l-1];
	}
	void build(char s[]){
		n=strlen(s+1);
		for (LL i=1;i<=n;++i) h[i]=h[i-1]+gethash(s[i]);
		for (LL i=n;i;--i) H[i]=H[i+1]+gethash(s[i]);
		fa[0]=1; len[0]=0; fa[1]=0; len[1]=-1; np=cnt=1;
		for (LL i=1;i<=n;++i){
			LL w=s[i]-'a';
			for (p=np;s[i]!=s[i-len[p]-1];p=fa[p]);
			if (!c[p][w]){
				LL now=++cnt,q=fa[p];
				len[now]=len[p]+2; g[now]=qry(i-len[now]+1,i);
				for (;s[i-len[q]-1]!=s[i];q=fa[q]);
				fa[now]=c[q][w]; c[p][w]=now;
				par[now][0]=fa[now];
				for (LL i=1;i<=20;++i) par[now][i]=par[par[now][i-1]][i-1];
			}
			f[i]=np=c[p][w];
		}
		p=0;
		for (LL i=n;i;--i){
			LL w=s[i]-'a';
			for (;s[i]!=s[i+len[p]+1];p=fa[p]);
			F[i]=p=c[p][w];
		}
	}
	bool pld(LL l,LL r){
		return h[r]<<h[l-1]==H[l]<<H[r+1];
	}
	LL double_pld(LL l,LL r){
		LL x=f[r];
		for (LL i=20;~i;--i)
			if (len[par[x][i]]>=r-l+1) x=par[x][i];
		if (len[x]>=r-l+1) x=fa[x];
		if (len[x]>0&&pld(l,r-len[x])) return r-len[x];
		x=F[l];
		for (LL i=20;~i;--i)
			if (len[par[x][i]]>=r-l+1) x=par[x][i];
		if (len[x]>=r-l+1) x=fa[x];
		if (len[x]>0&&pld(l+len[x],r)) return l+len[x]-1;
		return 0;
	}
}P0,P1;

int main(){
	scanf("%s%s",s0+1,s1+1); n0=strlen(s0+1); n1=strlen(s1+1);
	pw1[0]=pw2[0]=ipw1[0]=ipw2[0]=1;
	for (LL i=1,i1=inv1(B1),i2=inv2(B2);i<=n0+n1;++i){
		pw1[i]=pw1[i-1]*B1%mod1;
		ipw1[i]=ipw1[i-1]*i1%mod1;
		pw2[i]=pw2[i-1]*B2%mod2;
		ipw2[i]=ipw2[i-1]*i2%mod2;
	}
	P0.build(s0); P1.build(s1);
	ans=(P0.cnt-1)*(P1.cnt-1);
	for (LL i=0;i<=P0.cnt;++i)
		if (P0.len[P0.fa[i]]>0){
			Hash t=P0.g[i]<<P0.g[P0.fa[i]];
			++c[0][0][t];
			if (P0.len[i]<=P0.len[P0.fa[i]]*2) ++c[0][1][t];
		}
	for (LL i=0;i<=P1.cnt;++i)
		if (P1.len[P1.fa[i]]>0){
			Hash t=P1.g[i]>>P1.g[P1.fa[i]];
			++c[1][0][t];
			if (P1.len[i]<=P1.len[P1.fa[i]]*2) ++c[1][1][t];
		}
	for (auto it:c[0][0])
		ans+=(it.second)*c[1][0][it.first];
	for (auto it:c[0][0])
		ans-=(it.second)*c[1][1][it.first];
	for (auto it:c[1][0])
		ans-=(it.second)*c[0][1][it.first];
	for (LL i=1;i<=n0;++i){
		LL x=P0.f[i];
		LL len=P0.len[x];
		vis0[P0.qry(i-len+1,i)]=1;
	}
	for (LL i=1;i<=n1;++i){
		LL x=P1.f[i];
		LL len=P1.len[x];
		vis1[P1.qry(i-len+1,i)]=1;
	}
	memset(vis,0,sizeof vis);
	for (LL i=1;i<=n0;++i){
		LL x=P0.f[i];
		if (vis[x]||P0.len[P0.fa[x]]<=0) continue;
		vis[x]=1;
		LL len=P0.len[x]-P0.len[P0.fa[x]];
		LL l=i-len+1,r=i;
		LL t=P0.double_pld(l,r);
		if (t){
			Hash tmp=P0.qry(l,r)+P0.qry(l,t);
			ans-=vis1[tmp];
		}
	}
	memset(vis,0,sizeof vis);
	for (LL i=1;i<=n1;++i){
		LL x=P1.F[i];
		if (vis[x]||P1.len[P1.fa[x]]<=0) continue;
		vis[x]=1;
		LL len=P1.len[x]-P1.len[P1.fa[x]];
		LL l=i,r=i+len-1;
		LL t=P1.double_pld(l,r);
		if (t){
			Hash tmp=P1.qry(t+1,r)+P1.qry(l,r);
			ans-=vis0[tmp];
		}
	}
	printf("%lld\n",ans);
	
	return 0;
}