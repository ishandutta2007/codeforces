//#pragma comment(linker, "/STACK:102400000,102400000")
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector> 
#include <map>
#include <utility>
using namespace std;

#define rep(i,a,n) for (int i=(a);i<(n);i++)
#define per(i,a,n) for (int i=(a)-1;i>=(n);i--)
#define pb push_back
// #define mp make_pair
#define all(x) x.begin(),x.end()
#define SZ(x) (int)x.size()
#define fi first
#define se second
#define bug(x) cerr<<#x<<'='<<x<<' '
#define debug(x) cerr<<#x<<'='<<x<<endl
#define inf 0x3f3f3f3f
                  
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,int> pli;
typedef vector<int> vi;

const int N=2e5+5;
const int mod=1e9+7;
int n,m,bcnt;
char str[N];
vector<int> e[N];
int val[N],ans[N],deg[N];
vector<pii> que[N];

struct hsh {
	static const int mod1=1e9+7,mod2=1e9+9;
	ll a,b;
	hsh(ll a=0,ll b=0):a(a),b(b) {}
	hsh operator + (const hsh&_)const {return hsh((a+_.a)%mod1,(b+_.b)%mod2);}
	hsh operator - (const hsh&_)const {return hsh((a-_.a+mod1)%mod1,(b-_.b+mod2)%mod2);}
	hsh operator * (const hsh&_)const {return hsh(a*_.a%mod1,b*_.b%mod2);}
	bool operator < (const hsh&_)const {return a<_.a||(a==_.a&&b<_.b);}
	bool operator == (const hsh&_)const {return a==_.a&&b==_.b;}
	void print() {bug(a),debug(b);}
}b[N],a[N];

int son[N],siz[N],dep[N];
void get_son(int u) {
	siz[u]=1,son[u]=0;
	rep(i,0,SZ(e[u])) {
		int v=e[u][i];
		dep[v]=dep[u]+1;
		get_son(v);
		siz[u]+=siz[v];
		if (siz[v]>siz[son[u]]) son[u]=v;
	}
}

map<int,int> cnt[N];
int ct[N];
void add(int x) {
	if (!cnt[dep[x]][val[x]]) ct[dep[x]]++;
	cnt[dep[x]][val[x]]++;
}
void del(int x) {
	cnt[dep[x]][val[x]]--;
	if (!cnt[dep[x]][val[x]]) ct[dep[x]]--;
}
void ope(int x,int op) {
	if (op==1) add(x);
	else del(x);
	rep(i,0,SZ(e[x])) {
		int v=e[x][i];
		ope(v,op);
	}
}
void DSU(int x) {
	rep(i,0,SZ(e[x])) {
		int y=e[x][i];
		if (y==son[x]) continue;
		DSU(y);
		ope(y,-1);
	}
	if (son[x]) DSU(son[x]);
	add(x);
	rep(i,0,SZ(e[x])) {
		int y=e[x][i];
		if (y==son[x]) continue;
		ope(y,1);
	}
	rep(i,0,SZ(que[x])) {
		pii e=que[x][i];
		ans[e.se]=ct[e.fi+dep[x]];
	}
}

int main() {
	hsh P=hsh(13,17);
	scanf("%d",&n);
	rep(i,1,n+1) {
		int fa;
		scanf("%s%d",str,&fa);
		if (fa) {
			e[fa].pb(i);
			deg[i]++;
		}
		int len=strlen(str);
		hsh res=hsh(1,1);
		rep(i,0,len) res=res*P+hsh(str[i]-'a',str[i]-'a');
		a[i]=b[++bcnt]=res;
	}
	sort(b+1,b+1+bcnt);
	bcnt=unique(b+1,b+1+bcnt)-b-1;
	rep(i,1,n+1) val[i]=lower_bound(b+1,b+1+bcnt,a[i])-b;
	
	scanf("%d",&m);
	rep(i,1,m+1) {
		int v,w;
		scanf("%d%d",&v,&w);
		que[v].pb(make_pair(w,i));
	}
	
	rep(i,1,n+1) if (!deg[i]) get_son(i);
	rep(i,1,n+1) if (!deg[i]) {DSU(i); ope(i,-1);}
	rep(i,1,m+1) printf("%d\n",ans[i]);
	return 0;	
}