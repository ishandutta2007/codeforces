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

bool chkmin(ll &x,ll y){return x>y?x=y,1:0;}
bool chkmax(ll &x,ll y){return x<y?x=y,1:0;}

ll readint(){
	ll x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

ll n,k,a,b,x,y;
ll ar[200005],s[200005];

ll gcd(ll X,ll Y){return Y==0?X:gcd(Y,X%Y);}

int main(){
	int T=readint();
	while(T--){
		n=readint();
		for(int i=1;i<=n;i++) ar[i]=readint();
		sort(ar+1,ar+n+1); reverse(ar+1,ar+n+1);
		for(int i=1;i<=n;i++) s[i]=s[i-1]+ar[i];
		x=readint(); a=readint();
		y=readint(); b=readint();
		if(x<y) swap(x,y),swap(a,b);
		k=readint();
		ll l=a*b/gcd(a,b),res=-1;
		for(int i=1;i<=n;i++){
			ll now=s[i/l]/100*(x+y);
			now+=(s[i/a]-s[i/l])/100*x;
			now+=(s[i/a+i/b-i/l]-s[i/a])/100*y;
			if(now>=k){
				res=i;
				break;
			}
		}
		printf("%lld\n",res);
	}
	return 0;
}