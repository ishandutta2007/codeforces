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
	while(ch<'0'||ch>'9'){if(ch=='?')return -1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,tot,cnt1;
int a[305],b[305],v[200005],nxt[200005],h[605],mch[605],x[305],bs[305][305],ans[305];
bool hv[305],vis[605],vs[305][305];
pair<pii,int> p[305];
pii k1[100005];

void addedge(int x,int y){
	v[++tot]=y; nxt[tot]=h[x]; h[x]=tot;
	v[++tot]=x; nxt[tot]=h[y]; h[y]=tot;
}

bool dfs(int u){
	for(int p=h[u];p;p=nxt[p]){
		if(vis[v[p]]) continue;
		vis[v[p]]=1;
		if(!mch[v[p]]||dfs(mch[v[p]])){
			mch[v[p]]=u;
			return true;
		}
	}
	return false;
}

int main(){
	n=readint();
	for(int i=1;i<=n;i++) a[i]=readint(),b[i]=readint();
	for(int i=1;i<=n;i++) if(!a[i]&&b[i]>=0) x[b[i]]++;
	int bcnt=0;
	for(int i=1;i<=n;i++) if(b[i]>=0) hv[b[i]]=1,bcnt++;
	if(!bcnt) hv[1]=1;
	for(int i=1;i<=n;i++){
		if(x[i]%i!=0){
			int tmp=i-x[i]%i;
			for(int j=1;j<=tmp;j++) k1[++cnt1]=mp(i,0);
		}
		else if(x[i]==0&&hv[i]) for(int j=1;j<=i;j++) k1[++cnt1]=mp(i,0);
	}
	int amax=0;
	for(int i=1;i<=n;i++) chkmax(amax,a[i]);
	for(int i=1;i<=n;i++) if(a[i]>0&&b[i]>=0) vs[b[i]][a[i]]=1;
	int nmax=-1,fr=0;
	for(int i=1;i<=n;i++){
		int now=0;
		for(int j=n-1;j>=1;j--){
			if(vs[i][j]){
				now=j;
				break;
			}
		}
		for(int j=1;j<=now;j++) if(!vs[i][j]) k1[++cnt1]=mp(i,j);
	}
	int tmpcnt=cnt1;
	for(int fr=1;fr<=n;fr++){
		if(!hv[fr]) continue;
		int now=0;
		for(int i=1;i<n;i++) if(vs[fr][i]) now=i;
		cnt1=tmpcnt;
		for(int i=now+1;i<amax;i++) k1[++cnt1]=mp(fr,i);
		if(cnt1>n) continue;
		memset(h,0,sizeof(h)); tot=0;
		memset(mch,0,sizeof(mch));
		for(int i=1;i<=cnt1;i++){
			for(int j=1;j<=n;j++){
				if(a[j]>=0&&b[j]>=0) continue;
				if((k1[i].fi==b[j]||b[j]==-1)&&(k1[i].se==a[j]||a[j]==-1)) addedge(i,j+cnt1);
			}
		}
		bool fl=1;
		for(int i=1;i<=cnt1;i++){
			memset(vis,0,sizeof(vis));
			vis[i]=1;
			if(!dfs(i)) fl=0;
		}
		if(!fl) continue;
		for(int i=1;i<=n;i++){
			if(a[i]>=0&&b[i]>=0) continue;
			if(mch[i+cnt1]) b[i]=k1[mch[i+cnt1]].fi,a[i]=k1[mch[i+cnt1]].se;
			else{
				if(a[i]<0&&b[i]<0) a[i]=1,b[i]=fr;
				else if(a[i]<0) a[i]=1;
				else if(b[i]<0){
					if(a[i]==0) b[i]=1;
					else b[i]=fr;
				}
			}
		}
		for(int i=1;i<=n;i++) p[i]=mp(mp(a[i],b[i]),i);
		sort(p+1,p+n+1);
		int lst=1;
		for(int i=1;i<=n;i++){
			if(!p[i].fi.fi){
				if(bs[p[i].fi.se][0]) ans[p[i].se]=bs[p[i].fi.se][0];
				bs[p[i].fi.se][0]=p[i].se;
				if(i-lst+1==p[i].fi.se) ans[p[lst].se]=p[i].se,lst=i+1;
			}
			else{
				ans[p[i].se]=bs[p[i].fi.se][p[i].fi.fi-1];
				bs[p[i].fi.se][p[i].fi.fi]=p[i].se;
			}
		}
		for(int i=1;i<=n;i++) printf("%d ",ans[i]);
		printf("\n");
		return 0;
	}
	printf("-1\n");
	return 0;
}