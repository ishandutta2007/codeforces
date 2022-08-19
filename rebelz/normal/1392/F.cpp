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

ll readint(){
	ll x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n;
ll a[1000005];

int main(){
	n=readint();
	for(int i=1;i<=n;i++) a[i]=readint();
	ll sum=0;
	for(int i=1;i<=n;i++) sum+=a[i];
	ll l=0,r=1000000000000ll,res;
	while(l<=r){
		ll mid=(l+r)/2;
		if(n*(mid+mid+n-1)/2>sum) r=mid-1;
		else res=mid,l=mid+1;
	}
	sum-=n*(res+res+n-1)/2;
	for(int i=1;i<=n;i++) printf("%lld ",res+i+(i<=sum)-1);
	printf("\n");
	return 0;
}