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

const int inf=1<<30;
int n,q;

struct sgt{
	ll maxa[300000][2],cnt[300000],all[300000],sum[300000],lazy[300000];
	void build(int id,int l,int r){
		maxa[id][0]=inf,maxa[id][1]=-inf,lazy[id]=inf,cnt[id]=r-l+1;
		if(l==r) return;
		int mid=(l+r)/2;
		build(id<<1,l,mid);
		build(id<<1|1,mid+1,r);
	}
	void minimize(int id,ll c){
		sum[id]-=maxa[id][0]*cnt[id]*all[id];
		chkmin(maxa[id][0],c); chkmin(lazy[id],c);
		all[id]=1;
		sum[id]+=maxa[id][0]*cnt[id];
	}
	void pushdown(int id){
		if(lazy[id]<inf){
			minimize(id<<1,lazy[id]);
			minimize(id<<1|1,lazy[id]);
			lazy[id]=inf;
		}
	}
	void getmax(int id,ll c){
		if(c>maxa[id][0]) maxa[id][1]=maxa[id][0],maxa[id][0]=c;
		else if(c>maxa[id][1]&&c<maxa[id][0]) maxa[id][1]=c;
	}
	void update(int id){
		all[id]=all[id<<1]&all[id<<1|1],sum[id]=sum[id<<1]+sum[id<<1|1],cnt[id]=0;
		maxa[id][0]=maxa[id][1]=-inf;
		for(int i=0;i<2;i++) getmax(id,maxa[id<<1][i]),getmax(id,maxa[id<<1|1][i]);
		cnt[id]+=cnt[id<<1]*(maxa[id<<1][0]==maxa[id][0])+cnt[id<<1|1]*(maxa[id<<1|1][0]==maxa[id][0]);
	}
	void change(int id,int l,int r,int ql,int qr,ll c){
		if(maxa[id][0]<=c) return;
		if(l==ql&&r==qr&&maxa[id][1]<c) return minimize(id,c);
		pushdown(id);
		int mid=(l+r)/2;
		if(qr<=mid) change(id<<1,l,mid,ql,qr,c);
		else if(ql>mid) change(id<<1|1,mid+1,r,ql,qr,c);
		else change(id<<1,l,mid,ql,mid,c),change(id<<1|1,mid+1,r,mid+1,qr,c);
		update(id);
	}
}t[2];

ll query(int id,int l,int r,int ql,int qr){
	if(!t[0].sum[id]||!t[1].sum[id]) return 0;
	if(l==ql&&r==qr&&t[0].all[id]&&t[1].all[id]) return t[0].sum[id]+t[1].sum[id];
	t[0].pushdown(id),t[1].pushdown(id);
	int mid=(l+r)/2;
	if(qr<=mid) return query(id<<1,l,mid,ql,qr);
	else if(ql>mid) return query(id<<1|1,mid+1,r,ql,qr);
	else return query(id<<1,l,mid,ql,mid)+query(id<<1|1,mid+1,r,mid+1,qr);
}

int main(){
	q=readint();
	n=100000;
	t[0].build(1,1,n);
	t[1].build(1,1,n);
	int opt,l,r,x;
	for(int i=1;i<=q;i++){
		opt=readint();
		if(opt==1){
			l=readint(); r=readint()-1; x=readint();
			if(x>0) t[0].change(1,1,n,l,r,x);
			else t[1].change(1,1,n,l,r,-x);
		}
		else{
			l=readint(); r=readint()-1;
			printf("%lld\n",query(1,1,n,l,r));
		}
	}
	return 0;
}