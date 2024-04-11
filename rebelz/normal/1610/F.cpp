// xtqqwq
#include<bits/stdc++.h>

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
	int x,y,z;
}e[300005];

int n,m,k,tot=1,cnt;
int v[600005],c[600005],nxt[600005],h[300005],du[300005],seq[600005],ans[600005],res[600005],fr[300005],ed[300005],lf[300005],rg[300005];
bool vis[300005],hv[300005];

void addedge(int x,int y,int z){
	v[++tot]=y; c[tot]=z; nxt[tot]=h[x]; h[x]=tot;
	v[++tot]=x; c[tot]=-z; nxt[tot]=h[y]; h[y]=tot;
}

void dfs(int u){
	hv[u]=1;
	for(int &p=h[u];p;p=nxt[p]){
		if(vis[p>>1]) continue;
		vis[p>>1]=1;
		int edge=p;
		dfs(v[p]);
		ans[++cnt]=c[edge];
	}
}

int main(){
	n=readint(); m=readint();
	for(int i=1;i<=m;i++) e[i].x=readint(),e[i].y=readint(),e[i].z=readint();
	for(int i=1;i<=m;i++) du[e[i].x]+=e[i].z,du[e[i].y]+=e[i].z;
	int sum=0;
	for(int i=1;i<=n;i++) sum+=du[i]&1;
	printf("%d\n",sum);
	for(int i=1;i<=n;i++) du[i]=0;
	for(int i=1;i<=m;i++){
		if(e[i].z==2){
			addedge(e[i].x,e[i].y,i);
			du[e[i].x]++,du[e[i].y]++;
		}
	}
	for(int i=1;i<=n;i++) if(du[i]&1) addedge(0,i,i+m);
	dfs(0);
	for(int i=1;i<=cnt;i++) seq[i]=ans[i];
	int lst=1;
	for(int i=2;i<=cnt;i++){
		if(abs(ans[i])>m){
			k++;
			lf[k]=lst+1,rg[k]=i-1;
			fr[k]=abs(ans[lst])-m;
			ed[k]=abs(ans[i])-m;
			lst=i+1;
//			cout<<"test "<<k<<' '<<fr[k]<<' '<<ed[k]<<endl;
			i++;
		}
	}
	for(int i=1;i<=n;i++){
		if(!hv[i]){
			cnt=0;
			dfs(i);
			for(int j=1;j<=cnt;j++) res[abs(ans[j])]=ans[j]>0?1:2;
		}
	}
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=n;i++) du[i]=h[i]=hv[i]=0; tot=1;
	for(int i=1;i<=m;i++){
		if(e[i].z==1){
			addedge(e[i].x,e[i].y,i);
			du[e[i].x]++,du[e[i].y]++;
		}
	}
	for(int i=1;i<=k;i++) addedge(fr[i],ed[i],i+m),du[fr[i]]++,du[ed[i]]++;
	for(int i=1;i<=n;i++) if(du[i]&1) addedge(0,i,i+m+k);
	cnt=0;
	dfs(0);
	lst=1;
	for(int i=2;i<=cnt;i++){
		if(abs(ans[i])>m+k){
			for(int j=lst+1;j<i;j++){
				if(abs(ans[j])>m){
					int id=abs(ans[j])-m;
					for(int l=lf[id];l<=rg[id];l++) res[abs(seq[l])]=(seq[l]>0)^(ans[j]>0)?1:2;
				}
				else res[abs(ans[j])]=ans[j]>0?1:2;
			}
			lst=i+1;
			i++;
		}
	}
	for(int u=1;u<=n;u++){
		if(!hv[u]){
			cnt=0;
			dfs(u);
			for(int i=1;i<=cnt;i++){
				if(abs(ans[i])>m){
					int id=abs(ans[i])-m;
					for(int l=lf[id];l<=rg[id];l++) res[abs(seq[l])]=(seq[l]>0)^(ans[i]>0)?1:2;
				}
				else res[abs(ans[i])]=ans[i]>0?1:2;
			}
		}
	}
	for(int i=1;i<=m;i++) printf("%d",res[i]);
	printf("\n");
	return 0;
}