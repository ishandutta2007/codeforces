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

int n,m,cys;
ll pred[505],pref[505],C[505][505],d[505][505],f[505][505];

ll F(ll x){return x*(x+1)/2%cys;}
ll mod(ll x){return x>=cys?x-cys:x;}

int main(){
	n=readint(); m=readint(); cys=readint();
	for(int i=0;i<=n;i++) C[i][0]=1;
	for(int i=1;i<=n;i++) for(int j=1;j<=i;j++) C[i][j]=mod(C[i-1][j]+C[i-1][j-1]);
	pred[0]=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			pred[i]=(pred[i]+pred[j-1]*pred[i-j]%cys*C[i-1][j-1]%cys*(i+1))%cys;
			pref[i]=(pref[i]+pred[j-1]*pred[i-j]%cys*C[i-1][j-1]%cys*(F(i-j)+F(j-1)))%cys;
			pref[i]=(pref[i]+pref[j-1]*pred[i-j]%cys*C[i-1][j-1]%cys*(i+1))%cys;
			pref[i]=(pref[i]+pred[j-1]*pref[i-j]%cys*C[i-1][j-1]%cys*(i+1))%cys;
		}
	}
	d[0][0]=1;
	for(int i=0;i<=n;i++){
		for(int j=0;j<=i;j++){
			for(int k=0;k<=n-i+1;k++){
				d[i+k+1][j+k]=(d[i+k+1][j+k]+d[i][j]*pred[k]%cys*C[j+k][j])%cys;
				f[i+k+1][j+k]=(f[i+k+1][j+k]+d[i][j]*pref[k]%cys*C[j+k][j])%cys;
				f[i+k+1][j+k]=(f[i+k+1][j+k]+f[i][j]*pred[k]%cys*C[j+k][j])%cys;
			}
		}
	}
	printf("%lld\n",f[n+1][m]);
	return 0;
}