#include <bits/stdc++.h>
using namespace std;

const int RLEN=1<<18|1;
inline char nc() {
	static char ibuf[RLEN],*ib,*ob;
	(ib==ob) && (ob=(ib=ibuf)+fread(ibuf,1,RLEN,stdin));
	return (ib==ob) ? -1 : *ib++;
}
inline int rd() {
	char ch=nc(); int i=0,f=1;
	while(!isdigit(ch)) {if(ch=='-') f=-1; ch=nc();}
	while(isdigit(ch)) {i=(i<<1)+(i<<3)+ch-'0'; ch=nc();}
	return i*f;
}

const int N=1e3+50;
int n,m,vis[N];
struct P {
	int x,y,col,id;
	P(int x=0,int y=0,int col=0,int id=0) : x(x),y(y),col(col),id(id) {}
	friend inline P operator -(const P &a,const P &b) {return P(a.x-b.x,a.y-b.y);}
	friend inline int operator *(const P &a,const P &b) {return a.x*b.y-a.y*b.x;}
} p[N],q[N];
typedef vector <P> vp;
typedef pair <int,int> pii;

vector <pii> ans;
inline void add(int x,int y) {ans.push_back(pii(x,y));}
inline bool in(P a,P b,P c,P d) {return (a-d)*(b-d)>0 && (b-d)*(c-d)>0 && (c-d)*(a-d)>0;}
inline void solve(P a,P b,P c) {
	for(int i=1;i<=n;i++) if(in(a,b,c,p[i]) && p[i].col!=a.col) {
		add(p[i].id,c.id);
		solve(c,p[i],b); 
		solve(a,b,p[i]); 
		solve(p[i],c,a);
		return;
	}
	vp vec;
	for(int i=1;i<=n;i++) if(in(a,b,c,p[i])) add(a.id,p[i].id);
}
int main() {
	n=rd();
	for(int i=1;i<=n;i++) p[i].x=rd(), p[i].y=rd(), p[i].col=rd(), p[i].id=i;
	if(n==2) {
		if(p[1].col^p[2].col) puts("1\n1 2");
		else puts("0");
		return 0;
	}
	sort(p+1,p+n+1,[&] (const P &a,const P &b) {return a.x<b.x || (a.x==b.x && a.y<b.y);});
	sort(p+2,p+n+1,[&] (const P &a,const P &b) {return (a-p[1])*(b-p[1])>0;});
	q[m=1]=p[1];
	for(int i=2;i<=n;i++) {
		while(m>=2 && (p[i]-q[m-1])*(q[m]-q[m-1])>0) --m;
		q[++m]=p[i];
	}
	int fir[2]={0,0}, lst[2]={0,0}, cnt=0;
	for(int i=1;i<=m;i++) {
		if(q[i].col!=q[i%m+1].col) {
			++cnt;
			if(cnt>2) {puts("Impossible"); return 0;}
			if(!fir[0]) {
				fir[0]=i, fir[1]=i%m+1;
				if(q[i].col!=q[(i==1) ? m : (i-1)].col) lst[1]=i, lst[0]=i%m+1;
			} else lst[1]=i, lst[0]=i%m+1;
		}
	}
	for(int i=1;i<=m;i++) vis[q[i].id]=1;
	if(!cnt) {
		int tag=0;
		for(int i=1;i<=n;i++) if(!vis[i] && p[i].col!=q[1].col) {
			for(int j=1;j<=m;j++) {
				if(j!=m) add(q[j].id,q[j+1].id);
				solve(q[j],q[j%m+1],p[i]);
			}
			tag=1; break;
		}
		if(!tag) for(int i=1;i<n;i++) add(p[i].id,p[n].id);
	} else {
		for(int i=fir[1];i!=lst[1];i=i%m+1) {
			add(q[i].id,q[i%m+1].id);
			solve(q[i],q[i%m+1],q[lst[0]]);
		}
		for(int i=lst[0];i!=fir[0];i=i%m+1) {
			add(q[i].id,q[i%m+1].id);
			solve(q[i],q[i%m+1],q[fir[1]]);
		}
	}
	cout<<ans.size()<<'\n';
	for(int i=0;i<ans.size();i++) cout<<ans[i].first-1<<' '<<ans[i].second-1<<'\n';
}