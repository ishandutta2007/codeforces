#include <bits/stdc++.h>
#define ls now<<1
#define rs now<<1|1
#define m ((l+r)>>1)
using namespace std;
const int Maxn=5e5+10;
int n,q;
struct Node{
	int l[4],mid[4],r[4];
	int lz;
	int len;
	int k=0;
}t[Maxn<<2];
char s[Maxn];
void change(int now){
	swap(t[now].l[0],t[now].l[1]);
	swap(t[now].l[2],t[now].l[3]);
	swap(t[now].r[0],t[now].r[1]);
	swap(t[now].r[2],t[now].r[3]);
	swap(t[now].mid[0],t[now].mid[1]);
	swap(t[now].mid[2],t[now].mid[3]);
	t[now].lz^=1;	
}
void pushdown(int now,int l,int r){
	if(!t[now].lz){
		return;
	}
	change(ls);
	change(rs);
	t[now].lz=0;
}
void clear(Node &p){
	for(int i=0;i<=3;i++){
		p.l[i]=p.r[i]=p.mid[i]=0;
		p.lz=p.len=0;
	}
}
Node merge(Node xx,Node yy){
	Node now;
	clear(now);
	if(xx.len==0){
		return yy;
	}
	if(yy.len==0){
		return xx;
	}
	for(int x=0;x<=1;x++){
		now.mid[x]=max(xx.mid[x],max(yy.mid[x],xx.r[x]+yy.l[x]));
		now.l[x]=xx.l[x];
		if(xx.l[x]==xx.len){
			now.l[x]=max(now.l[x],xx.l[x]+yy.l[x]);
		}
		now.r[x]=yy.r[x];
		if(yy.r[x]==yy.len){
			now.r[x]=max(now.r[x],yy.r[x]+xx.r[x]);
		}		
	}
	for(int x=2;x<=3;x++){
		int k=3-x;
		now.mid[x]=max(xx.mid[x],yy.mid[x]);
		now.mid[x]=max(now.mid[x],max(yy.l[x]+xx.r[k],yy.l[1-k]+xx.r[k]));
		now.mid[x]=max(now.mid[x],xx.r[x]+yy.l[1-k]);
		now.l[x]=xx.l[x];
		if(xx.l[x]==xx.len){
			now.l[x]=xx.l[x]+yy.l[1-k];
			if(xx.l[k]==xx.len){
				now.l[x]=max(now.l[x],xx.l[k]+max(yy.l[1-k],yy.l[x]));
			}
		}
		now.r[x]=yy.r[x];
		if(yy.r[x]==yy.len){
			now.r[x]=yy.r[x]+xx.r[k];
			if(yy.r[1-k]==yy.len){
				now.r[x]=max(now.r[x],max(xx.r[k],xx.r[x])+yy.r[1-k]);
			}
		}
	}
	now.len=xx.len+yy.len;
	return now;
}
void pushup(int now,int l,int r){
	t[now]=merge(t[ls],t[rs]);
}
void build(int now,int l,int r){
	if(l==r){
		int k=(s[l]=='>'?1:0);
		if(k){
			t[now].l[1]=t[now].mid[1]=t[now].r[1]=1;
		}
		else{
			t[now].l[0]=t[now].mid[0]=t[now].r[0]=1;
		}
		t[now].mid[2]=t[now].l[2]=t[now].r[2]=1;
		t[now].l[3]=t[now].mid[3]=t[now].r[3]=1;
		t[now].lz=0;
		t[now].len=r-l+1;
		return;
	}
	build(ls,l,m);
	build(rs,m+1,r);
	pushup(now,l,r);
}
void update(int now,int l,int r,int L,int R){
	if(L>R){
		return;
	}
	if(l==L&&r==R){
		change(now);
		return;
	}
	pushdown(now,l,r);
	update(ls,l,m,L,min(m,R));
	update(rs,m+1,r,max(m+1,L),R);
	pushup(now,l,r);
}
Node quary(int now,int l,int r,int L,int R){
	Node ans;
	clear(ans);
	if(L>R){
		return ans;
	}
	if(l==L&&r==R){
		return t[now];
	}
	pushdown(now,l,r);
	ans=merge(quary(ls,l,m,L,min(m,R)),quary(rs,m+1,r,max(m+1,L),R));
	return ans;
}
int main(){
	scanf("%d%d",&n,&q);
	scanf("%s",s+1);
	build(1,1,n);
	for(int i=1,x,y;i<=q;i++){
		scanf("%d%d",&x,&y);
		update(1,1,n,x,y);
		Node o=quary(1,1,n,x,y);
		int p=0;
		p=max(o.mid[0],max(o.mid[1],o.mid[2]));
		printf("%d\n",p);
	}
	return 0;
}