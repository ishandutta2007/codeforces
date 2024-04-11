#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll readint(){
	ll x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

struct ret{int k[32];};

int n,m,q;
int t[600000][2][32],lazy[600000],a[200005];

void update(int id){
	for(int i=0;i<(1<<m);i++){
		t[id][0][i]=t[id<<1][0][t[id<<1|1][0][i]];
		t[id][1][i]=t[id<<1][1][t[id<<1|1][1][i]];
	}
}

void build(int id,int l,int r){
	if(l==r){
		for(int i=0;i<(1<<m);i++){
			if(i!=(1<<m)-1||!a[l]) t[id][0][i]=(i>>1)+(1<<m-1);
			else t[id][0][i]=i>>1;
		}
		for(int i=0;i<(1<<m);i++){
			if(i!=(1<<m)-1||a[l]) t[id][1][i]=(i>>1)+(1<<m-1);
			else t[id][1][i]=i>>1;
		}
		return;
	}
	int mid=(l+r)/2;
	build(id<<1,l,mid);
	build(id<<1|1,mid+1,r);
	update(id);
}

void pushdown(int id){
	if(lazy[id]){
		swap(t[id<<1][0],t[id<<1][1]),swap(t[id<<1|1][0],t[id<<1|1][1]);
		lazy[id<<1]^=1,lazy[id<<1|1]^=1;
		lazy[id]=0;
	}
}

void change(int id,int l,int r,int ql,int qr,int c){
	if(!c) return;
	if(l==ql&&r==qr){
		lazy[id]^=1;
		swap(t[id][0],t[id][1]);
		return;
	}
	pushdown(id);
	int mid=(l+r)/2;
	if(qr<=mid) change(id<<1,l,mid,ql,qr,c);
	else if(ql>mid) change(id<<1|1,mid+1,r,ql,qr,c);
	else change(id<<1,l,mid,ql,mid,c),change(id<<1|1,mid+1,r,mid+1,qr,c);
	update(id);
}

ret query(int id,int l,int r,int ql,int qr){
	if(l==ql&&r==qr){
		ret ans;
		memcpy(ans.k,t[id][0],sizeof(ans.k));
		return ans;
	}
	pushdown(id);
	int mid=(l+r)/2;
	if(qr<=mid) return query(id<<1,l,mid,ql,qr);
	else if(ql>mid) return query(id<<1|1,mid+1,r,ql,qr);
	ret lson=query(id<<1,l,mid,ql,mid),rson=query(id<<1|1,mid+1,r,mid+1,qr),ans;
	for(int i=0;i<(1<<m);i++) ans.k[i]=lson.k[rson.k[i]];
	return ans;
}

int main(){
	n=readint(); m=readint(); q=readint();
	for(int i=1;i<=n;i++) a[i]=readint()&1;
	build(1,1,n);
	int opt,x,y;
	while(q--){
		opt=readint(); x=readint(); y=readint();
		if(opt==1) change(1,1,n,x,y,readint()%2);
		else printf("%d\n",((query(1,1,n,x,y).k[(1<<m)-1]>>(m-1))^1)+1);
	}
	return 0;
}