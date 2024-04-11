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

int n,tot,ans=1<<30;
int v[400005],nxt[400005],h[200005],mxd[200005],can[200005];

void addedge(int x,int y){
	v[++tot]=y; nxt[tot]=h[x]; h[x]=tot;
	v[++tot]=x; nxt[tot]=h[y]; h[y]=tot;
}

void dfs1(int u,int fa){
	can[u]=1;
	int now=0;
	for(int p=h[u];p;p=nxt[p]){
		if(v[p]==fa) continue;
		dfs1(v[p],u);
		if(!can[v[p]]) can[u]=0;
		if(!now) now=mxd[v[p]];
		else if(now!=mxd[v[p]]) can[u]=0,chkmax(now,mxd[v[p]]);
	}
	mxd[u]=now+1;
}

void dfs2(int u,int fa){
	int now1=0,now2=0,nc=1,td=1;
	vector<int> v1(0),v2(0),ct(0);
	for(int p=h[u];p;p=nxt[p]){
		if(!can[v[p]]) nc=0,ct.push_back(v[p]);
		if(!now1) now1=mxd[v[p]];
		else if(now1!=mxd[v[p]]){
			if(!now2) now2=mxd[v[p]];
			else if(now2!=mxd[v[p]]){
				nc=0,td=0;
				break;
			}
		}
	}
	if(nc){
		int res=now1+now2;
		while(res%2==0) res/=2;
		chkmin(ans,res);
	}
	if(!td||ct.size()>1) return;
	for(int p=h[u];p;p=nxt[p]){
		if(mxd[v[p]]==now1) v1.push_back(v[p]);
		else if(mxd[v[p]]==now2) v2.push_back(v[p]);
	}
	for(int p=h[u];p;p=nxt[p]){
		if(v[p]==fa) continue;
		if(mxd[v[p]]==now2) swap(now1,now2),swap(v1,v2);
		if(mxd[v[p]]==now1){
			if(v1.size()==1){
				if(ct.size()>0&&(ct.size()!=1||ct[0]!=v[p])) continue;
				int tmp1=mxd[u],tmp2=can[u];
				mxd[u]=now2+1,can[u]=1;
				dfs2(v[p],u);
				mxd[u]=tmp1,can[u]=tmp2;
			}
			else if(v2.size()==0){
				if(ct.size()>0&&(ct.size()!=1||ct[0]!=v[p])) continue;
				int tmp1=mxd[u],tmp2=can[u];
				mxd[u]=now1+1,can[u]=1;
				dfs2(v[p],u);
				mxd[u]=tmp1,can[u]=tmp2;
			}
		}
	}
}

int main(){
	n=readint();
	for(int i=1;i<n;i++) addedge(readint(),readint());
	dfs1(1,-1);
	dfs2(1,-1);
	if(ans==(1<<30)) printf("-1\n");
	else printf("%d\n",ans);
	return 0;
}