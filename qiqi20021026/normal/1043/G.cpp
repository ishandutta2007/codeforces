#include<bits/stdc++.h>

using namespace std;

typedef long long LL;
#define N 600000

int n,m,p,l,r,cnt[N],lg[N],sum[N],pre[N][30],f[N],g[N];
bool cov[N<<6];
char s[N];

struct Hash{
	const LL B1=233,mod1=998244353,B2=377,mod2=1000000007;
	LL h1[N],pw1[N],h2[N],pw2[N];
	Hash(){memset(h1,0,sizeof h1); memset(h2,0,sizeof h2);}
	void build(){
		pw1[0]=pw2[0]=1; h1[0]=h2[0]=0;
		for (int i=1;i<=n;++i){
			pw1[i]=pw1[i-1]*B1%mod1;
			h1[i]=(h1[i-1]*B1+s[i])%mod1;
			pw2[i]=pw2[i-1]*B2%mod2;
			h2[i]=(h2[i-1]*B2+s[i])%mod2;
		}
	}
	LL qry(int l,int r){
		LL t1=(h1[r]-h1[l-1]*pw1[r-l+1]%mod1+mod1)%mod1;
		LL t2=(h2[r]-h2[l-1]*pw2[r-l+1]%mod2+mod2)%mod2;
		return t1<<31|t2;
	}
}H;
struct SA{
	int sa[N],sa2[N],x[N],y[N],rk[N],lcp[22][N];
	void resort(int m){
		memset(cnt,0,sizeof cnt);
		for (int i=1;i<=n;++i) ++cnt[y[i]];
		for (int i=1;i<=m;++i) cnt[i]+=cnt[i-1];
		for (int i=1;i<=n;++i) sa2[cnt[y[i]]--]=i;
		memset(cnt,0,sizeof cnt);
		for (int i=1;i<=n;++i) ++cnt[x[i]];
		for (int i=1;i<=m;++i) cnt[i]+=cnt[i-1];
		for (int i=n;i;--i) sa[cnt[x[sa2[i]]]--]=sa2[i];
		rk[sa[1]]=1;
		for (int i=2;i<=n;++i){
			int u=sa[i],v=sa[i-1];
			rk[u]=rk[v]+(!(x[u]==x[v]&&y[u]==y[v]));
		}
	}
	void build(){
		for (int i=1;i<=n;++i){x[i]=s[i]-'a'+1; y[i]=1;}
		for (int i=n+1;i<=n*2;++i) rk[i]=0;
		resort(26);
		for (int k=1;k<n;k<<=1){
			for (int i=1;i<=n;++i){x[i]=rk[i]; y[i]=rk[i+k];}
			resort(n);
		}
		for (int i=1,j,h=0;i<=n;lcp[0][rk[i++]]=h)
			for (h?--h:h,j=sa[rk[i]-1];j&&s[i+h]==s[j+h];++h);
		for (int i=1;i<=20;++i)
			for (int j=1;j+(1<<i)-1<=n;++j) lcp[i][j]=min(lcp[i-1][j],lcp[i-1][j+(1<<(i-1))]);
	}
	int qry(int x,int y){
		x=rk[x]; y=rk[y];
		if (x>y) swap(x,y);
		++x; int l=lg[y-x+1];
		return min(lcp[l][x],lcp[l][y-(1<<l)+1]);
	}
}sa0,sa1;

namespace p0{
	bool ask(int l,int r){
		for (int i=0;i<26;++i)
			if (pre[r][i]-pre[l-1][i]>1) return 0;
		return 1;
	}
}

namespace p1{
	bool check(int l,int r,int i){
		return H.qry(l,r-i)==H.qry(l+i,r);
	}
	bool ask(int l,int r){
		int len=r-l+1;
		for (int i=1;i*i<=len;++i)
			if (len%i==0){
				if (i<len&&check(l,r,i)) return 1;
				if (len/i<len&&check(l,r,len/i)) return 1;
			}
		return 0;
	}
}

namespace p2{
	bool check_border(int l,int r){
		int len=r-l+1;
		for (int i=1;i<=p&&i<len;++i)
			if (H.qry(l,l+i-1)==H.qry(r-i+1,r)) return 1;
		for (int i=1,mn=n-l+1;i<=p&&sa0.rk[l]+i<=n;++i){
			int t=sa0.rk[l]+i,j=sa0.sa[t];
			mn=min(mn,sa0.lcp[0][t]);
			if (j>l&&j<=r&&j+mn>r) return 1;
		}
		for (int i=1,mn=n-l+1;i<=p&&sa0.rk[l]-i;++i){
			int t=sa0.rk[l]-i,j=sa0.sa[t];
			mn=min(mn,sa0.lcp[0][t+1]);
			if (j>l&&j<=r&&j+mn>r) return 1;
		}
		return 0;
	}
	bool ask(int l,int r){
		if (f[l]<=r||g[r]>=l) return 1;
		return check_border(l,r);
	}
}

namespace p3{
	#define ls (x<<1)
	#define rs (x<<1|1)
	int seg[N<<1];
	void build(int x,int l,int r){
		if (l==r){seg[x]=f[l]; return;}
		int mid=(l+r)>>1;
		build(ls,l,mid); build(rs,mid+1,r);
		seg[x]=min(seg[ls],seg[rs]);
	}
	int qmin(int x,int l,int r,int L,int R){
		if (l>=L&&r<=R) return seg[x];
		int mid=(l+r)>>1,ret=n+1;
		if (L<=mid) ret=min(ret,qmin(ls,l,mid,L,R));
		if (R>mid) ret=min(ret,qmin(rs,mid+1,r,L,R));
		return ret;
	}
	bool ask(int l,int r){
		if (pre[r][s[l]-'a']-pre[l][s[l]-'a']) return 1;
		if (pre[r-1][s[r]-'a']-pre[l-1][s[r]-'a']) return 1;
		if (qmin(1,1,n,l,r)<=r) return 1;
		return 0;
	}
}

void getsqr(){
	for (int i=1;i<=n;++i){f[i]=n+1; g[i]=0;}
	for (int i=1,j=0;i<=n;++i) lg[i]=j+=(1<<(j+1))<=i;
	for (int i=1;i<=n;++i) sum[i]=sum[i-1]+n/i;
	for (int i=1;i<=n;++i){
		int l=0,r=0;
		for (int j=i;j+i<=n;j+=i) if (j>r){
			l=sa1.qry(n-j+1,n-(j+i)+1),r=sa0.qry(j,j+i);
			l=j-l+1; r=j+r-1;
			if (r-l+1<i||cov[sum[i-1]+j/i]) continue;
			for (int k=i*2;l+k*2-1<=r+i;k+=i) cov[sum[k-1]+(l+k-1)/k]=1;
			for (int k=l;k<=r-i+1;++k){
				f[k]=min(f[k],k+i*2-1);
				g[k+i*2-1]=max(g[k+i*2-1],k);
			}
		}
	}
	p3::build(1,1,n);
}

int main(){
	scanf("%d%s%d",&n,s+1,&m); p=sqrt(n)+10;
	H.build();
	sa0.build(); reverse(s+1,s+n+1); sa1.build(); reverse(s+1,s+n+1);
	for (int i=1;i<=n;++i)
		for (int j=0;j<26;++j)
			pre[i][j]=pre[i-1][j]+(s[i]-'a'==j);
	getsqr();
	while (m--){
		scanf("%d%d",&l,&r);
		if (p0::ask(l,r)) puts("-1");
		else
			if (p1::ask(l,r)) puts("1");
			else
				if (p2::ask(l,r)) puts("2");
				else
					if (p3::ask(l,r)) puts("3");
					else puts("4");
	}
	
	return 0;
}