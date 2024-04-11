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
int l[100005],r[100005],fr[100005],to[100005];
int f[100005];
V<int> v[600000];
int fa[100005],it[100005];
int getfa(int x){
	RE (x==fa[x])?x:(fa[x]=getfa(fa[x]));
}
void merge(int x,int y){
	if(x==y)RE;
	x=getfa(x);y=getfa(y);
	if(x==y)RE;
	l[x]=min(l[x],l[y]);
	r[x]=max(r[x],r[y]);
	fa[y]=x;
}
void update(int x,int l,int r,int tl,int tr,int p){
	if(l>tr||tl>r)RE;
	if(l>=tl&&r<=tr){
		v[x].PB(p);RE ;
	}
	int mid=(l+r)>>1;
	update(x<<1,l,mid,tl,tr,p);
	update((x<<1)|1,mid+1,r,tl,tr,p);
}
void get(int x,int l,int r,int p,int id){
	bool f=v[x].empty();
	for(auto u:v[x])merge(u,id);
	v[x].clear();
	if(!f)v[x].PB(id);
	if(l==r)RE;
	int mid=(l+r)>>1;
	if(p<=mid)get(x<<1,l,mid,p,id);
	else get((x<<1)|1,mid+1,r,p,id);
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	V<int> v;
	int n;cin>>n;
	FOR(i,1,n){
		cin>>f[i];
		if(f[i]==1){
			cin>>l[i]>>r[i];
			v.PB(l[i]);v.PB(r[i]);
		}else{
			cin>>fr[i]>>to[i];
		}
	}
	sort(ALL(v));
	v.erase(unique(ALL(v)),v.end());
	FOR(i,1,n){
		if(f[i]==2)continue;
		l[i]=lwb(ALL(v),l[i])-v.begin()+1;
		r[i]=lwb(ALL(v),r[i])-v.begin()+1;
	}
	int len=v.size(),cnt=0;
	FOR(i,1,n){
		if(f[i]==1){
			fa[i]=i;it[++cnt]=i;
			if(l[i]<r[i]-1)update(1,1,len,l[i]+1,r[i]-1,i);
			get(1,1,len,l[i],i);
			get(1,1,len,r[i],i);
		}else{
			int t1=getfa(it[fr[i]]),t2=getfa(it[to[i]]);
			if(l[t1]>l[t2]&&l[t1]<r[t2]||r[t1]>l[t2]&&r[t1]<r[t2]||t1==t2){
				cout<<"YES\n";
			}else cout<<"NO\n";
		}
	}
	RE 0;
}