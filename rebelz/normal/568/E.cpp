#include<bits/stdc++.h>

#define y1 dmytxdy
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

int n,m,cnt;
int a[100005],p[200005],b[100005],lst[100005],ans[100005];
pii d[100005];
bool vis[100005];

int main(){
	n=readint();
	for(int i=1;i<=n;i++) a[i]=readint();
	for(int i=1;i<=n;i++) if(a[i]>0) p[++cnt]=a[i];
	m=readint();
	for(int i=1;i<=m;i++) b[i]=readint(),p[++cnt]=b[i];
	sort(b+1,b+m+1);
	sort(p+1,p+cnt+1); cnt=unique(p+1,p+cnt+1)-p-1;
	p[cnt+1]=1e9+5,a[n+1]=cnt+1;
	for(int i=1;i<=m;i++) b[i]=lower_bound(p+1,p+cnt+1,b[i])-p;
	for(int i=1;i<=n;i++) if(a[i]>0) a[i]=lower_bound(p+1,p+cnt+1,a[i])-p;
	for(int i=1;i<=n;i++) d[i]=mp(1e9+5,0);
	for(int i=1;i<=n;i++){
		if(a[i]>0){
			int tmp=lower_bound(d,d+n+1,mp(a[i],0))-d-1;
			lst[i]=d[tmp].se;
			chkmin(d[tmp+1],mp(a[i],i));
		}
		else{
			int now=m;
			for(int j=n-1;j>=0;j--){
				while(now&&b[now-1]>d[j].fi) now--;
				if(now&&b[now]>d[j].fi) chkmin(d[j+1],mp(b[now],d[j].se));
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(a[i]>0) ans[i]=p[a[i]];
		else ans[i]=-1;
	}
	int st=0,ut=n+1; pii opt;
	for(int i=1;i<=n;i++) if(d[i].fi<=1e9) opt=d[i];
	st=opt.se;
	while(ut){
		int bpl=upper_bound(b+1,b+m+1,a[st])-b;
		for(int i=st+1;i<=ut-1;i++){
			if(a[i]<0){
				if(bpl<=m&&b[bpl]<a[ut]) ans[i]=p[b[bpl]],vis[bpl]=1;
				while(bpl<=m&&b[bpl]<a[ut]&&ans[i]==p[b[bpl]]) bpl++;
			}
		}
		if(!st) break;
		ut=st,st=lst[st];
	}
	int tpl=1;
	for(int i=1;i<=n;i++){
		if(ans[i]<0){
			while(tpl<=m&&vis[tpl]) tpl++;
			ans[i]=p[b[tpl]];
			tpl++;
		}
	}
	for(int i=1;i<=n;i++) printf("%d ",ans[i]);
	printf("\n");
	return 0;
}