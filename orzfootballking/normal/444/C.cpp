#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
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
int c[300005],t[300005],add[300005],same[300005];
void build(int s,int l,int r){
	if(l==r){
		same[s]=1;
		c[s]=l;
		RE;
	}
	int mid=(l+r)>>1;
	build(s<<1,l,mid);
	build((s<<1)+1,mid+1,r);
}
void push(int s,int l,int r){
	if(add[s]){
		t[s]=t[s]+(r-l+1)*add[s];
		if(l!=r){
			add[s<<1]=add[s<<1]+add[s];
			add[(s<<1)+1]=add[(s<<1)+1]+add[s];
		}
		add[s]=0;
	}
	if(same[s]&&l!=r){
		same[s<<1]=1;
		same[(s<<1)+1]=1;
		c[s<<1]=c[s];
		c[(s<<1)+1]=c[s];
	}
}
void up(int s,int tl,int tr,int l,int r,int x){
	push(s,tl,tr);
	if(r<tl||tr<l)RE;
	if(tl>=l&&tr<=r){
		if(same[s]){
			add[s]=add[s]+abs(x-c[s]);
			c[s]=x;
			push(s,tl,tr);
			RE;
		}else{
			same[s]=1;
			c[s]=x;
		}
	}else{
		if(same[s]&&c[s]!=x){
			same[s]=0;
			c[s]=0;
		}
	}
	int mid=(tl+tr)>>1;
	up(s<<1,tl,mid,l,r,x);
	up((s<<1)+1,mid+1,tr,l,r,x);
	t[s]=t[s<<1]+t[(s<<1)+1];
}
int get(int s,int tl,int tr,int l,int r){
	push(s,tl,tr);
	if(r<tl||tr<l)RE 0;
	if(tl>=l&&tr<=r)RE t[s];
	int mid=(tl+tr)>>1;
	RE get(s<<1,tl,mid,l,r)+get((s<<1)+1,mid+1,tr,l,r);
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	int type,l,r,x;
	build(1,1,n);
	FOR(i,1,m){
		cin>>type;
		if(type==1){
			cin>>l>>r>>x;
			up(1,1,n,l,r,x);
		}else{
			cin>>l>>r;
			cout<<get(1,1,n,l,r)<<'\n';
		}
	}
	RE 0;
}