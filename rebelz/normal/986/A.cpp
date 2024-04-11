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

int n,m,k,s,tot;
int a[100005],dis[100005][105],q[100005],v[200005],nxt[200005],h[100005];
vector<int> vec[105];

void addedge(int x,int y){
	v[++tot]=y; nxt[tot]=h[x]; h[x]=tot;
	v[++tot]=x; nxt[tot]=h[y]; h[y]=tot;
}

int main(){
	n=readint(); m=readint(); k=readint(); s=readint();
	for(int i=1;i<=n;i++) a[i]=readint(),vec[a[i]].pb(i);
	for(int i=1;i<=m;i++) addedge(readint(),readint());
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++) dis[j][i]=1<<30;
		int front=0,rear=0;
		for(auto r:vec[i]) dis[r][i]=0,q[rear++]=r;
		while(front<rear){
			int t=q[front++];
			for(int p=h[t];p;p=nxt[p])
				if(chkmin(dis[v[p]][i],dis[t][i]+1))
					q[rear++]=v[p];
		}
	}
	for(int i=1;i<=n;i++){
		sort(dis[i]+1,dis[i]+k+1);
		ll ans=0;
		for(int j=1;j<=s;j++) ans+=dis[i][j];
		printf("%lld ",ans);
	}
	printf("\n");
	return 0;
}