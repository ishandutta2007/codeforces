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

const int cys=998244353,N=400000;
int n,m,rt,ncnt;
mt19937 mrand(23984);
int ch[200005][2],sum[200005],siz[200005],val[200005];
ll fac[400005],inv[400005];

ll qpow(ll x,ll p){
	ll ret=1;
	for(;p;p>>=1,x=x*x%cys) if(p&1) ret=ret*x%cys;
	return ret;
}

void update(int u){
	siz[u]=1+siz[ch[u][0]]+siz[ch[u][1]];
	sum[u]=val[u]+sum[ch[u][0]]+sum[ch[u][1]];
}

void split(int u,int k,int &x,int &y){
	if(!u) return (void)(x=y=0);
	if(sum[ch[u][0]]+val[u]<=k) x=u,split(ch[u][1],k-sum[ch[u][0]]-val[u],ch[x][1],y);
	else y=u,split(ch[u][0],k,x,ch[y][0]);
	update(u);
}

int merge(int x,int y){
	if(!x||!y) return x+y;
	if(mrand()%(siz[x]+siz[y])<siz[x]){
		ch[x][1]=merge(ch[x][1],y); update(x);
		return x;
	}
	else{
		ch[y][0]=merge(x,ch[y][0]); update(y);
		return y;
	}
}

int main(){
	int T=readint();
	fac[0]=inv[0]=1;
	for(int i=1;i<=N;i++) fac[i]=fac[i-1]*i%cys;
	inv[N]=qpow(fac[N],cys-2);
	for(int i=N-1;i>=1;i--) inv[i]=inv[i+1]*(i+1)%cys;
	while(T--){
		n=readint(); m=readint();
		rt=ncnt=0;
		int x,y;
		for(int i=1;i<=m;i++){
			x=readint(); y=readint();
			if(y>sum[rt]){
				ncnt++;
				val[ncnt]=sum[ncnt]=y-sum[rt]+1,siz[ncnt]=1,ch[ncnt][0]=ch[ncnt][1]=0;
				rt=merge(rt,ncnt);
			}
			else{
				int a,b,c,to;
				split(rt,y-1,a,b);
				to=b;
				while(ch[to][0]) to=ch[to][0];
				split(b,val[to],b,c);
				if(sum[a]+val[b]==y) val[b]++,sum[b]++,rt=merge(a,merge(b,c));
				else{
					ncnt++;
					val[ncnt]=sum[ncnt]=y-sum[a]+1,siz[ncnt]=1,ch[ncnt][0]=ch[ncnt][1]=0;
					val[b]=sum[b]=sum[a]+val[b]-y;
					rt=merge(a,merge(merge(ncnt,b),c));
				}
			}
		}
		int num=n-1-siz[rt];
		printf("%lld\n",fac[n+num]*inv[n]%cys*inv[num]%cys);
	}
	return 0;
}