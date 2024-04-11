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

ll n,k;
ll a[200005];

int main(){
	int T=readint();
	while(T--){
		n=readint(); k=readint();
		for(int i=1;i<=n;i++) a[i]=readint();
		ll maxa=-(1ll<<60);
		for(int i=1;i<=n;i++) chkmax(maxa,a[i]);
		for(int i=1;i<=n;i++) a[i]=maxa-a[i];
		k--;
		if(k%2==0){
			for(int i=1;i<=n;i++) printf("%d ",a[i]);
			printf("\n");
		}
		else{
			maxa=-(1ll<<60);
			for(int i=1;i<=n;i++) chkmax(maxa,a[i]);
			for(int i=1;i<=n;i++) a[i]=maxa-a[i];
			for(int i=1;i<=n;i++) printf("%d ",a[i]);
			printf("\n");
		}
	}
	return 0;
}