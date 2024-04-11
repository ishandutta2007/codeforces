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
bool f[600005],flip[200005];
int blk[600005],wit[600005];
void build(int s,int l,int r){
	if(l==r){
		if(flip[l])blk[s]=1;else wit[s]=1;
		RE;
	}
	int mid=(l+r)>>1;
	build(s<<1,l,mid);
	build((s<<1)+1,mid+1,r);
	blk[s]=blk[s<<1]+blk[(s<<1)+1];
	wit[s]=wit[s<<1]+wit[(s<<1)+1];
}
void push(int s){
	if(f[s]){
		swap(blk[s<<1],wit[s<<1]);
		swap(blk[(s<<1)+1],wit[(s<<1)+1]);
		f[s<<1]^=1;
		f[(s<<1)+1]^=1;
		f[s]=0;
	}
}
void up(int s,int tl,int tr,int l,int r){
	if(r<tl||tr<l)RE;
	if(tl>=l&&tr<=r){
		f[s]^=1;
		swap(blk[s],wit[s]);
		RE;
	}
	push(s);
	int mid=(tl+tr)>>1;
	up(s<<1,tl,mid,l,r);
	up((s<<1)+1,mid+1,tr,l,r);
	blk[s]=blk[s<<1]+blk[(s<<1)+1];
	wit[s]=wit[s<<1]+wit[(s<<1)+1];
}
int get(int s,int tl,int tr,int l,int r){
	if(r<tl||tr<l)RE 0;
	if(tl>=l&&tr<=r){
		RE blk[s];
	}
	push(s);
	int mid=(tl+tr)>>1;
	RE get(s<<1,tl,mid,l,r)+get((s<<1)+1,mid+1,tr,l,r);
}
P<int,int> p[200005];
V<int> v[200005];
int n,cnt; 
void dfs(int u,int fa){
	p[u].F=++cnt;
	for(auto nxt:v[u])if(nxt!=fa)dfs(nxt,u);
	p[u].S=cnt;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	int x;
	FOR(i,2,n){
		cin>>x;
		v[x].PB(i);
		v[i].PB(x);
	}
	dfs(1,0);
	FOR(i,1,n){
		cin>>x;
		flip[p[i].F]=x;
	}
	build(1,1,n);
	string s;int m;
	cin>>m;
	FOR(i,1,m){
		cin>>s>>x;
		if(s=="pow"){
			up(1,1,n,p[x].F,p[x].S);
		}else{
			cout<<get(1,1,n,p[x].F,p[x].S)<<'\n';
		}
	}
	RE 0;
}