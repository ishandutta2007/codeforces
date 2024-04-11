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

int n,k;
ll a[500005],s[500005],sa[500005];

int main(){
	n=readint(); k=readint();
	for(int i=1;i<=n;i++) a[i]=readint();
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	for(int i=n;i>=1;i--) sa[i]=sa[i+1]+a[i]*i;
	ll ans=sa[1]-s[n],now=0;
	for(int i=1;i<=n;i++){
		int pl=(i-1)/(k+1);
		now+=pl*a[i];
		chkmax(ans,now+sa[i+1]-(s[n]-s[i])*(i-pl));
	}
	printf("%lld\n",ans);
	return 0;
}