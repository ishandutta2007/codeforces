#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long i64;

const int N=1000005;
int n,m,a[N],b[N],v[N<<1],rt[N];
int st[N],f[N<<1];
pair<int,int> val[N];

namespace bits{
int s[N<<1];

void add(int x){
	while(x<=n) s[x]++,x+=x&(-x);
}

int query(int x){
	int ans=0;
	while(x)
		ans+=s[x],x&=x-1;
	return ans;
}

void clear(){
	for(int i=1;i<=n;i++)
		s[i]=0;
}
}

namespace sgt{
const int N=30000005;
int sz[N],lc[N],rc[N],cnt;

void insert(int &i,int l,int r,int x){
	if(!i) i=++cnt,lc[i]=rc[i]=sz[i]=0;
	sz[i]++;
	if(l==r) return;

	int mid=(l+r)>>1;
	if(x<=mid)
		insert(lc[i],l,mid,x);
	else
		insert(rc[i],mid+1,r,x);
}

int merge(int i,int j,int l,int r){
	if(i==0||j==0) return i|j;
	sz[i]+=sz[j];
	if(l==r) return i;
	int mid=(l+r)>>1;

	lc[i]=merge(lc[i],lc[j],l,mid);
	rc[i]=merge(rc[i],rc[j],mid+1,r);

	return i;
}

int find(int i,int l,int r,int x){
	if(l==r) return l;

	int mid=(l+r)>>1;

	if(x<=sz[lc[i]])
		return find(lc[i],l,mid,x);

	return find(rc[i],mid+1,r,x-sz[lc[i]]);
}

int query(int i,int l,int r,int x,int y){
	if(x>y||!i) return 0;

	if(x<=l&&y>=r)
		return sz[i];

	int mid=(l+r)>>1;
	if(y<=mid)
		return query(lc[i],l,mid,x,y);
	if(x>mid)
		return query(rc[i],mid+1,r,x,y);

	return query(lc[i],l,mid,x,y)+query(rc[i],mid+1,r,x,y);
}
}

void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i],v[i]=a[i];
	for(int i=1;i<=m;i++)
		cin>>b[i],v[n+i]=b[i];
	sort(b+1,b+m+1);
	sort(v+1,v+n+m+1);
	int k=unique(v+1,v+n+m+1)-v-1;
	for(int i=1;i<=n;i++)
		a[i]=lower_bound(v+1,v+k+1,a[i])-v;
	for(int i=1;i<=m;i++)
		b[i]=lower_bound(v+1,v+k+1,b[i])-v;

	int top=0;
	for(int i=1;i<=n;i++){
		pair<int,int> v=make_pair(a[i],0);
		sgt::insert(rt[i],1,k,a[i]);

		while(top&&v<val[top]){
			rt[i]=sgt::merge(rt[i],rt[st[top]],1,k);
			v.first=sgt::find(rt[i],1,k,(sgt::sz[rt[i]]+1)/2);
			v.second=(sgt::query(rt[i],1,k,v.first+1,k)>sgt::query(rt[i],1,k,1,v.first-1));
			top--;
		}

		st[++top]=i,val[top]=v;
	}

	int i=1,j=1,cnt=0,nw=0;
	while(i<=top&&j<=m){
		if(val[i]<=make_pair(b[j],0)){
			for(int j=sgt::sz[rt[st[i]]];j;j--)
				f[++cnt]=a[++nw];
			i++;
		}
		else
			f[++cnt]=b[j++];
	}

	while(i<=top){
		for(int j=sgt::sz[rt[st[i]]];j;j--)
				f[++cnt]=a[++nw];
			i++;
	}

	while(j<=m)
		f[++cnt]=b[j++];

	n+=m;
	i64 ans=0;
	for(int i=1;i<=n;i++){
		ans+=i-1-bits::query(f[i]);
		bits::add(f[i]);
	}

	for(int i=1;i<=n;i++)
		rt[i]=0;
	sgt::cnt=0;
	bits::clear();

	cout<<ans<<'\n';
}

int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

	int t;
	cin>>t;
	while(t--)
		solve();
}