#include<algorithm>
#include<stdio.h>
#include<string.h>
#include<queue>
#define cmax(x,y) ((y)>x?x=(y):x)
#define Cmax(x,y) ({typeof(y) t=y; cmax(x,t);})
#define cmin(x,y) ((y)<x?x=(y):x)
#define dmax(x,y) ((x)>(y)?(x):(y))
#define dmin(x,y) ((x)<(y)?(x):(y))
int F() {
	register int a,b,c;
	while(c=getchar(),c!='-'&&(c<'0'||c>'9'));
	b = (c=='-');
	for(a=b?0:c-'0';c=getchar(),c>='0'&&c<='9';a=a*10+c-'0');
	return b?-a:a;
}
const int N=1e5+10,S=1<<19,oo=1<<30;
int n,y[N<<1],ys,x1[N],y1[N],x2[N],y2[N];
struct Rect {
	int col,x,y1,y2;
	bool event;
	//event: {remove,create}
	bool operator<(const Rect &o) const {
		return x<o.x || x==o.x&&event>o.event || x==o.x&&event==o.event&&(col<o.col ^ event);
	}
} re[N<<1];
typedef std::priority_queue<int> Heap;
int submin[S],submax[S],ql,qr,qv;
bool ok[N],deleted[N];
Heap seg[S];
int top(register int x) {
	register Heap &h=seg[x];
	while(!h.empty()&&deleted[h.top()]) h.pop();
	return h.empty()?0:h.top();
}
void maintain(register int o) {
	register int tl=top(o<<1),tr=top(o<<1|1);
	cmax(tl,submax[o<<1]),cmax(tr,submax[o<<1|1]);
	submax[o]=0;
	if(!ok[tl] && tl>=submin[o<<1]) cmax(submax[o],tl);
	if(!ok[tr] && tr>=submin[o<<1|1]) cmax(submax[o],tr);
}
void rem(register int o,register int l,register int r,register int ql,register int qr) {
	if(l>qr||r<ql) return;
	if(ql<=l&&r<=qr) return;
	register int m=(l+r)>>1;
	rem(o<<1,l,m,ql,qr);
	rem(o<<1|1,m+1,r,ql,qr);
	if(l<r) maintain(o);
}
void add(register int o,register int l,register int r,register int maxblock) {
	if(l>qr||r<ql) return;
	Cmax(maxblock,top(o));
	if(ql<=l&&r<=qr) {
		seg[o].push(qv);
		if(qv>=maxblock&&qv>submin[o]) {
			ok[qv]=1;
		}
	} else {
		register int m=(l+r)>>1;
		add(o<<1,l,m,maxblock);
		add(o<<1|1,m+1,r,maxblock);
	}
	if(l<r) maintain(o);
	submin[o] = l<r ? dmin(submin[o<<1],submin[o<<1|1]) : 0;
	Cmax(submin[o],top(o));
}
void del(register int o,register int l,register int r,register int maxblock) {
	if(l>qr||r<ql) return;
	Cmax(maxblock,top(o));
	submin[o] = l<r ? dmin(submin[o<<1],submin[o<<1|1]) : 0;
	Cmax(submin[o],top(o));
	if(ql<=l&&r<=qr) {
		register int seen=top(o);
		if(seen && !ok[seen] && seen>=maxblock && seen>=submin[o]) {
			ok[seen]=1;
			rem(1,0,ys-1,y1[seen-1],y2[seen-1]);
		}
		while((seen=submax[o])>=maxblock && seen) {
			ok[seen]=1;
			rem(1,0,ys-1,y1[seen-1],y2[seen-1]);
		}
	} else {
		register int m=(l+r)>>1;
		del(o<<1,l,m,maxblock);
		del(o<<1|1,m+1,r,maxblock);
	}
	if(l<r) maintain(o);
	submin[o] = l<r ? dmin(submin[o<<1],submin[o<<1|1]) : 0;
	register int t=top(o);
	cmax(submin[o],t);
	if(t && !ok[t] && t>=maxblock && t>=submin[o]) {
		ok[t]=1;
		rem(1,0,ys-1,y1[t-1],y2[t-1]);
	}
}
int main() {
	register int i,ans=1;
	n=F();
	for(i=0;i<n;++i) {
		x1[i]=F();
		y[ys++]=y1[i]=F();
		x2[i]=F();
		y[ys++]=y2[i]=F();
	}
	std::sort(y,y+ys);
	ys=std::unique(y,y+ys)-y;
	for(i=0;i<n;++i) {
		re[i].col=re[i+n].col=i+1;
		re[i  ].x=x1[i];
		re[i+n].x=x2[i];
		re[i].y1=re[i+n].y1=y1[i]=std::lower_bound(y,y+ys,y1[i])-y;
		re[i].y2=re[i+n].y2=y2[i]=std::lower_bound(y,y+ys,y2[i])-y-1;
		re[i  ].event=1;
		re[i+n].event=0;
	}
	std::sort(re,re+n+n);
	for(i=0;i<n+n;++i) {
		if(re[i].event) {
			//create
			ql=re[i].y1,qr=re[i].y2,qv=re[i].col;
			add(1,0,ys-1,0);
			if(ok[qv]) rem(1,0,ys-1,ql,qr);
		} else {
			//remove
			deleted[re[i].col]=1;
			ql=re[i].y1,qr=re[i].y2,qv=re[i].col;
			del(1,0,ys-1,0);
		}
	}
	for(i=1;i<=n;++i) ans+=ok[i];
	printf("%d\n",ans);
	return 0;
}