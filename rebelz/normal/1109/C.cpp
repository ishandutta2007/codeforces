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
	ll l,r,s;
	node(int l=0,int r=0,int s=0):l(l),r(r),s(s){}
	bool operator<(const node c)const{return l<c.l;}
	bool operator<=(const node c)const{return l<=c.l;}
	node operator+(const int c)const{return node(l+c,r,s);}
};

struct trp{
	node x;
	int ch[2],siz,lll,rrr;
	ll sum,mina;
}t[100005];

int n,rt,tot;

ll getsum(node x){return (x.r-x.l)*x.s;}
int newnode(int l,int r,int s){t[++tot].x=node(l,r,s),t[tot].mina=t[tot].sum=getsum(t[tot].x),t[tot].lll=l,t[tot].rrr=r,t[tot].siz=1;return tot;}

void update(int id){
	t[id].lll=t[id].ch[0]?t[t[id].ch[0]].lll:t[id].x.l,t[id].rrr=t[id].ch[1]?t[t[id].ch[1]].rrr:t[id].x.r;
	t[id].mina=min(min(t[t[id].ch[0]].mina,t[t[id].ch[0]].sum+getsum(t[id].x)),t[t[id].ch[0]].sum+getsum(t[id].x)+t[t[id].ch[1]].mina);
	t[id].sum=t[t[id].ch[0]].sum+t[t[id].ch[1]].sum+getsum(t[id].x);
	t[id].siz=1+t[t[id].ch[0]].siz+t[t[id].ch[1]].siz;
}

ll rnd(){
	static int seed=19260817;
	return (unsigned int)(seed*=48271ll);
}

int merge(int x,int y){
	if(!x||!y) return x+y;
	if(rnd()%(t[x].siz+t[y].siz)<t[x].siz){
		t[x].ch[1]=merge(t[x].ch[1],y); update(x);
		return x;
	}
	else{
		t[y].ch[0]=merge(x,t[y].ch[0]); update(y);
		return y;
	}
}

void split(int now,node k,int &x,int &y){
	if(!now) return (void)(x=y=0);
	if(k<=t[now].x) y=now,split(t[now].ch[0],k,x,t[now].ch[0]);
	else x=now,split(t[now].ch[1],k,t[now].ch[1],y);
	update(now);
}

int findr(int x){
	if(!t[x].ch[1]) return x;
	return findr(t[x].ch[1]);
}

int findl(int x){
	if(!t[x].ch[0]) return x;
	return findl(t[x].ch[0]);
}

double getans(int id,ll v){
	if(t[id].mina+v>0) return -1;
	if(t[t[id].ch[0]].mina+v<=0) return getans(t[id].ch[0],v);
	else if(t[t[id].ch[0]].sum+getsum(t[id].x)+v<=0) return t[t[id].ch[0]].rrr-t[t[id].ch[0]].lll+1.0*(v+t[t[id].ch[0]].sum)/(-t[id].x.s);
	else return t[t[id].ch[0]].rrr-t[t[id].ch[0]].lll+t[id].x.r-t[id].x.l+getans(t[id].ch[1],v+t[t[id].ch[0]].sum+getsum(t[id].x));
}

void print(int id){
	if(!id) return;
	cout<<"TEST "<<t[id].x.l<<' '<<t[id].x.r<<' '<<t[id].x.s<<' '<<getsum(t[id].x)<<' '<<t[id].sum<<' '<<t[id].mina<<' '<<t[id].lll<<' '<<t[id].rrr<<endl;
	print(t[id].ch[0]);
	print(t[id].ch[1]);
}

double query(int l,int r,ll v){
	if(v==0) return l;
	int a,b,c;
	split(rt,node(l),a,b);
	split(b,node(r+1),b,c);
//	cout<<"########################################"<<endl;
//	print(b);
//	cout<<"########################################"<<endl;
	double ret=getans(b,v);
	if(ret==-1){
		rt=merge(merge(a,b),c);
		return -1;
	}
	ret+=t[findl(b)].x.l;
	rt=merge(merge(a,b),c);
	return ret>r?-1:ret;
}

int main(){
	n=readint();
	t[0].mina=1e9+1;
	rt=newnode(0,1e9+1,0);
	int opt,x,y,a,b,c,d;
	for(int i=1;i<=n;i++){
//		print(rt);
		opt=readint(); x=readint();
		if(opt==1){
			split(rt,node(x),a,c);
			split(a,t[findr(a)].x,a,b);
			int tmp=newnode(x,t[b].x.r,readint());
			t[b].x.r=t[b].rrr=x,t[b].sum=t[b].mina=getsum(t[b].x);
			rt=merge(merge(merge(a,b),tmp),c);
		}
		else if(opt==2){
			split(rt,node(x),a,c);
			split(a,t[findr(a)].x,a,b);
			split(c,t[findl(c)].x+1,c,d);
			t[b].x.r=t[b].rrr=d?t[findl(d)].x.l:t[c].x.r,t[b].sum=t[b].mina=getsum(t[b].x);
			rt=merge(merge(a,b),d);
		}
		else{
			y=readint();
			printf("%.10lf\n",query(x,y,readint()));
		}
	}
	return 0;
}