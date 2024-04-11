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

ll n,ans=0;
ll val[300005],mask[300005],cnt[300005];

int main(){
	n=readint();
	ll sum=0;
	for(int i=1;i<=n;i++) val[i]=readint(),mask[i]=readint(),sum+=val[i];
	if(sum<0) for(int i=1;i<=n;i++) val[i]*=-1;
	for(int i=61;i>=0;i--){
		ll res=0;
		for(int j=1;j<=n;j++) if((1ll<<i)==(mask[j]&(-mask[j]))) res+=(cnt[j]&1?-1ll:1ll)*val[j];
		if(res>0){
			ans|=(1ll<<i);
			for(int j=1;j<=n;j++) if((mask[j]>>i)&1) cnt[j]++;
		}
	}
	cout<<ans<<endl;
	return 0;
}