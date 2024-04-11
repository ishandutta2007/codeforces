#include<bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

template <typename T> bool chkmax(T &x,T y){return x<y?x=y,true:false;}
template <typename T> bool chkmin(T &x,T y){return x>y?x=y,true:false;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,k,m,q;
vector<int> adj[100005];
int f[30],p[30];

int getf(int x){return x==f[x]?x:f[x]=getf(f[x]);}

bool merge(int x,int y){
	int fx=getf(x),fy=getf(y);
	if(fx==fy) return false;
	f[fx]=fy;
	return true;
}

struct node{
	int l,r,ans,len;
	int a[2][6];
	node operator+(const node c)const{
		if(!c.ans) return *this;
		if(!ans) return c;
		node ret;
		ret.l=l,ret.r=c.r,ret.len=len+c.len,ret.ans=ans+c.ans;
		for(int i=1;i<=25;i++) f[i]=i,p[i]=0;
		int ncnt=0;
		for(int i=1;i<=min(5,len);i++){
			for(auto v:adj[r-i+1]){
				if(v<c.l||v>c.r) continue;
				if(merge(c.a[0][v-c.l+1]+12,a[1][i])) ret.ans--;
			}
		}
		for(int i=1;i<=min(5,ret.len);i++){
			int tmp;
			if(i<=min(5,len)) tmp=a[0][i];
			else tmp=c.a[0][i-len]+12;
			tmp=getf(tmp);
			if(!p[tmp]) p[tmp]=++ncnt;
			ret.a[0][i]=p[tmp];
		}
		for(int i=1;i<=min(5,ret.len);i++){
			int tmp;
			if(i<=min(5,c.len)) tmp=c.a[1][i]+12;
			else tmp=a[1][i-c.len];
			tmp=getf(tmp);
			if(!p[tmp]) p[tmp]=++ncnt;
			ret.a[1][i]=p[tmp];
		}
		return ret;
	}
}t[300000];

void build(int id,int l,int r){
	if(l==r){
		t[id].l=l,t[id].r=r;
		t[id].ans=1,t[id].len=1;
		t[id].a[0][1]=t[id].a[1][1]=1;
		return;
	}
	int mid=(l+r)/2;
	build(id<<1,l,mid);
	build(id<<1|1,mid+1,r);
	t[id]=t[id<<1]+t[id<<1|1];
}

node query(int id,int l,int r,int ql,int qr){
	if(ql>qr){
		node tmp;
		tmp.ans=0;
		return tmp;
	}
	if(l==ql&&r==qr) return t[id];
	int mid=(l+r)/2;
	if(qr<=mid) return query(id<<1,l,mid,ql,qr);
	else if(ql>mid) return query(id<<1|1,mid+1,r,ql,qr);
	else return query(id<<1,l,mid,ql,mid)+query(id<<1|1,mid+1,r,mid+1,qr);
}

int main(){
	n=readint(); k=readint(); m=readint();
	int x,y;
	for(int i=1;i<=m;i++){
		x=readint(); y=readint();
		adj[x].push_back(y),adj[y].push_back(x);
	}
	build(1,1,n);
	q=readint();
	while(q--){
		x=readint(); y=readint();
		printf("%d\n",query(1,1,n,x,y).ans);
	}
	return 0;
}