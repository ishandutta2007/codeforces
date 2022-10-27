#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

typedef long long i64;

const int N=300005;
int n,q,k,a[N],b[N];
int que[N];
vector<pair<int,int>> qy[N];
i64 ans[N];

namespace sgt{
int lazy[N<<2],fl[N<<2],fr[N<<2];
i64 s[N<<2];

void build(int i,int l,int r){
	lazy[i]=0;
	fl[i]=fr[i]=1<<30;
	s[i]=1e9*(r-l+1);
	if(l==r)
		return;

	int mid=(l+r)>>1;
	build(i<<1,l,mid),build(i<<1|1,mid+1,r);
}

void cover(int i,int l,int r,int z){
	lazy[i]=fl[i]=fr[i]=z;
	s[i]=1ll*z*(r-l+1);
}

void pushdown(int i,int l,int r){
	if(lazy[i]){
		int mid=(l+r)>>1;
		cover(i<<1,l,mid,lazy[i]);
		cover(i<<1|1,mid+1,r,lazy[i]);
		lazy[i]=0;
	}
}

void modify(int i,int l,int r,int x,int y,int z){
	if(fl[i]<=z)
		return;

	if(x<=l&&y>=r){
		if(fr[i]>=z){
			cover(i,l,r,z);
			return;
		}

		int mid=(l+r)>>1;
		pushdown(i,l,r);
		modify(i<<1,l,mid,x,y,z),modify(i<<1|1,mid+1,r,x,y,z);
		fl[i]=fl[i<<1],fr[i]=fr[i<<1|1];
		s[i]=s[i<<1]+s[i<<1|1];
		return;
	}


	int mid=(l+r)>>1;
	pushdown(i,l,r);

	if(x<=mid)
		modify(i<<1,l,mid,x,y,z);
	if(y>mid)
		modify(i<<1|1,mid+1,r,x,y,z);

	fl[i]=fl[i<<1],fr[i]=fr[i<<1|1];
	s[i]=s[i<<1]+s[i<<1|1];
}

i64 query(int i,int l,int r,int x,int y){
	if(x<=l&&y>=r)
		return s[i];

	pushdown(i,l,r);

	int mid=(l+r)>>1;
	if(y<=mid)
		return query(i<<1,l,mid,x,y);
	if(x>mid)
		return query(i<<1|1,mid+1,r,x,y);
	return query(i<<1,l,mid,x,y)+query(i<<1|1,mid+1,r,x,y);
}
}

int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

	cin>>n>>q>>k;
	for(int i=0;i<n;i++)
		cin>>a[i];

	for(int i=n-1,h=1,t=0;~i;i--){
		while(t>=h&&a[que[t]]>=a[i]) t--;
		que[++t]=i;

		if(que[h]>=i+k)
			h++;

		b[i]=a[que[h]];
	}

	for(int i=1;i<=q;i++){
		int l,r;
		cin>>l>>r;
		qy[l-1].push_back(make_pair(r-1,i));
	}

	for(int l=0;l<k;l++){
		sgt::build(1,0,n/k);
		for(int i=n-1-l;i>=0;i-=k){
			if(i!=n-1-l)
				sgt::modify(1,0,n/k,i/k+1,(n-l)/k,b[i]);

			sgt::modify(1,0,n/k,i/k,i/k,a[i]);
			for(auto tp:qy[i])
				ans[tp.second]=sgt::query(1,0,n/k,i/k,tp.first%k>=i%k?tp.first/k:tp.first/k-1);
		}
	}

	for(int i=1;i<=q;i++)
		cout<<ans[i]<<'\n';
}