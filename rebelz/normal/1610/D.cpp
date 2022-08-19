// xtqqwq
#include<bits/stdc++.h>

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

const int cys=1000000007;
int n;
int a[35],s[35];
ll pw[200005];

int main(){
	n=readint();
	int x;
	for(int i=1;i<=n;i++){
		x=readint();
		int cnt=0;
		while(!(x&1)) x>>=1,cnt++;
		a[cnt]++;
	}
	for(int i=30;i>=1;i--) s[i]=s[i+1]+a[i];
	pw[0]=1;
	for(int i=1;i<=n;i++) pw[i]=pw[i-1]*2%cys;
	ll ans=(pw[a[0]]-1)*pw[n-a[0]]%cys;
	for(int i=1;i<=30;i++){
		if(!a[i]) continue;
		ans=(ans+(pw[a[i]-1]-1)*pw[s[i]-a[i]])%cys;
	}
	printf("%lld\n",ans);
	return 0;
}