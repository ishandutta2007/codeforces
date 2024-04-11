// xtqqwq
#include<bits/stdc++.h>

#define fi first
#define se second
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

template<typename T> bool chkmax(T &x,T y){return x<y?x=y,1:0;}
template<typename T> bool chkmin(T &x,T y){return x>y?x=y,1:0;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,cys,tot,ncnt;
int v[4005],nxt[4005],h[2005];
ll d[2005][2005],ans[2005],sum[2005],C[2005][2005],A[2005],pre[2005],suf[2005];

ll mod(ll x){return x>=cys?x-cys:x;}

ll qpow(ll x,ll p){
	ll ret=1;
	for(;p;p>>=1,x=x*x%cys) if(p&1) ret=ret*x%cys;
	return ret;
}

void addedge(int x,int y){
	v[++tot]=y; nxt[tot]=h[x]; h[x]=tot;
	v[++tot]=x; nxt[tot]=h[y]; h[y]=tot;
}

void dfs(int u,int fa){
	int son=0;
	for(int p=h[u];p;p=nxt[p]){
		if(v[p]==fa) continue;
		dfs(v[p],u);
		son++;
	}
	if(!son){
		for(int i=1;i<n;i++) d[u][i]=i;
		return;
	}
	ll now=0,pl=0;
	for(int i=1;i<n;i++){
		ll all=0,mul=1;
		for(int p=h[u];p;p=nxt[p]){
			if(v[p]==fa) continue;
			mul=mul*d[v[p]][i]%cys;
			all=mod(all+d[v[p]][i]);
		}
//		cout<<"test "<<i<<' '<<mul<<' '<<all<<endl;
		ncnt=0;
		for(int p=h[u];p;p=nxt[p]){
			if(v[p]==fa) continue;
			A[++ncnt]=d[v[p]][i];
		}
		pre[0]=1;
		for(int i=1;i<=ncnt;i++) pre[i]=pre[i-1]*A[i]%cys;
		suf[ncnt+1]=1;
		for(int i=ncnt;i>=1;i--) suf[i]=suf[i+1]*A[i]%cys;
		pl=0;
		for(int p=h[u];p;p=nxt[p]){
			if(v[p]==fa) continue;
			pl++;
			sum[v[p]]=(sum[v[p]]+pre[pl-1]*suf[pl+1])%cys;
			d[u][i]=(d[u][i]+sum[v[p]]*d[v[p]][i])%cys;
		}
		now=mod(now+cys-(son-1)*mul%cys);
		d[u][i]=mod(d[u][i]+now);
	}
//	cout<<"dfs "<<u<<endl;
//	for(int i=1;i<n;i++) cout<<d[u][i]<<' ';
//	cout<<endl;
}

int main(){
	n=readint(); cys=readint();
	for(int i=1;i<n;i++) addedge(readint(),readint());
	dfs(1,-1);
	for(int i=1;i<n;i++) ans[i]=1;
	for(int p=h[1];p;p=nxt[p])
		for(int i=1;i<n;i++)
			ans[i]=ans[i]*d[v[p]][i]%cys;
	for(int i=0;i<=n;i++) C[i][0]=1;
	for(int i=1;i<=n;i++) for(int j=1;j<=i;j++) C[i][j]=mod(C[i-1][j]+C[i-1][j-1]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<i;j++)
			ans[i]=mod(ans[i]+cys-ans[j]*C[i][j]%cys);
	for(int i=1;i<n;i++) printf("%lld ",ans[i]);
	printf("\n");
	return 0;
}