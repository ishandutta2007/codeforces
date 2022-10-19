#include<bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<LL,LL> pii;
#define P(x,y) make_pair(x,y)
#define N 600000
#define ls (x<<1)
#define rs (x<<1|1)

const LL mod=1000000007;
const LL MX=2000000000LL;
LL n,m,x,y,sum[N<<2],a[N],nxt[N],lst[N],ans[N],tail;
vector<pii> vec[N];
struct tag{
	LL x,y;
	tag(LL x=0,LL y=0):x(x),y(y){}
	tag operator * (const tag &p) const{
		return tag(x*p.x,x*p.y+y);
	}
	tag operator ^ (const tag &p) const{
		return tag(x*p.x%mod,(x*p.y+y)%mod);
	}
}seg[N<<2];

void add(LL x,LL l,LL r,LL L,LL R,LL s){
	if (l>=L&&r<=R){
		sum[x]=(sum[x]+s)%mod;
		return;
	}
	LL mid=(l+r)>>1;
	if (L<=mid) add(ls,l,mid,L,R,s);
	if (R>mid) add(rs,mid+1,r,L,R,s);
}

LL qry(LL x,LL l,LL r,LL k){
	if (l==r) return sum[x];
	LL mid=(l+r)>>1,ret=0;
	if (k<=mid) ret=qry(ls,l,mid,k);
	else ret=qry(rs,mid+1,r,k);
	return (ret+sum[x])%mod;
}

void psd(LL x,LL l){
	if (l>=nxt[tail]){
		seg[ls]=seg[x]^seg[ls];
		seg[rs]=seg[x]^seg[rs];
	}
	else{
		seg[ls]=seg[x]*seg[ls];
		seg[rs]=seg[x]*seg[rs];
	}
	seg[x]=tag(1,0);
}

void mdf(LL x,LL l,LL r,LL L,LL R,tag k){
	if (l>=L&&r<=R){
		if (l>=nxt[tail]){
			seg[x]=k^seg[x];
		}
		else{
			seg[x]=k*seg[x];
		}
		return;
	}
	psd(x,l);
	LL mid=(l+r)>>1;
	if (L<=mid) mdf(ls,l,mid,L,R,k);
	if (R>mid) mdf(rs,mid+1,r,L,R,k);
}

LL ask(LL x,LL l,LL r,LL k){
	if (l==r) return seg[x].y;
	psd(x,l);
	LL mid=(l+r)>>1;
	if (k<=mid) return ask(ls,l,mid,k);
	return ask(rs,mid+1,r,k);
}

int main(){
	scanf("%lld%lld",&n,&m);
	for (LL i=1;i<=n;++i) scanf("%lld",a+i);
	for (LL i=1;i<=m;++i){
		scanf("%lld%lld",&x,&y);
		vec[x].push_back(P(y,i));
	}
	tail=n;
	for (LL i=n;i;--i){
		LL k=i+1;
		for (;k<=tail;k=nxt[k]){
			LL tmp=ask(1,1,n,k);
			if (tmp<0){
				add(1,1,n,k,nxt[k]-1,tmp%mod*2%mod);
				mdf(1,1,n,k,nxt[k]-1,tag());
				nxt[i+1]=nxt[k];
				lst[nxt[i+1]]=i+1;
				if (k==tail) tail=i+1;
			}
			else break;
		}
		while (tail>=i){
			LL tmp=ask(1,1,n,tail);
			if (tmp>=MX) tail=lst[tail];
			else break;
		}
		nxt[i]=i+1; lst[i+1]=i;
		mdf(1,1,n,i,nxt[tail]-1,tag(2,a[i]));
		if (nxt[tail]<=n) mdf(1,1,n,nxt[tail],n,tag(2,a[i]));
		for (LL j=0;j<(LL)vec[i].size();++j){
			LL x=vec[i][j].first,y=vec[i][j].second;
			ans[y]=ask(1,1,n,x)+qry(1,1,n,x);
		}
	}
	for (LL i=1;i<=m;++i) printf("%lld\n",(ans[i]%mod+mod)%mod);
	
	return 0;
}