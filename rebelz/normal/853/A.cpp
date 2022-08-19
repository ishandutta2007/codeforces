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

int n,k;
ll a[300005],res[300005];
set<pll> s;

int main(){
	n=readint(); k=readint();
	for(int i=1;i<=n;i++) a[i]=readint();
	ll ans=0,sum=0;
	for(int i=1;i<=k;i++) ans+=a[i]*(k-i),sum+=a[i];
	for(int i=1;i<=k;i++) s.insert(mp(a[i],i));
	for(int i=k+1;i<=k+n;i++){
		if(i<=n) s.insert(mp(a[i],i));
		auto it=--s.end();
		ans+=sum,sum-=it->fi;
		res[it->se]=i;
		s.erase(it);
		if(i<=n) sum+=a[i];
	}
	printf("%lld\n",ans);
	for(int i=1;i<=n;i++) printf("%d ",res[i]);
	printf("\n");
	return 0;
}