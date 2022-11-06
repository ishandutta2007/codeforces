#include<bits/stdc++.h>
using namespace std;
#define next Next
//#define int long long
char buf[1<<21],*p1=buf,*p2=buf;
inline int gc(){return p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++;}
inline int read()
{
    int ret=0,f=0;char c=gc();
    while(!isdigit(c)){if(c=='-')f=1;c=gc();}
    while(isdigit(c)){ret=ret*10+c-48;c=gc();}
    if(f)return -ret;return ret;
}
void write(int x)
{
    if(x<10)
    {
        putchar('0'+x);
        return;
    }
    write(x/10);
    putchar('0'+x%10);
}
#define mid (l+r)/2
const int N=1e5+5;
int n,m,opt,x,y,a[N]; 
struct node{
    int sum,ans,l,r,ansl,ansr,ql,qr;
}tree[N*4],tree2[N*4];
struct Node{
    int val,l,r,ql,qr,opt;
};
bool operator < (Node a,Node b)
{
    return a.val<b.val;
}
void pushup(int nod,int l,int r)
{
    tree[nod].sum=tree[nod*2].sum+tree[nod*2+1].sum;
    if(tree[nod*2].sum+tree[nod*2+1].l>tree[nod*2].l)
    {
        tree[nod].l=tree[nod*2].sum+tree[nod*2+1].l;
        tree[nod].qr=tree[nod*2+1].qr;
    }
    else{
        tree[nod].l=tree[nod*2].l;
        tree[nod].qr=tree[nod*2].qr;
    }
    if(tree[nod*2+1].sum+tree[nod*2].r>tree[nod*2+1].r)
    {
        tree[nod].r=tree[nod*2+1].sum+tree[nod*2].r;
        tree[nod].ql=tree[nod*2].ql;
    }
    else{
        tree[nod].r=tree[nod*2+1].r;
        tree[nod].ql=tree[nod*2+1].ql;
    }
    tree[nod].ans=tree[nod*2].ans;
    tree[nod].ansl=tree[nod*2].ansl;
    tree[nod].ansr=tree[nod*2].ansr;
    if(tree[nod*2+1].ans>tree[nod].ans)
    {
        tree[nod].ans=tree[nod*2+1].ans;
        tree[nod].ansl=tree[nod*2+1].ansl;
        tree[nod].ansr=tree[nod*2+1].ansr;	
    }
    if(tree[nod*2].r+tree[nod*2+1].l>tree[nod].ans)
    {
        tree[nod].ans=tree[nod*2].r+tree[nod*2+1].l;
        tree[nod].ansl=tree[nod*2].ql;
        tree[nod].ansr=tree[nod*2+1].qr;			
    }
}
void build(int nod,int l,int r)
{
    if(l==r)
    {
        tree[nod]=(node){a[l],a[l],a[l],a[l],l,r,l,r};
        return;
    }
    build(nod*2,l,mid);
    build(nod*2+1,mid+1,r);
    pushup(nod,l,r);
}
void change(int nod,int l,int r,int x,int y)
{
    if(l==r)
    {
        tree[nod]=(node){y,y,y,y,l,r,l,r};
        return;
    }
    if(x<=mid)change(nod*2,l,mid,x,y);
    else change(nod*2+1,mid+1,r,x,y);
    pushup(nod,l,r);
}
node find(int nod,int l,int r,int L,int R)
{
    if(l==L&&r==R)return tree[nod];
    if(R<=mid)return find(nod*2,l,mid,L,R);
    else if(L>mid)return find(nod*2+1,mid+1,r,L,R);
    node x=find(nod*2,l,mid,L,mid),y=find(nod*2+1,mid+1,r,mid+1,R),res;
    res.sum=x.sum+y.sum;
    if(x.sum+y.l>x.l)
    {
        res.l=x.sum+y.l;
        res.qr=y.qr;
    }
    else{
        res.l=x.l;
        res.qr=x.qr;
    }
    if(y.sum+x.r>y.r)
    {
        res.r=y.sum+x.r;
        res.ql=x.ql;
    }
    else{
        res.r=y.r;
        res.ql=y.ql;
    }
    res.ans=x.ans;
    res.ansl=x.ansl;
    res.ansr=x.ansr;
    if(y.ans>res.ans)
    {
        res.ans=y.ans;
        res.ansl=y.ansl;
        res.ansr=y.ansr;	
    }
    if(x.r+y.l>res.ans)
    {
        res.ans=x.r+y.l;
        res.ansl=x.ql;
        res.ansr=y.qr;			
    }
    return res;
}

void pushup2(int nod,int l,int r)
{
    tree2[nod].sum=tree2[nod*2].sum+tree2[nod*2+1].sum;
    if(tree2[nod*2].sum+tree2[nod*2+1].l>tree2[nod*2].l)
    {
        tree2[nod].l=tree2[nod*2].sum+tree2[nod*2+1].l;
        tree2[nod].qr=tree2[nod*2+1].qr;
    }
    else{
        tree2[nod].l=tree2[nod*2].l;
        tree2[nod].qr=tree2[nod*2].qr;
    }
    if(tree2[nod*2+1].sum+tree2[nod*2].r>tree2[nod*2+1].r)
    {
        tree2[nod].r=tree2[nod*2+1].sum+tree2[nod*2].r;
        tree2[nod].ql=tree2[nod*2].ql;
    }
    else{
        tree2[nod].r=tree2[nod*2+1].r;
        tree2[nod].ql=tree2[nod*2+1].ql;
    }
    tree2[nod].ans=tree2[nod*2].ans;
    tree2[nod].ansl=tree2[nod*2].ansl;
    tree2[nod].ansr=tree2[nod*2].ansr;
    if(tree2[nod*2+1].ans>tree2[nod].ans)
    {
        tree2[nod].ans=tree2[nod*2+1].ans;
        tree2[nod].ansl=tree2[nod*2+1].ansl;
        tree2[nod].ansr=tree2[nod*2+1].ansr;	
    }
    if(tree2[nod*2].r+tree2[nod*2+1].l>tree2[nod].ans)
    {
        tree2[nod].ans=tree2[nod*2].r+tree2[nod*2+1].l;
        tree2[nod].ansl=tree2[nod*2].ql;
        tree2[nod].ansr=tree2[nod*2+1].qr;			
    }
}
void build2(int nod,int l,int r)
{
    if(l==r)
    {
        tree2[nod]=(node){-a[l],-a[l],-a[l],-a[l],l,r,l,r};
        return;
    }
    build2(nod*2,l,mid);
    build2(nod*2+1,mid+1,r);
    pushup2(nod,l,r);
}
void change2(int nod,int l,int r,int x,int y)
{
    if(l==r)
    {
        tree2[nod]=(node){-y,-y,-y,-y,l,r,l,r};
        return;
    }
    if(x<=mid)change2(nod*2,l,mid,x,y);
    else change2(nod*2+1,mid+1,r,x,y);
    pushup2(nod,l,r);
}
node find2(int nod,int l,int r,int L,int R)
{
    if(l==L&&r==R)return tree2[nod];
    if(R<=mid)return find2(nod*2,l,mid,L,R);
    else if(L>mid)return find2(nod*2+1,mid+1,r,L,R);
    node x=find2(nod*2,l,mid,L,mid),y=find2(nod*2+1,mid+1,r,mid+1,R),res;
    res.sum=x.sum+y.sum;
    if(x.sum+y.l>x.l)
    {
        res.l=x.sum+y.l;
        res.qr=y.qr;
    }
    else{
        res.l=x.l;
        res.qr=x.qr;
    }
    if(y.sum+x.r>y.r)
    {
        res.r=y.sum+x.r;
        res.ql=x.ql;
    }
    else{
        res.r=y.r;
        res.ql=y.ql;
    }
    res.ans=x.ans;
    res.ansl=x.ansl;
    res.ansr=x.ansr;
    if(y.ans>res.ans)
    {
        res.ans=y.ans;
        res.ansl=y.ansl;
        res.ansr=y.ansr;	
    }
    if(x.r+y.l>res.ans)
    {
        res.ans=x.r+y.l;
        res.ansl=x.ql;
        res.ansr=y.qr;			
    }
    return res;
}
signed main(){
	n=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	build(1,1,n);
	build2(1,1,n);
	m=read();
	for(int i=1;i<=m;i++){
		int opt=read();
		if(opt==0){
			int x=read(),y=read();
			a[x]=y;
			change(1,1,n,x,y);
			change2(1,1,n,x,y);
		}
		else{
			int l=read(),r=read(),k=read(),ma=0;
			priority_queue<Node>q;
			node xu=find(1,1,n,l,r);
			q.push((Node){xu.ans,l,r,xu.ansl,xu.ansr,1});
			for(int i=1;i<=k;i++){
				Node u=q.top();q.pop();
				if(u.val<0){
					break;
				}
				ma+=u.val;
				if(u.opt==1){
					node xu=find2(1,1,n,u.ql,u.qr);
					if(xu.ans>0){
						q.push((Node){xu.ans,u.ql,u.qr,xu.ansl,xu.ansr,0});
					}
					if(u.ql>u.l){
						node xu=find(1,1,n,u.l,u.ql-1);
						if(xu.ans>0){
							q.push((Node){xu.ans,u.l,u.ql-1,xu.ansl,xu.ansr,1});
						}
					}
					if(u.qr<u.r){
						node xu=find(1,1,n,u.qr+1,u.r);
						if(xu.ans>0){
							q.push((Node){xu.ans,u.qr+1,u.r,xu.ansl,xu.ansr,1});
						}
					}
				}
				else{
					node xu=find(1,1,n,u.ql,u.qr);
					if(xu.ans>0){
						q.push((Node){xu.ans,u.ql,u.qr,xu.ansl,xu.ansr,1});
					}
					if(u.ql>u.l){
						node xu=find2(1,1,n,u.l,u.ql-1);
						if(xu.ans>0){
							q.push((Node){xu.ans,u.l,u.ql-1,xu.ansl,xu.ansr,0});
						}
					}
					if(u.qr<u.r){
						node xu=find2(1,1,n,u.qr+1,u.r);
						if(xu.ans>0){
							q.push((Node){xu.ans,u.qr+1,u.r,xu.ansl,xu.ansr,0});
						}
					}
				}
				if(q.empty()){
					break;
				}
			}
			write(ma);
			putchar('\n');
		}
	}
	return 0;
}