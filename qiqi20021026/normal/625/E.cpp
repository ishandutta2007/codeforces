#include<bits/stdc++.h>

using namespace std;

#define INF 0x3f3f3f3f
#define N 120000
#define P(x,y) make_pair(x,y)
#define ff first
#define ss second

int n,m,xb,p[N],c[N],pre[N],nxt[N],out[N];
set<pair<int,int> > se;
struct node{
	int x,y,i;
	bool operator < (const node p) const{
		return x<p.x;
	}
}a[N];

int dist(int x,int y){
	if (x==y) return INF;
	int d=(p[y]-p[x]+m)%m;
	if (y<x) d+=c[y];
	if (d>=m) return INF;
	if (d<=c[x]) return 1;
	if (c[x]<=c[y]) return INF;
	return (d-c[y]-1)/(c[x]-c[y])+1;
}

int main(){
	scanf("%d%d",&n,&m);
	if (n==1){puts("1\n1"); return 0;}
	for (int i=1;i<=n;++i){
		scanf("%d%d",&a[i].x,&a[i].y);
		p[i]=a[i].x; c[i]=a[i].y; a[i].i=i;
	}
	sort(a+1,a+n+1);
	for (int i=2;i<n;++i){
		pre[a[i].i]=a[i-1].i;
		nxt[a[i].i]=a[i+1].i;
		se.insert(P(dist(a[i].i,nxt[a[i].i]),a[i].i));
	}
	nxt[a[1].i]=a[2].i; pre[a[1].i]=a[n].i; se.insert(P(dist(a[1].i,a[2].i),a[1].i));
	nxt[a[n].i]=a[1].i; pre[a[n].i]=a[n-1].i; se.insert(P(dist(a[n].i,a[1].i),a[n].i));
	while (1){
		if (se.size()<2||se.begin()->ff>=INF) break;
		int i=se.begin()->ss,j=nxt[i];
		se.erase(P(dist(j,nxt[j]),j));
		se.erase(P(dist(i,j),i));
		se.erase(P(dist(pre[i],i),pre[i]));
		pre[nxt[j]]=pre[j];
		nxt[pre[j]]=nxt[j];
 		p[i]+=dist(i,j); --c[i];
		se.insert(P(dist(pre[i],i),pre[i]));
		se.insert(P(dist(i,nxt[i]),i));
	}
	printf("%d\n",se.size());
	while (!se.empty()){
		out[++xb]=se.begin()->ss;
		se.erase(se.begin());
	}
	for (int i=1;i<=xb;++i) printf(i==xb?"%d\n":"%d ",out[i]);
	
	return 0;
}