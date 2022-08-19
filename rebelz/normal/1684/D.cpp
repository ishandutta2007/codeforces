// xtqqwq
#include<bits/stdc++.h>

#define fi first
#define se second
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

template<typename T> bool chkmax(T &x,T y){return x<y?x=y,1:0;}
template<typename T> bool chkmin(T &x,T y){return x>y?x=y,1:0;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,k;
ll a[200005],b[200005];

int main(){
	int T=readint();
	while(T--){
		n=readint(); k=readint();
		ll sum=0;
		for(int i=1;i<=n;i++) a[i]=readint(),sum+=a[i];
		for(int i=1;i<=k;i++) sum+=n-k+i;
		for(int i=1;i<=n;i++) b[i]=a[i]+i;
		sort(b+1,b+n+1);
		for(int i=n;i>=n-k+1;i--) sum-=b[i];
		printf("%lld\n",sum);
	}
	return 0;
}