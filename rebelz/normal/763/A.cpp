#include<bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

template <typename T> bool chkmax(T &x,T y){return x<y?x=y,true:false;}
template <typename T> bool chkmin(T &x,T y){return x>y?x=y,true:false;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,tot;
int v[200005],nxt[200005],h[100005],d[100005],a[100005];

void addedge(int x,int y){
	v[++tot]=y; nxt[tot]=h[x]; h[x]=tot;
	v[++tot]=x; nxt[tot]=h[y]; h[y]=tot;
}

void dfs1(int u,int fa){
	d[u]=1;
	int now=a[u];
	for(int p=h[u];p;p=nxt[p]){
		if(v[p]==fa) continue;
		dfs1(v[p],u);
		if(!d[v[p]]) d[u]=0;
		if(now!=a[v[p]]) d[u]=0;
	}
}

void dfs2(int u,int fa){
	vector<int> vt(0);
	int now1=0,now2=0,cnt1=0,cnt2=0,fl=1;
	for(int p=h[u];p;p=nxt[p]) if(!d[v[p]]) vt.push_back(v[p]);
	for(int p=h[u];p;p=nxt[p]){
		if(!now1) now1=a[v[p]];
		else if(now1!=a[v[p]]){
			if(!now2) now2=a[v[p]];
			else if(now2!=a[v[p]]) fl=0;
		}
	}
	if(!vt.size()){
		printf("YES\n%d\n",u);
		exit(0);
	}
	if(!fl) return;
	if(a[u]!=now1){
		if(!now2) now2=a[u];
		else if(now2!=a[u]) return;
	}
	int tc=0;
	if(a[u]==now1) tc=1;
	if(a[u]==now2) tc=2;
	for(int p=h[u];p;p=nxt[p]){
		if(a[v[p]]==now1) cnt1++;
		else if(a[v[p]]==now2) cnt2++;
	}
	if(a[u]==now1) cnt1++;
	else if(a[u]==now2) cnt2++;
	if(vt.size()>1) return;
	if(!tc) return;
	if(tc==2) swap(now1,now2),swap(cnt1,cnt2);
	for(int p=h[u];p;p=nxt[p]){
		if(v[p]==fa) continue;
		if(vt[0]==v[p]&&(cnt2==0||(cnt2==1&&a[v[p]]==now2))){
			int tmp=d[u];
			d[u]=1;
			dfs2(v[p],u);
			d[u]=tmp;
		}
	}
}

int main(){
	n=readint();
	for(int i=1;i<n;i++) addedge(readint(),readint());
	for(int i=1;i<=n;i++) a[i]=readint();
	dfs1(1,-1);
	dfs2(1,-1);
	printf("NO\n");
	return 0;
}