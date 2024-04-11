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

ll readint(){
	ll x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,m;
pii a[305];
ll p[305],al[305],am[305],ar[305],lst[305],g[305][305],f[305][305],d[305][305],bf[305],mx[305];
vector<int> fr[305];

int main(){
	n=readint();
	for(int i=1;i<=n;i++) a[i].fi=readint(),a[i].se=readint();
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) p[++m]=a[i].fi-a[i].se,p[++m]=a[i].fi,p[++m]=a[i].fi+a[i].se;
	sort(p+1,p+m+1); m=unique(p+1,p+m+1)-p-1;
	for(int i=1;i<=n;i++){
		al[i]=lower_bound(p+1,p+m+1,a[i].fi-a[i].se)-p;
		am[i]=lower_bound(p+1,p+m+1,a[i].fi)-p;
		ar[i]=lower_bound(p+1,p+m+1,a[i].fi+a[i].se)-p;
		bf[am[i]]=i;
		fr[ar[i]].push_back(i);
		if(ar[i]>mx[i-1]) mx[i]=ar[i];
		else mx[i]=mx[i-1];
	}
	am[n+1]=m;
	for(int i=1;i<=n;i++) for(int j=am[i]+1;j<=am[i+1];j++) lst[j]=i;
	for(int i=1;i<=m;i++){
		g[i][i-1]=m+1;
		for(int j=i;j<=m;j++){
			if(bf[j]) g[i][j]=min(g[i][j-1],al[bf[j]]);
			else g[i][j]=g[i][j-1];
		}
	}
	for(int i=1;i<=m;i++){
		f[i][i-1]=i;
		for(int j=i;j<=m;j++){
			if(g[i][j]>=i) f[i][j]=i;
			else f[i][j]=f[g[i][j]][i-1];
		}
	}
	memset(d,-0x3f,sizeof(d));
	d[0][0]=0,p[0]=p[1],am[n+1]=m+1;
	for(int i=1;i<=n;i++){
		for(int j=am[i];j<=mx[i];j++){
			if(bf[j]&&bf[j]<=i){
				int pl=min(al[bf[j]],f[al[bf[j]]][min((ll)j,am[i+1])-1]),ls=lst[pl];
				if(ls) for(int k=0;k<=m;k++) d[i][j]=max(d[i][j],d[ls][k]-max(0ll,p[k]-p[pl]));
				else d[i][j]=0;
				d[i][j]+=p[j]-p[pl];
			}
			else if(fr[j].size()){
				for(auto x:fr[j]){
					if(x>i) continue;
					int pl=am[x],tmp=g[am[x]+1][min((ll)j,am[i+1])-1];
					if(tmp<=m&&tmp<=am[x]) chkmin(pl,(int)f[tmp][am[x]-1]);
					int ls=lst[pl];
					ll now=d[0][1];
					if(ls) for(int k=0;k<=m;k++) now=max(now,d[ls][k]-max(0ll,p[k]-p[pl]));
					else now=0;
					now+=p[j]-p[pl];
					chkmax(d[i][j],now);
				}
			}
		}
	}
	ll ans=0;
	for(int i=1;i<=m;i++) chkmax(ans,d[n][i]);
	printf("%lld\n",ans);
	return 0;
}