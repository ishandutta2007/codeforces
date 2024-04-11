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

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,p,k; ll x,y;
int sum[200005];
char s[100005];

int main(){
	int T=readint();
	while(T--){
		n=readint(); p=readint(); k=readint();
		scanf("%s",s+1);
		x=readint(); y=readint();
		for(int i=1;i<=n+k;i++) sum[i]=0;
		for(int i=n;i>=1;i--) sum[i]=sum[i+k]+((s[i]-'0')^1);
		ll ans=1ll<<60;
		for(int i=0;i<=n-p;i++) chkmin(ans,i*y+sum[i+p]*x);
		printf("%lld\n",ans);
	}
	return 0;
}