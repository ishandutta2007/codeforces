#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=(a);i<(n);i++)
#define per(i,a,n) for (int i=(a)-1;i>=(n);i--)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#define SZ(x) (int)x.size()
#define make_unique(x) {sort(all(x)); x.resize(unique(all(x))-x.begin());} 
#define bug(x) cerr<<#x<<'='<<x<<' '
#define debug(x) cerr<<#x<<'='<<x<<endl 
mt19937 mrand(time(0)); 

typedef long long ll;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef double db;
const int mod=1e9+7;
const ll inf=1ll<<60;
// head
typedef pair<ll,int> PLI;
const int N=2e5+5;
int n,s,t,a[N];
int dis[N];

struct segment {
	#define lson p<<1,l,mid
	#define rson p<<1|1,mid+1,r
	#define lp p<<1
	#define rp p<<1|1
	PLI key[N<<2];
	
	PLI merge(PLI a,PLI b) {return a>b?a:b;}
	void update(int p,int l,int r,int x,ll a) {
		if (l==r) { key[p]=mp(a,l); return; }
		int mid=(l+r)>>1;
		if (x<=mid) update(lson,x,a);
		else update(rson,x,a);
		key[p]=merge(key[lp],key[rp]);
	}
	PLI query(int p,int l,int r,int ql,int qr) {
		if (ql>qr) return {-inf,0};
		if (ql==l&&qr==r) return key[p];
		int mid=(l+r)>>1;
		if (qr<=mid) return query(lson,ql,qr);
		else if (ql>mid) return query(rson,ql,qr);
		else return merge(query(lson,ql,mid),query(rson,mid+1,qr));
	}
}G[2];

void solve() {
	#define root 1,1,n
	scanf("%d%d%d",&n,&s,&t);
	rep(i,1,n+1) scanf("%d",&a[i]);
	rep(i,1,n+1) {
		G[0].update(1,1,n,i,(ll)a[i]+i);
		G[1].update(1,1,n,i,(ll)a[i]-i);
	}
	G[0].update(root,s,-inf);
	G[1].update(root,s,-inf);
	
	queue<int> q;
	q.push(s); dis[s]=0;
	while (!q.empty()) {
		int x=q.front(); q.pop();
		int l=max(1,x-a[x]),r=min(n,x+a[x]);
		
		// bug(x),debug(dis[x]);
		
		PLI cur;
		cur=G[0].query(root,l,x-1);
		// puts("IN");
		while (cur.fi>=x) {
			int y=cur.se;
			dis[y]=dis[x]+1;
			q.push(y);
			// debug(y);
			
			G[0].update(root,y,-inf);
			G[1].update(root,y,-inf);
			cur=G[0].query(root,l,x-1);
		}
		// puts("OUT");
		cur=G[1].query(root,x+1,r);
		while (cur.fi>=-x) {
			int y=cur.se;
			dis[y]=dis[x]+1;
			q.push(y);
			
			G[0].update(root,y,-inf);
			G[1].update(root,y,-inf);
			cur=G[1].query(root,x+1,r);
		}
	}
	printf("%d\n",dis[t]);
}

int main() {
	int _;
	for (scanf("%d",&_);_;_--) {
		solve();
	}
	return 0;
}