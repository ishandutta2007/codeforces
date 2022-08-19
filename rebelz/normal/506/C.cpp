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

int n,m,k,p;
ll h[100005],a[100005],b[100005],s[100005];

bool check(ll x){
	ll sum=0;
	for(int i=1;i<=n;i++) b[i]=max(0ll,(ll)ceil(1.0*(h[i]+a[i]*m-x)/p)),sum+=b[i];
	if(sum>k*m) return false;
	memset(s,0,sizeof(s));
	for(int i=1;i<=n;i++) for(int j=1;j<=b[i];j++) s[max(0ll,m+1-((b[i]-j)*p+x)/a[i])]++;
	for(int i=m;i>=1;i--) s[i]+=s[i+1];
	for(int i=m;i>=1;i--) if(s[i]>(m-i+1)*k) return false;
	return true;
}

int main(){
	n=readint(); m=readint(); k=readint(); p=readint();
	ll mina=0;
	for(int i=1;i<=n;i++) h[i]=readint(),a[i]=readint(),chkmax(mina,a[i]);
	ll l=mina,r=1e13,ans=0;
	while(l<=r){
		ll mid=(l+r)/2;
		if(check(mid)) ans=mid,r=mid-1;
		else l=mid+1;
	}
	printf("%lld\n",ans);
	return 0;
}