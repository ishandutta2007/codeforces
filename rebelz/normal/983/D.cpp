#include<bits/stdc++.h>

#define y1 dmytxdy
#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef long double ld;

template <typename T> bool chkmin(T &x,T y){return x>y?x=y,1:0;}
template <typename T> bool chkmax(T &x,T y){return x<y?x=y,1:0;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,nx,ny;
int x1[100005],y1[100005],x2[100005],y2[100005],px[200005],py[200005],mx[600000],mn[600000];
bool vis[100005];
vector<int> a[200005],b[200005];
set<int> s[600000];

void update(int id){
	mx[id]=max(mx[id<<1],mx[id<<1|1]);
	mn[id]=min(mn[id<<1],mn[id<<1|1]);
	if(s[id].empty()) return;
	int tmp=*(--s[id].end());
	chkmax(mn[id],tmp);
	if(tmp>mx[id]){
		if(vis[tmp]||tmp<mn[id]) mx[id]=0;
		else mx[id]=tmp;
	}
}

void change(int id,int l,int r,int ql,int qr,int c,int tp){
	if(l==ql&&r==qr){
		if(tp>0) s[id].insert(c);
		else s[id].erase(c);
		if(l==r){
			mn[id]=s[id].empty()?0:*(--s[id].end());
			if(vis[mn[id]]) mx[id]=0;
			else mx[id]=mn[id];
		}
		else update(id);
		return;
	}
	int mid=(l+r)/2;
	if(qr<=mid) change(id<<1,l,mid,ql,qr,c,tp);
	else if(ql>mid) change(id<<1|1,mid+1,r,ql,qr,c,tp);
	else change(id<<1,l,mid,ql,mid,c,tp),change(id<<1|1,mid+1,r,mid+1,qr,c,tp);
	update(id);
}

void del(int id,int l,int r,int ql,int qr){
	if(l==ql&&r==qr){
		if(l==r){
			mn[id]=s[id].empty()?0:*(--s[id].end());
			if(vis[mn[id]]) mx[id]=0;
			else mx[id]=mn[id];
		}
		else update(id);
		return;
	}
	int mid=(l+r)/2;
	if(qr<=mid) del(id<<1,l,mid,ql,qr);
	else if(ql>mid) del(id<<1|1,mid+1,r,ql,qr);
	else del(id<<1,l,mid,ql,mid),del(id<<1|1,mid+1,r,mid+1,qr);
	update(id);
}

int main(){
	n=readint();
	for(int i=1;i<=n;i++) px[++nx]=x1[i]=readint(),py[++ny]=y1[i]=readint(),px[++nx]=x2[i]=readint(),py[++ny]=y2[i]=readint();
	sort(px+1,px+nx+1);
	sort(py+1,py+ny+1);
	nx=unique(px+1,px+nx+1)-px-1;
	ny=unique(py+1,py+ny+1)-py-1;
	for(int i=1;i<=n;i++){
		x1[i]=lower_bound(px+1,px+nx+1,x1[i])-px;
		y1[i]=lower_bound(py+1,py+ny+1,y1[i])-py;
		x2[i]=lower_bound(px+1,px+nx+1,x2[i])-px;
		y2[i]=lower_bound(py+1,py+ny+1,y2[i])-py;
		a[x1[i]].pb(i);
		b[x2[i]].pb(i);
	}
	int ans=1;
	for(int i=1;i<=nx;i++){
		for(auto r:a[i]) change(1,1,ny,y1[r],y2[r]-1,r,1);
		for(auto r:b[i]) change(1,1,ny,y1[r],y2[r]-1,r,-1);
		while(mx[1]) vis[mx[1]]=1,ans++,del(1,1,ny,y1[mx[1]],y2[mx[1]]-1);
	}
	printf("%d\n",ans);
	return 0;
}