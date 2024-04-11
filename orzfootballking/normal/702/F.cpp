/*

DP





ll int
 dp 










*/
#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define ll long long
#define gmax(x,y) x=max(x,y)
#define gmin(x,y) x=min(x,y)
#define F first
#define S second
#define P pair
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define V vector
#define RE return
#define ALL(a) a.begin(),a.end()
#define MP make_pair
#define PB emplace_back
#define PF emplace_front
#define FILL(a,b) memset(a,b,sizeof(a))
#define lwb lower_bound
#define upb upper_bound
using namespace std;
P<int,int> p[200005];
bool cmp(P<int,int> x,P<int,int> y){
	RE x.S>y.S||(x.S==y.S)&&(x.F<y.F); 
}
int b[200005];
struct node{
	int sum,val,lc,rc,it,tags,tagv;
};
node a[200005];
int root;
void pushdown(int x){
	if(a[x].tags){
		if(a[x].lc)a[a[x].lc].tags+=a[x].tags,a[a[x].lc].sum+=a[x].tags;
		if(a[x].rc)a[a[x].rc].tags+=a[x].tags,a[a[x].rc].sum+=a[x].tags;
		a[x].tags=0;
	}
	if(a[x].tagv){
		if(a[x].lc)a[a[x].lc].tagv+=a[x].tagv,a[a[x].lc].val+=a[x].tagv;
		if(a[x].rc)a[a[x].rc].tagv+=a[x].tagv,a[a[x].rc].val+=a[x].tagv;
		a[x].tagv=0;
	}
}
void update(int x){
	pushdown(x);
	if(a[x].lc)update(a[x].lc);
	if(a[x].rc)update(a[x].rc);
}
void slipt(int now,int mid,int &x,int &y){
	if(!now){
		x=y=0;RE ;
	}
	pushdown(now);
	if(a[now].val<=mid){
		x=now;
		slipt(a[x].rc,mid,a[x].rc,y);
	}else{
		y=now;
		slipt(a[y].lc,mid,x,a[y].lc);
	}
}
int merge(int x,int y){
	if(!x||!y)RE x^y;
	pushdown(x);pushdown(y);
	if(a[x].it>a[y].it){
		a[x].rc=merge(a[x].rc,y);
		RE x;
	}else{
		a[y].lc=merge(x,a[y].lc);
		RE y;
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	FOR(i,1,n)cin>>p[i].F>>p[i].S;
	sort(p+1,p+n+1,cmp);
	int q;
	cin>>q;
	srand(time(0));
	FOR(i,1,q){
		cin>>b[i];
		int x,y;
		a[i]=(node){
			0,b[i],0,0,rand(),0,0
		};
		slipt(root,b[i],x,y);
		root=merge(merge(x,i),y);
	}
	FOR(i,1,n){
		int x,y,z;
//		cout<<p[i].F<<' '<<p[i].S<<'\n';
		slipt(root,p[i].F-1,x,y);
		slipt(y,2*p[i].F-1,y,z);
//		cout<<x<<' '<<y<<' '<<z<<'\n';
		queue<int> Q;
		if(y)Q.emplace(y);
		while(!Q.empty()){
			int cur=Q.front();Q.pop();
			pushdown(cur);
			if(a[cur].lc)Q.emplace(a[cur].lc);
			if(a[cur].rc)Q.emplace(a[cur].rc);
			int x1,x2;
			a[cur].val-=p[i].F;
			a[cur].sum++;a[cur].lc=a[cur].rc=0;
			slipt(x,a[cur].val,x1,x2);
			x=merge(merge(x1,cur),x2);
		}
		if(z){
			a[z].tagv-=p[i].F;a[z].sum++;a[z].val-=p[i].F;a[z].tags++;
			root=merge(x,z);
		}else root=x;
//		FOR(j,1,q){
//			cout<<a[j].lc<<' '<<a[j].rc<<'\n';
//		} 
	} 
	update(root);
	FOR(i,1,q)cout<<a[i].sum<<' ';
	RE 0;
}