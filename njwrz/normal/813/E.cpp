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
int ch[10000000][2],val[10000000],cnt,a[100005],root[100005]; 
V<int> v[100005];
void build(int &x,int l,int r){
	x=++cnt;
	if(l==r)RE ;
	int mid=(l+r)>>1;
	build(ch[x][0],l,mid);
	build(ch[x][1],mid+1,r);
}
void update(int lst,int &now,int l,int r,int it,int tap){
	now=++cnt;val[now]=val[lst];
	FOR(i,0,1)ch[now][i]=ch[lst][i];
	if(l==r){
		val[now]+=tap;RE;
	}
	int mid=(l+r)>>1;
	if(it<=mid)update(ch[lst][0],ch[now][0],l,mid,it,tap);
	else update(ch[lst][1],ch[now][1],mid+1,r,it,tap);
	val[now]=val[ch[now][0]]+val[ch[now][1]];
}
int get(int x,int l,int r,int tl,int tr){
	if(l>tr||tl>r)RE 0;
	if(l>=tl&&r<=tr){
		RE val[x];
	}
	int mid=(l+r)>>1;
	RE get(ch[x][0],l,mid,tl,tr)+get(ch[x][1],mid+1,r,tl,tr);
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,k;
	cin>>n>>k;k++;
	int lst=0;
	FOR(i,1,n)cin>>a[i];
	build(root[0],1,n);
	FOR(i,1,n){
		v[a[i]].PB(i);
		update(root[i-1],root[i],1,n,i,1);
		if(v[a[i]].size()>=k){
			update(root[i],root[i],1,n,v[a[i]][v[a[i]].size()-k],-1);
		}
	}
	int x,y,q;cin>>q;
	FOR(i,1,q){
		cin>>x>>y;
		x=(x+lst)%n+1;
		y=(y+lst)%n+1;
		if(x>y)swap(x,y);
		lst=get(root[y],1,n,x,y);
		cout<<lst<<'\n';
	}
	RE 0;
}