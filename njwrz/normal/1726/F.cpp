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
#define PF push_front
#define FILL(a,b) memset(a,b,sizeof(a))
#define lwb lower_bound
#define upb upper_bound
#define lc (x<<1)
#define rc ((x<<1)|1)
using namespace std;
ll n,t;
ll d[200005];
ll to[200005];
ll g[200005],c[200005],r[200005],st[200005];
int p[10000005];
int ch[10000005][2];
int root,cnt;
void update(int &x,int l,int r,int tl,int tr,int val){
	if(l>tr||tl>r)RE;
	if(!x)x=++cnt;
	if(l>=tl&&r<=tr){
		p[x]=val;RE;
	}
	int mid=(l+r)>>1;
	update(ch[x][0],l,mid,tl,tr,val);
	update(ch[x][1],mid+1,r,tl,tr,val);
}
int get(int x,int l,int r,int it){
	if(!x)RE 0;
	if(l==r)RE p[x];
	int now=p[x];
	int mid=(l+r)>>1;
	int to=0;
	if(mid>=it)to=get(ch[x][0],l,mid,it);
	else to=get(ch[x][1],mid+1,r,it);
	if(!to||!now)now+=to;else gmin(now,to);
	RE now;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>t;
	FOR(i,1,n)cin>>g[i]>>c[i];
	FOR(i,2,n)cin>>d[i],d[i]+=d[i-1];
	FOR(i,1,n){
		c[i]=(c[i]+d[i])%t;
		r[i]=(g[i]-c[i]%t+t)%t;st[i]=(r[i]+t-g[i])%t;
		c[i]=(r[i]+t-g[i])%t;
//		cout<<r[i]<<' '<<c[i]<<'\n';
	}
	to[n]=0;
	for(int i=n;i>=1;i--){
		ll j=get(1,0,t-1,st[i]);
		if(j){
			if(r[j]<=c[j]){
				if(r[j]<=st[i]&&st[i]<=c[j]){
					to[i]=to[j]+c[j]-st[i];
				}
			}else{
				if(st[i]<=c[j]||r[j]<=st[i]){
					to[i]=to[j]+(c[j]-st[i]+t)%t;
				}
			}
		}
//		cout<<j<<' ';
		j=i;
		if(r[j]<=c[j]){
			update(root,0,t-1,r[j],c[j],i);
		}else {
			update(root,0,t-1,0,c[j],i);
			update(root,0,t-1,r[j],t-1,i);
		}
	}
	ll out=1e18;
	FOR(i,1,n){
		int now=(r[i]-1+t)%t;
		ll ans=0;
		int j=get(root,0,t-1,now);
		if(j){
			if(r[j]<=c[j]){
				if(r[j]<=now&&now<=c[j]){
					ans=to[j]+c[j]-now;
				}
			}else{
				if(now<=c[j]||r[j]<=now){
					ans=to[j]+(c[j]-now+t)%t;
				}
			}
		}
		gmin(out,ans);
	}
	cout<<out+d[n];
	RE 0;
}