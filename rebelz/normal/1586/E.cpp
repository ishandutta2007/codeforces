#include<bits/stdc++.h>

#define y1 dmytxdy
#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef long double ld;

template <typename T> bool chkmin(T &x,T y){return x>y?x=y,1:0;}
template <typename T> bool chkmax(T &x,T y){return x<y?x=y,1:0;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,m,q,tot;
int dep[300005],qx[300005],qy[300005],num[300005],f[300005],v[600005],nxt[600005],h[300005];
bool vis[300005];

void addedge(int x,int y){
	v[++tot]=y; nxt[tot]=h[x]; h[x]=tot;
	v[++tot]=x; nxt[tot]=h[y]; h[y]=tot;
}

void dfs(int u){
	for(int p=h[u];p;p=nxt[p]){
		if(vis[v[p]]) continue;
		f[v[p]]=u,dep[v[p]]=dep[u]+1;
		vis[v[p]]=u;
		dfs(v[p]);
	}
}

int main(){
	n=readint(); m=readint();
	for(int i=1;i<=m;i++) addedge(readint(),readint());
	vis[1]=1,dep[1]=1; dfs(1);
	q=readint();
	for(int i=1;i<=q;i++) qx[i]=readint(),qy[i]=readint(),num[qx[i]]++,num[qy[i]]++;
	int cnt=0;
	for(int i=1;i<=n;i++) if(num[i]&1) cnt++;
	if(cnt>0){
		printf("NO\n");
		printf("%d\n",cnt/2);
		return 0;
	}
	printf("YES\n");
	for(int i=1;i<=q;i++){
		vector<int> t1(0),t2(0);
		int tx=qx[i],ty=qy[i],fl=0;
		while(tx!=ty){
			if(dep[tx]<dep[ty]) swap(tx,ty),swap(t1,t2),fl^=1;
			t1.pb(tx);
			tx=f[tx];
		}
		if(fl) swap(t1,t2);
		printf("%d\n",t1.size()+t2.size()+1);
		for(auto r:t1) printf("%d ",r);
		printf("%d ",tx);
		reverse(t2.begin(),t2.end());
		for(auto r:t2) printf("%d ",r);
		printf("\n");
	}
	return 0;
}