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
const int mod=1e9+7,inf=1<<30;
// head
const int N=1e6+5;
int n,m,ret;
char str[N];
int a[4][N];
VI v[4];
int fa[N*2],sz[N*2],vis[N*2];
vector<PII> h[N];
int as[N],ans[N],id[4][N];

int find(int x) {return fa[x]==x?x:fa[x]=find(fa[x]);}
void unite(int x,int y) {
	x=find(x),y=find(y);
	if (x==y) return;
	if (vis[x]&&vis[y]) ret--;
	if (x>y) swap(x,y);
	fa[y]=x;
}

int main() {
	// freopen("data.in","r",stdin);
	// freopen("my.out","w",stdout);
	
	scanf("%d",&n);
	rep(i,0,4*n+1) fa[i]=i,sz[i]=1;
	rep(i,1,4) {
		scanf("%s",str+1);
		rep(j,1,n+1) a[i][j]=str[j]-'0',a[i][j]=1-a[i][j];
	}
	
	// puts("");
	// rep(i,1,4) {
	// 	rep(j,1,n+1) printf("%d",a[i][j]);
	// 	puts("");	
	// }
	
	int tim=0;
	rep(i,1,n+1) {
		rep(j,1,4) id[j][i]=++tim;
	}	

	rep(i,1,n+1) {
		if (a[1][i]==1) v[1].pb(i);
		if (a[2][i]==0) v[2].pb(i);
		if (a[3][i]==1) v[3].pb(i);
	}
	rep(j,1,4) v[j].pb(n+1);
	#define id(x,y) id[x][y]
	scanf("%d",&m);
	rep(i,1,m+1) {
		int l,r;
		scanf("%d%d",&l,&r);
		h[r].pb(mp(l,i));	
	}
	rep(i,1,n+1) { // [,i]
		rep(r,1,4) {
			if (!a[r][i]&&(!a[r][i-1]&&i>1)) unite(id(r,i),id(r,i-1));
		}
		// debug(ret);
		if (!a[2][i]) {
			if (!a[1][i]) unite(id(2,i),id(1,i));
			if (!a[3][i]) unite(id(2,i),id(3,i));
		}
		
		rep(r,1,4) if (!a[r][i]&&find(id(r,i))==id(r,i)) vis[id(r,i)]=1,ret++;
		ans[i]=ret;
		// printf("ans[%d]=%d\n",i,ans[i]);
		
		for (auto q:h[i]) {
			int l=q.fi,id=q.se,r=i;
			as[id]=ans[r]-ans[l];
			int cnt=0;
			rep(r,1,4) if (!a[r][l]) cnt++;
			if (!cnt) ;
			else if (cnt==2&&!a[1][l]&&!a[3][l]) {
				// a[l]=(0,1,0)
				int p1=*upper_bound(all(v[1]),l);
				int p2=*upper_bound(all(v[2]),l);
				int p3=*upper_bound(all(v[3]),l);
				// bug(v[p1]),bug(v[p2),debug(p3);
				if (p2<=r&&p2<min(p1,p3)) {
					as[id]++;
					if (ans[p2]<ans[l]) as[id]++;
				}else as[id]+=2;
				
				
			}else as[id]++;
		}
	}
	rep(i,1,m+1) printf("%d\n",as[i]);
	
	return 0;
}
/*
12
011100000010
101001101100
011001011101
1
1 7


*/