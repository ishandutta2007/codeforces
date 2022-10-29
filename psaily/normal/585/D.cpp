#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,n) for (int i=(a);i<(n);i++)
#define per(i,a,n) for (int i=(a)-1;i>=(n);i--)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define SZ(x) ((int)x.size())
#define all(x) x.begin(),x.end()

typedef long long ll;
typedef pair<ll,ll> PLL;
typedef vector<int> VI;
typedef double db;

#define N 30
int n,m;
int val[N][4];
PLL ans=mp(-2e9,0);

map<PLL,PLL> mmap;
// L M W
// 0 -> MW
// 1 -> LW
// 2 -> LM

ll pow3[N];
void prepare() {
	pow3[0]=1;
	rep(i,1,27) pow3[i]=pow3[i-1]*3;
}

void dfs1(int x,ll a,ll b,ll c,ll sta) {
	if (x==m) {
		ll tot=a+b+c;
		PLL tmp=mp(a-b,a-c);
		//printf("a=%lld b=%lld c=%lld sta=%lld\n",a,b,c,sta);
		if (mmap.find(tmp)!=mmap.end()) {
			PLL las=mmap[tmp];
			if (tot>las.fi) mmap[tmp]=mp(tot,sta);
		}else mmap[tmp]=mp(tot,sta);
		return;	
	}
	dfs1(x+1,a,b+val[x][1],c+val[x][2],sta+0*pow3[x]);
	dfs1(x+1,a+val[x][0],b,c+val[x][2],sta+1*pow3[x]);
	dfs1(x+1,a+val[x][0],b+val[x][1],c,sta+2*pow3[x]);
}
void dfs(int x,ll a,ll b,ll c,ll sta) {
	if (x==n) {
		PLL p=mp(b-a,c-a);
		if (mmap.find(p)!=mmap.end()) {
			PLL ret=mmap[p];
			if (ret.fi+a+b+c>ans.fi) ans=mp(ret.fi+a+b+c,ret.se+sta);
		}
		return;
	}
	dfs(x+1,a,b+val[x][1],c+val[x][2],sta+0*pow3[x]);
	dfs(x+1,a+val[x][0],b,c+val[x][2],sta+1*pow3[x]);
	dfs(x+1,a+val[x][0],b+val[x][1],c,sta+2*pow3[x]);
}

int main() {
	scanf("%d",&n);
	rep(i,0,n) rep(j,0,3) scanf("%d",&val[i][j]);
	prepare();
	m=(n+1)>>1;
	dfs1(0,0,0,0,0);
	if (m==n) {
		if (mmap.find(mp(0,0))!=mmap.end()) {
			ans.se=mmap[mp(0,0)].se;
			rep(i,0,n) {
				ll s=ans.se/pow3[i]%3;
				if (s==0) puts("MW");
				else if (s==1) puts("LW");
				else puts("LM");
			}
		}else puts("Impossible");
		return 0;
	}
	dfs(m,0,0,0,0);
	//cerr<<"ans="<<ans.fi<<endl;
	if (ans.se==0) puts("Impossible");
	else {
		rep(i,0,n) {
			ll s=ans.se/pow3[i]%3;
			if (s==0) puts("MW");
			else if (s==1) puts("LW");
			else puts("LM");
		}
	}
	return 0;
}