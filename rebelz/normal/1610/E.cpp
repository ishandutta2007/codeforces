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

int n;
ll a[200005];

int main(){
	int T=readint();
	while(T--){
		n=readint();
		for(int i=1;i<=n;i++) a[i]=readint();
		a[n+1]=0;
		ll ans=0,num=(a[1]==a[2]);
		for(int i=2;i<=n;i++){
			if(a[i]==a[i+1]){
				num++;
				continue;
			}
			ll pl=i,now=a[i]-a[i-1],cnt=max(2ll,num+1);
			while(pl<=n){
				pl=lower_bound(a+pl+1,a+n+1,2*now+a[i-1])-a;
				if(pl>n) break;
				now=a[pl]-a[i-1];
				cnt++;
			}
			num=0;
			chkmax(ans,cnt);
		}
		printf("%lld\n",n-ans);
	}
	return 0;
}