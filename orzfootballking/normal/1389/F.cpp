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
struct Segtree{
	int n;
	int maxi[1100000],d[1100000],val[1100000];
	void init(int len){
		n=len+1;
	}
	void pd(int p,int l,int r){
		if(l!=r){
			maxi[p<<1]+=d[p];
			val[(p<<1)|1]+=d[p];
			maxi[(p<<1)|1]+=d[p];
			val[(p<<1)|1]+=d[p];
			d[p<<1]+=d[p];
			d[(p<<1)|1]+=d[p]; 
		}
		d[p]=0;
	}
	void add(int p,int l,int r,int tl,int tr,int x){
		pd(p,l,r);
		if(l>=tl&&r<=tr){
			d[p]+=x;
			val[p]+=x;
			maxi[p]+=x;
			RE;
		}
		if(l>tr||tl>r)RE;
		int mid=(l+r)>>1;
		add(p<<1,l,mid,tl,tr,x);
		add((p<<1)|1,mid+1,r,tl,tr,x);
		maxi[p]=max(maxi[p<<1],maxi[(p<<1)|1]);
	}
	int get(int p,int l,int r,int tl,int tr){
		pd(p,l,r);
		if(l>=tl&&r<=tr){
			RE maxi[p];
		}
		if(l>tr||tl>r)RE 0;
		int mid=(l+r)>>1;
		RE max(get(p<<1,l,mid,tl,tr),get((p<<1)|1,mid+1,r,tl,tr));
	}
	void add(int l,int r,int x){
		add(1,1,n,l+1,r+1,x);
	}
	int get(int l,int r){
		RE get(1,1,n,l+1,r+1);
	}
}T[2]; 
int l[200005],r[200005],t[200005];
V<int> v,lst[400005][2];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	FOR(i,1,n){
		cin>>l[i]>>r[i]>>t[i];
		v.PB(l[i]);
		v.PB(r[i]);t[i]--;
	}
	sort(ALL(v));
	v.erase(unique(ALL(v)),v.end());
	FOR(i,1,n){
		l[i]=lwb(ALL(v),l[i])-v.begin()+1;
		r[i]=lwb(ALL(v),r[i])-v.begin()+1;
		lst[r[i]][t[i]].PB(l[i]);
	}
	int len=v.size();
	T[0].init(len);
	T[1].init(len);
	FOR(i,1,len){
		for(auto u:lst[i][0]){
			T[0].add(0,u-1,1);
		}
		for(auto u:lst[i][1]){
			T[1].add(0,u-1,1);
		}
		int now=max(T[0].get(0,i-1),T[1].get(0,i-1));
		T[1].add(i,i,now);
		T[0].add(i,i,now);
//		FOR(j,0,i){
//			cout<<T[0].get(j,j)<<' ';
//		}
//		cout<<"\n";
//		FOR(j,0,i){
//			cout<<T[1].get(j,j)<<' ';
//		}
//		cout<<"\n";
	}
	cout<<T[0].get(len,len);
	RE 0;
}