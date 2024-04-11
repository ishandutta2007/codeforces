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

ll readint(){
	ll x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int cys=1000000007;
int n;
ll pw[65],a[500005],cnt[65];

int main(){
	int T=readint();
	pw[0]=1;
	for(int i=1;i<=60;i++) pw[i]=pw[i-1]*2%cys;
	while(T--){
		n=readint();
		for(int i=1;i<=n;i++) a[i]=readint();
		for(int i=0;i<60;i++) cnt[i]=0;
		for(int i=1;i<=n;i++) for(int j=0;j<60;j++) cnt[j]+=(a[i]>>j)&1;
		ll ans=0;
		for(int i=1;i<=n;i++){
			ll s1=0,s2=0;
			for(int j=0;j<60;j++){
				if((a[i]>>j)&1) s1=(s1+cnt[j]*pw[j])%cys,s2=(s2+n*pw[j])%cys;
				else s2=(s2+cnt[j]*pw[j])%cys;
			}
			ans=(ans+s1*s2)%cys;
		}
		printf("%lld\n",ans);
	}
	return 0;
}