#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
const int N=5e5+5;
struct node{
	pair<bool,int> l[2],r[2];
	int mx[2],le,ri;
	bool flip;
}em;
vector<node> d(4*N);
string s;
node merge(node a,node b){
	if(a.mx[0]==-1)
		return b;
	if(b.mx[0]==-1)
		return a;
	node sol;
	for(int i=0;i<2;i++){
		if(a.ri-a.le+1==a.l[i].s){
			if(a.r[i].f==1||b.l[i].f==1)
				sol.l[i]={a.l[i].f,a.l[i].s+b.l[i].s};
			else
				sol.l[i]=a.l[i];
		}
		else
			sol.l[i]=a.l[i];
		if(b.ri-b.le+1==b.r[i].s){
			if(b.l[i].f==1||a.r[i].f==1)
				sol.r[i]={b.r[i].f,b.r[i].s+a.r[i].s};
			else
				sol.r[i]=b.r[i];
		}
		else
			sol.r[i]=b.r[i];
		sol.mx[i]=max({a.mx[i],b.mx[i],sol.l[i].s,sol.r[i].s});
		if(a.r[i].f||b.l[i].f)
			sol.mx[i]=max(sol.mx[i],a.r[i].s+b.l[i].s);
	}
	sol.flip=0;
	sol.le=a.le;
	sol.ri=b.ri;
	return sol;
}
void sw(int i){
	swap(d[i].l[0],d[i].l[1]);
	swap(d[i].r[0],d[i].r[1]);
	swap(d[i].mx[0],d[i].mx[1]);
	d[i].flip^=1;
}
void build(int l=0,int r=N-1,int i=1){
	if(l==r){
		d[i].le=d[i].ri=l;
		d[i].mx[0]=d[i].mx[1]=1;
		if(s[l]=='<'){
			d[i].l[0]={1,1};
			d[i].r[0]={0,1};
			d[i].l[1]={0,1};
			d[i].r[1]={1,1};
			d[i].flip=0;
		}
		else{
			d[i].l[0]={0,1};
			d[i].r[0]={1,1};
			d[i].l[1]={1,1};
			d[i].r[1]={0,1};
			d[i].flip=0;
		}
		return;
	}
	int m=(l+r)>>1;
	build(l,m,2*i);
	build(m+1,r,2*i+1);
	d[i]=merge(d[2*i],d[2*i+1]);
}
node getFlip(int qs,int qe,int l=0,int r=N-1,int i=1){
	if(qs>r||qe<l)
		return em;
	if(qs<=l&&qe>=r){
		sw(i);
		return d[i];
	}
	int m=(l+r)>>1;
	if(d[i].flip){
		d[i].flip=0;
		sw(2*i);
		sw(2*i+1);
	}
	node lft=getFlip(qs,qe,l,m,2*i),rght=getFlip(qs,qe,m+1,r,2*i+1);
	node ret=merge(lft,rght);
	d[i]=merge(d[2*i],d[2*i+1]);
	return ret;
}
int main()
{
	em.mx[0]=-1;
	int n,q;
	scanf("%i %i",&n,&q);
	cin >> s;
	while(s.size()<N)
		s+='>';
	build();
	for(int i=0;i<q;i++){
		int l,r;
		scanf("%i %i",&l,&r);
		printf("%i\n",getFlip(l-1,r-1).mx[0]);
	}
	return 0;
}