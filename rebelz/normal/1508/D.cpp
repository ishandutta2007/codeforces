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

struct node{
	int x,y,id;
	node(int x=0,int y=0,int id=0):x(x),y(y),id(id){}
}p[2005];

int n,m;
int x[2005],y[2005],a[2005];
bool vis[2005];

ll operator*(pii x,pii y){return 1ll*x.fi*y.se-1ll*x.se*y.fi;}

int main(){
	n=readint();
	for(int i=1;i<=n;i++) x[i]=readint(),y[i]=readint(),a[i]=readint();
	int pl=0,mina=1<<30;
	for(int i=1;i<=n;i++) if(a[i]!=i&&chkmin(mina,x[i])) pl=i;
	if(!pl){
		printf("0\n");
		return 0;
	}
	for(int i=1;i<=n;i++) if(i!=pl&&a[i]!=i) p[++m]=node(x[i],y[i],i);
	for(int i=1;i<=m;i++) for(int j=i+1;j<=m;j++) if(mp(p[i].x-x[pl],p[i].y-y[pl])*mp(p[j].x-x[pl],p[j].y-y[pl])<0) swap(p[i],p[j]);
	vector<pii> ans(0);
	for(int i=1;i<m;i++){
		for(int j=p[i].id,k=1;k<=n;j=a[j],k++) vis[j]=1;
		bool fl=vis[p[i+1].id];
		for(int j=p[i].id,k=1;k<=n;j=a[j],k++) vis[j]=0;
		if(!fl) ans.pb(mp(p[i].id,p[i+1].id)),swap(a[p[i].id],a[p[i+1].id]);
	}
	for(int j=a[pl];j!=pl;j=a[j]) ans.pb(mp(pl,j));
	printf("%d\n",ans.size());
	for(auto r:ans) printf("%d %d\n",r.fi,r.se);
	return 0;
}