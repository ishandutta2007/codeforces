#include<bits/stdc++.h>

using namespace std;

#define N 120000
#define INF 0x3f3f3f3f
#define ls (x<<1)
#define rs (x<<1|1)
#define P(x,y) make_pair(x,y)

int n,ans,a[N],b[N],c[N],mn[N*4],mx[N*4],tag[N*4];
vector<int> vec[N];
map<int,bool> vis;
map<int,pair<int,int> > mp;

void build(int x,int l,int r){
	tag[x]=-1;
	if (l==r){mx[x]=0; mn[x]=l; return;}
	int mid=(l+r)>>1;
	build(ls,l,mid); build(rs,mid+1,r);
	mx[x]=max(mx[ls],mx[rs]);
	mn[x]=min(mn[ls],mn[rs]);
}

void psd(int x,int l,int r,int mid){
	if (tag[x]>=0){
		mx[ls]=mx[rs]=tag[ls]=tag[rs]=tag[x];
		mn[ls]=tag[x]+l; mn[rs]=tag[x]+mid+1;
		tag[x]=-1;
	}
}

void mdf(int x,int l,int r,int R,int k){
	if (l>R) return;
	if (r<=R){
		if (mx[x]<=k){mx[x]=tag[x]=k; mn[x]=k+l; return;}
		if (l==r) return;
		int mid=(l+r)>>1;
		psd(x,l,r,mid);
		if (mx[rs]<=k){
			mx[rs]=tag[rs]=k; mn[rs]=k+mid+1;
			mdf(ls,l,mid,R,k);
		}
		else mdf(rs,mid+1,r,R,k);
		mx[x]=max(mx[ls],mx[rs]);
		mn[x]=min(mn[ls],mn[rs]);
		return;
	}
	int mid=(l+r)>>1;
	psd(x,l,r,mid);
	mdf(ls,l,mid,R,k);
	if (R>mid) mdf(rs,mid+1,r,R,k);
	mx[x]=max(mx[ls],mx[rs]);
	mn[x]=min(mn[ls],mn[rs]);
}

int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;++i){
		scanf("%d",&a[i]);
		if (!vis.count(a[i])){
			vis[a[i]]=1;
			vec[i].push_back(a[i]);
			mp[a[i]]=P(INF,INF);
		}
	}
	for (int i=1;i<=n;++i){
		scanf("%d",&b[i]);
		if (!mp.count(b[i])) mp[b[i]]=P(INF,INF);
		mp[b[i]].first=min(mp[b[i]].first,i);
		if (!vis.count(b[i])){
			vis[b[i]]=1; vec[n+1].push_back(b[i]);
		}
	}
	for (int i=1;i<=n;++i){
		scanf("%d",&c[i]);
		if (!mp.count(c[i])) mp[c[i]]=P(INF,INF);
		mp[c[i]].second=min(mp[c[i]].second,i);
		if (!vis.count(c[i])){
			vis[c[i]]=1; vec[n+1].push_back(c[i]);
		}
	}
	build(1,0,n); ans=INF;
	for (int i=0;i<(int)vec[n+1].size();++i){
		int t=vec[n+1][i],x=mp[t].first,y=mp[t].second;
		mdf(1,0,n,min(x-1,n),y);
	}
	for (int i=n;i>=1;--i){
		ans=min(ans,mn[1]+i);
		for (int j=0;j<(int)vec[i].size();++j){
			int t=vec[i][j],x=mp[t].first,y=mp[t].second;
			mdf(1,0,n,min(x-1,n),y);
		}
	}
	ans=min(ans,mn[1]);
	printf("%d\n",ans);
	
	return 0;
}