#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int cys=998244353;
int n,m,tot=0;
int v[600005],nxt[600005],col[300005],h[300005],cnt[5];
ll ans,p[300005];

ll power(ll x,ll p){
	ll ret=1;
	for(;p;p>>=1,x=x*x%cys) if(p&1) ret=ret*x%cys;
	return ret;
}

void addedge(int x,int y){
	v[++tot]=y; nxt[tot]=h[x]; h[x]=tot;
	v[++tot]=x; nxt[tot]=h[y]; h[y]=tot;
}

bool dfs(int u,int c){
	cnt[c]++;
	for(int p=h[u];p;p=nxt[p]){
		if(c==col[v[p]]) return false;
		if(col[v[p]]>-1) continue;
		col[v[p]]=c^1;
		if(!dfs(v[p],c^1)) return false;
	}
	return true;
}

int main(){
	int t=readint();
	p[0]=1;
	for(int i=1;i<=300000;i++) p[i]=p[i-1]*2%cys;
	while(t--){
		n=readint(); m=readint();
		for(int i=1;i<=n;i++) h[i]=0; tot=0;
		int x,y;
		for(int i=1;i<=m;i++){
			x=readint(); y=readint();
			addedge(x,y);
		}
		for(int i=1;i<=n;i++) col[i]=-1;
		ans=1;
		bool flag=true;
		for(int i=1;i<=n;i++){
			cnt[0]=cnt[1]=0;
			if(col[i]==-1){
				col[i]=0;
				if(!dfs(i,0)) flag=false;
				else ans=ans*(p[cnt[0]]+p[cnt[1]])%cys;
			}
		}
		if(!flag) printf("0\n");
		else printf("%lld\n",ans);
	}
	return 0;
}