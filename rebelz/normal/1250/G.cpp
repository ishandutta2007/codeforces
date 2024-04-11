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
int n,r;
ll a[505],d[505][1005],f[505][1005];

ll mod(ll x){return x>=cys?x-cys:x;}

int main(){
	n=readint(); r=readint();
	for(int i=1;i<=n;i++) a[i]=readint();
	sort(a+1,a+n+1);
	a[n+1]=a[n];
	d[0][0]=1;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=min(i,n-i);j++){
			for(int k=0;k<=r;k++){
				if(i&1){
					f[j][k]=0;
					if(k>=j*(a[i+1]-a[i])) f[j][k]=mod(f[j][k]+d[j][k-j*(a[i+1]-a[i])]*(j+1)%cys);
					if(j&&k>=j*(a[i+1]-a[i])) f[j][k]=mod(f[j][k]+d[j-1][k-j*(a[i+1]-a[i])]);
					if(k>=j*(a[i+1]-a[i])) f[j][k]=mod(f[j][k]+d[j+1][k-j*(a[i+1]-a[i])]*(j+1)%cys);
				}
				else{
					d[j][k]=0;
					if(k>=j*(a[i+1]-a[i])) d[j][k]=mod(d[j][k]+f[j][k-j*(a[i+1]-a[i])]*(j+1)%cys);
					if(j&&k>=j*(a[i+1]-a[i])) d[j][k]=mod(d[j][k]+f[j-1][k-j*(a[i+1]-a[i])]);
					if(k>=j*(a[i+1]-a[i])) d[j][k]=mod(d[j][k]+f[j+1][k-j*(a[i+1]-a[i])]*(j+1)%cys);
				}
			}
		}
	}
	ll ans=0;
	for(int i=0;i<=r;i++) ans=mod(ans+(n&1?f[0][i]:d[0][i]));
	printf("%d\n",ans);
	return 0;
}