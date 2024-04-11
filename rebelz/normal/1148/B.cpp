#include<bits/stdc++.h>

#define mp make_pair
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

ll readint(){
	ll x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

ll n,m,ta,tb,k;
ll a[200005],b[200005];
ll ans=0;

int main(){
	n=readint(); m=readint(); ta=readint(); tb=readint(); k=readint();
	for(int i=1;i<=n;i++) a[i]=readint()+ta;
	for(int i=1;i<=m;i++) b[i]=readint();
	if(k>=n) return printf("-1\n"),0;
	for(int i=1;i<=n;i++){
		ll tmp=k-i+1,p=lower_bound(b+1,b+m+1,a[i])-b-1;
		if(tmp<0) continue;
		if(p+tmp>=m) return printf("-1\n"),0;
		ans=max(ans,b[p+tmp+1]+tb);
	}
	cout<<ans<<endl;
	return 0;
}