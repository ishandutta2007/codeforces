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

const int cys=1000000007;
int n,k,m,N;
ll d[215][215],g[215][215],f[215],tmp[215];

int main(){
	n=readint(); k=readint(); m=readint();
	N=(k+1)*(1<<m);
	for(int i=0;i<N;i++){
		int t=i/(1<<m),mask=i%(1<<m);
		d[t*(1<<m)+((mask<<1)&((1<<m)-1))][i]++;
		int cnt=0;
		for(int j=0;j<m;j++) cnt+=(i>>j)&1;
		if(t<k) d[(t+1)*(1<<m)+((mask<<1)&((1<<m)-1)|1)][i]+=1+cnt;
	}
	f[0]+=1;
	for(;n;n>>=1){
		if(n&1){
			for(int i=0;i<N;i++)
				for(int j=0;j<N;j++)
					tmp[i]=(tmp[i]+d[i][j]*f[j])%cys;
			for(int i=0;i<N;i++) f[i]=tmp[i],tmp[i]=0;
		}
		for(int i=0;i<N;i++)
			for(int j=0;j<N;j++)
				for(int l=0;l<N;l++)
					g[i][l]=(g[i][l]+d[i][j]*d[j][l])%cys;
		for(int i=0;i<N;i++)
			for(int j=0;j<N;j++)
				d[i][j]=g[i][j],g[i][j]=0;
	}
	ll ans=0;
	for(int i=k*(1<<m);i<N;i++) ans=(ans+f[i])%cys;
	printf("%lld\n",ans);
	return 0;
}