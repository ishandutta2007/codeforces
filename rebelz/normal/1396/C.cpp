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

ll n,r1,r2,r3,d;
ll a[1000005],b[1000005],f[1000005][2];

int main(){
	n=readint(); r1=readint(); r2=readint(); r3=readint(); d=readint();
	for(int i=1;i<=n;i++) a[i]=readint(),b[i]=min(r2,(a[i]+1)*r1);
	for(int i=1;i<=n;i++) b[i]+=b[i-1];
	f[1][1]=min(r1,r3)*a[1]+r3;
	f[1][0]=min(r2,(a[1]+1)*r1);
	for(int i=2;i<=n;i++){
		f[i][1]=f[i-1][0]+d+min(r2,(a[i]+1)*r1)+d+min(min(r1,r2),r3)+d+min(min(r1,r2),r3);
		chkmin(f[i][1],f[i-1][0]+d+min(r1,r3)*a[i]+r3+d+min(min(r1,r2),r3)+d);
		chkmin(f[i][1],f[i-1][1]+d+min(r1,r3)*a[i]+r3);
		f[i][0]=f[i-1][1]+d+min(r2,(a[i]+1)*r1);
	}
	ll ans=min(f[n][1],f[n][0]+d+d+min(min(r1,r2),r3));
	for(int i=1;i<n;i++){
		chkmin(ans,f[i][0]+(n-i+1)*d*2+b[n]-b[i]+min(min(r1,r2),r3)*(n-i+1));
		chkmin(ans,f[i][0]+(n-i)*d*2+b[n-1]-b[i]+min(r1,r3)*a[n]+r3+min(min(r1,r2),r3)*(n-i));
	}
	printf("%lld\n",ans);
	return 0;
}