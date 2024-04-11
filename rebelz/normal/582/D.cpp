#include<bits/stdc++.h>

#define y1 dmytxdy
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
ll p,q,m,n;
ll a[5005],t[5005],res[5005];
int d[4005][4005][2][2];
char s[1005];

ll C(ll x){return x<0?0:(x*(x-1)/2)%cys;}

int get(){
	ll now=0; int fr=-1;
	for(int i=0;i<m;i++) res[i]=0;
	for(int i=m-1;i>=0;i--){
		now=now*10+t[i];
		if(now>=p) res[i]=now/p,fr=max(fr,i);
		now%=p;
	}
	m=fr+1;
	for(int i=0;i<m;i++) t[i]=res[i];
	return now;
}

int main(){
	p=readint(); q=readint();
	scanf("%s",s); m=strlen(s);
	reverse(s,s+m);
	for(int i=0;i<m;i++) t[i]=s[i]-'0';
	while(m) a[++n]=get();
	if(q>n) return printf("0\n"),0;
	d[0][0][0][1]=d[0][0][0][0]=1;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=n;j++){
			d[i][j][0][0]=(1ll*d[i-1][j][0][0]*C(p+1)+1ll*d[i-1][j][1][0]*C(p))%cys;
			if(j) d[i][j][1][0]=(1ll*d[i-1][j-1][0][0]*C(p)+1ll*d[i-1][j-1][1][0]*C(p+1))%cys;
			d[i][j][0][1]=(1ll*d[i-1][j][0][0]*C(a[i]+1)+1ll*d[i-1][j][0][1]*(a[i]+1)+1ll*d[i-1][j][1][0]*C(a[i])+1ll*d[i-1][j][1][1]*a[i])%cys;
			if(j) d[i][j][1][1]=(1ll*d[i-1][j-1][0][0]*(C(p)-C(p-a[i]))+1ll*d[i-1][j-1][0][1]*(p-a[i]-1)+1ll*d[i-1][j-1][1][0]*(C(p+1)-C(p-a[i]+1))+1ll*d[i-1][j-1][1][1]*(p-a[i]))%cys;
		}
	}
	ll ans=0;
	for(int i=q;i<=n;i++) ans=(ans+d[n][i][0][1])%cys;
	printf("%lld\n",(ans+cys)%cys);
	return 0;
}