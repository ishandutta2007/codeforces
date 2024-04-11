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

int n,cys;
ll d[4000005],g[4000005],s[4000005];

ll mod(ll x){return x>=cys?x-cys:x;}

int main(){
	n=readint(); cys=readint();
	d[1]=1;
	for(int i=1;i<=n;i++){
		d[i]=mod(d[i]+s[i-1]);
		g[i]=mod(g[i]+g[i-1]);
		d[i]=mod(d[i]+g[i]);
		s[i]=mod(s[i-1]+d[i]);
		for(int j=2;j<=n/i;j++){
			g[j*i]=mod(g[j*i]+d[i]);
			if(j*(i+1)<=n) g[j*(i+1)]=mod(g[j*(i+1)]+cys-d[i]);
		}
	}
	printf("%lld\n",d[n]);
	return 0;
}