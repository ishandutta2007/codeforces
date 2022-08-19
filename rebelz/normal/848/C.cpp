#include<bits/stdc++.h>

#define mp make_pair
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

struct node{
	int lch,rch; ll val;
}t[15000005];

int n,m,ncnt;
int rt[100005],a[100005],lst[100005],nxt[100005];
set<int> s[100005];

void change(int &id,int l,int r,int p,ll c){
	if(!id) id=++ncnt;
	t[id].val+=c;
	if(l==r) return;
	int mid=(l+r)/2;
	if(p<=mid) change(t[id].lch,l,mid,p,c);
	else change(t[id].rch,mid+1,r,p,c);
}

ll query(int id,int l,int r,int ql,int qr){
	if(!id) return 0;
	if(l==ql&&r==qr) return t[id].val;
	int mid=(l+r)/2;
	if(qr<=mid) return query(t[id].lch,l,mid,ql,qr);
	else if(ql>mid) return query(t[id].rch,mid+1,r,ql,qr);
	else return query(t[id].lch,l,mid,ql,mid)+query(t[id].rch,mid+1,r,mid+1,qr);
}

int lowbit(int x){return x&(-x);}
void add(int x,int y,ll c){if(x>n||y>n)return;for(;x<=n;x+=lowbit(x))change(rt[x],1,n,y,c);}
ll ask(int x,int y){ll ret=0;for(;x;x-=lowbit(x))ret+=query(rt[x],1,n,1,y);return ret;}
void update(int l1,int r1,int l2,int r2,ll c){if(l1>r1||l2>r2)return;add(l1,l2,c),add(l1,r2+1,-c),add(r1+1,l2,-c),add(r1+1,r2+1,c);}

int main(){
	n=readint(); m=readint();
	for(int i=1;i<=n;i++) a[i]=readint();
	for(int i=1;i<=n;i++){
		update(lst[a[i]]+1,i,i,n,-i);
		lst[a[i]]=i;
	}
	for(int i=1;i<=n;i++) nxt[i]=n+1;
	for(int i=n;i>=1;i--){
		update(1,i,i,nxt[a[i]]-1,i);
		nxt[a[i]]=i;
	}
	for(int i=1;i<=n;i++) s[a[i]].insert(i);
	int opt,x,y,lf,rg; set<int>::iterator ilf,irg;
	for(int i=1;i<=m;i++){
		opt=readint(); x=readint(); y=readint();
		if(opt==1){
			ilf=s[a[x]].find(x),irg=s[a[x]].upper_bound(x);
			if(ilf==s[a[x]].begin()) lf=0;
			else lf=*(--ilf);
			if(irg==s[a[x]].end()) rg=n+1;
			else rg=*irg;
			update(lf+1,x,rg,n,x-(rg==n+1?0:rg));
			update(1,lf,x,rg-1,lf-x);
			s[a[x]].erase(s[a[x]].find(x));
			ilf=s[y].lower_bound(x),irg=s[y].lower_bound(x);
			if(ilf==s[y].begin()) lf=0;
			else lf=*(--ilf);
			if(irg==s[y].end()) rg=n+1;
			else rg=*irg;
			update(lf+1,x,rg,n,(rg==n+1?0:rg)-x);
			update(1,lf,x,rg-1,x-lf);
			s[y].insert(x);
			a[x]=y;
		}
		else printf("%lld\n",ask(x,y));
	}
	return 0;
}