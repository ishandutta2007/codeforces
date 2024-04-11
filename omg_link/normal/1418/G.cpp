#include <stdio.h>
#include <map>
#define MN 500000
typedef long long LL;
const int mod1=998244853;
const int mod2=1000000009;
const int bsc1=3216712;
const int bsc2=3217863;

int n,a[MN+5],c[MN+5],cc[MN+5];
LL h1=0,h2=0,ans=0;

struct node{
	int hash1,hash2;
	node(){}
	node(int hash1,int hash2){
		this->hash1 = hash1;
		this->hash2 = hash2;
	}
	bool operator < (const node &b)const{
		if(hash1!=b.hash1) return hash1<b.hash1;
		return hash2<b.hash2;
	}
}b[MN+5];

std::map<node,int> mp;

int qpow(LL bsc,int y,int mod){
	LL ret = 1;
	while(y){
		if(y&1) ret=(ret*bsc)%mod;
		bsc=(bsc*bsc)%mod;
		y>>=1;
	}
	return ret;
}

int main(){
	scanf("%d",&n);
	mp[node(h1,h2)]++;
	for(int i=1,l=0;i<=n;i++){
		scanf("%d",&a[i]);
		h1 -= 1ll*c[a[i]]*qpow(bsc1,a[i],mod1);
		h2 -= 1ll*c[a[i]]*qpow(bsc2,a[i],mod2);
		c[a[i]] = (c[a[i]]+1)%3;
		cc[a[i]]++;
		h1 += 1ll*c[a[i]]*qpow(bsc1,a[i],mod1);
		h2 += 1ll*c[a[i]]*qpow(bsc2,a[i],mod2);
		h1 = ((h1%mod1)+mod1)%mod1;
		h2 = ((h2%mod2)+mod2)%mod2;
		b[i] = node(h1,h2);
		mp[b[i]]++;
		while(cc[a[i]]>3){
			mp[b[l]]--;
			cc[a[++l]]--;
		}
		ans += mp[b[i]]-1;
	}
	printf("%lld\n",ans);
}