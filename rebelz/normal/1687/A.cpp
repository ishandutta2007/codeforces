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
ll a[200005],s[200005];

int main(){
	int T=readint();
	while(T--){
		n=readint(); k=readint();
		for(int i=1;i<=n;i++) a[i]=readint();
		if(k>=n){
			ll sum=0;
			for(int i=1;i<=n;i++) sum+=a[i]+k-i;
			printf("%lld\n",sum);
		}
		else{
			ll sum=0,ans=0;
			for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
			for(int i=k;i<=n;i++){
				ll tmp=s[i]-s[i-k];
				chkmax(ans,tmp+1ll*k*(k-1)/2);
			}
			printf("%lld\n",ans);
		}
	}
	return 0;
}