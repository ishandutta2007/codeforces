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

const int cys=998244353;
int n,k;
int lst[200005],nxt[200005],a[200005],b[200005],pos[200005];
bool vis[200005];

int main(){
	int T=readint();
	while(T--){
		n=readint(); k=readint();
		for(int i=1;i<=n;i++) vis[i]=0;
		for(int i=1;i<=n;i++) nxt[i]=i+1,lst[i]=i-1;
		for(int i=1;i<=n;i++) a[i]=readint(),pos[a[i]]=i;
		for(int i=1;i<=k;i++) b[i]=readint(),vis[pos[b[i]]]=1;
		ll ans=1;
		for(int i=1;i<=k;i++){
			int pl=pos[b[i]],cnt=0;
			if(lst[pl]&&!vis[lst[pl]]) cnt++;
			if(nxt[pl]!=n+1&&!vis[nxt[pl]]) cnt++;
			ans=ans*cnt%cys;
			int tl=lst[pl],tn=nxt[pl];
			nxt[tl]=tn,lst[tn]=tl;
		}
		printf("%lld\n",ans);
	}
	return 0;
}