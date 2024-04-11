// xtqqwq
#include<bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef long double ld;

template <typename T> bool chkmin(T &x,T y){return x>y?x=y,1:0;}
template <typename T> bool chkmax(T &x,T y){return x<y?x=y,1:0;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n;
int cnt[2],mina[600000],maxa[600000],sum[600000],num[600000],tag[600000];
char s[200005];

void update(int id){
	mina[id]=min(mina[id<<1],sum[id<<1]+mina[id<<1|1]);
	maxa[id]=max(maxa[id<<1],sum[id<<1]+maxa[id<<1|1]);
	sum[id]=sum[id<<1]+sum[id<<1|1];
	num[id]=num[id<<1]+num[id<<1|1];
}

void build(int id,int l,int r){
	tag[id]=0;
	if(l==r){
		int c=s[l]-'0'?1:-1;
		mina[id]=maxa[id]=sum[id]=c;
		num[id]=s[l]-'0';
		return;
	}
	int mid=(l+r)/2;
	build(id<<1,l,mid);
	build(id<<1|1,mid+1,r);
	update(id);
}

void addtag(int id,int l,int r,int c){
	mina[id]=min(c,c*(r-l+1));
	maxa[id]=max(c,c*(r-l+1));
	sum[id]=c*(r-l+1);
	num[id]=(c>0)*(r-l+1);
	tag[id]=c;
}

void pushdown(int id,int l,int r){
	if(tag[id]){
		int mid=(l+r)/2;
		addtag(id<<1,l,mid,tag[id]);
		addtag(id<<1|1,mid+1,r,tag[id]);
		tag[id]=0;
	}
}

void cover(int id,int l,int r,int ql,int qr,int c){
	if(l==ql&&r==qr) return addtag(id,l,r,c);
	pushdown(id,l,r);
	int mid=(l+r)/2;
	if(qr<=mid) cover(id<<1,l,mid,ql,qr,c);
	else if(ql>mid) cover(id<<1|1,mid+1,r,ql,qr,c);
	else cover(id<<1,l,mid,ql,mid,c),cover(id<<1|1,mid+1,r,mid+1,qr,c);
	update(id);
}

pii query(int id,int l,int r,int ql,int qr,int &cur){
	if(l==ql&&r==qr){
		pii ret=mp(cur+mina[id],cur+maxa[id]);
		cur+=sum[id];
		return ret;
	}
	pushdown(id,l,r);
	int mid=(l+r)/2;
	if(qr<=mid) return query(id<<1,l,mid,ql,qr,cur);
	else if(ql>mid) return query(id<<1|1,mid+1,r,ql,qr,cur);
	else{
		pii lson=query(id<<1,l,mid,ql,mid,cur),rson=query(id<<1|1,mid+1,r,mid+1,qr,cur);
		return mp(min(lson.fi,rson.fi),max(lson.se,rson.se));
	}
}

int ask(int id,int l,int r,int x,int cur,bool fl){
	if(!fl&&cur+maxa[id]<x) return l-1;
	if(fl&&cur+mina[id]>x) return l-1;
	if(l==r) return l;
	pushdown(id,l,r);
	int mid=(l+r)/2,tmp=ask(id<<1|1,mid+1,r,x,cur+sum[id<<1],fl);
	if(tmp<=mid) return ask(id<<1,l,mid,x,cur,fl);
	else return tmp;
}

int getnum(int id,int l,int r,int ql,int qr){
	if(l==ql&&r==qr) return num[id];
	pushdown(id,l,r);
	int mid=(l+r)/2;
	if(qr<=mid) return getnum(id<<1,l,mid,ql,qr);
	else if(ql>mid) return getnum(id<<1|1,mid+1,r,ql,qr);
	else return getnum(id<<1,l,mid,ql,mid)+getnum(id<<1|1,mid+1,r,mid+1,qr);
}

void solve(){
	n=readint();
	scanf("%s",s+1);
	cnt[0]=cnt[1]=0;
	for(int i=1;i<=n;i++) cnt[s[i]-'0']++;
	if(cnt[1]>cnt[0]){
		swap(cnt[0],cnt[1]);
		for(int i=1;i<=n;i++) s[i]=((s[i]-'0')^1)+'0';
		reverse(s+1,s+n+1);
	}
	build(1,1,n);
	int pl=n+1,ans=0;
	for(int i=n;i>=1;i--) if(s[i]=='1') pl=i;
	while(1){
		if(pl==n-cnt[1]+1) break;
		int cur=0;
		pii tmp=pl>1?query(1,1,n,1,pl-1,cur):mp(0,0);
		chkmin(tmp.fi,0),chkmax(tmp.se,0);
		cur=0;
		int pr=ask(1,1,n,tmp.fi,cur,0);
		cur=0;
		chkmin(pr,ask(1,1,n,tmp.se,cur,1));
		int b=getnum(1,1,n,1,pr);
		cover(1,1,n,1,pr-b,-1);
		cover(1,1,n,pr-b+1,pr,1);
		pl=pr-b+1;
		ans++;
	}
	printf("%d\n",ans);
}

int main(){
	int T=readint();
	while(T--) solve();
	return 0;
}