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

int n,m,k;
ll a[3505],b[3505];

int main(){
	int T=readint();
	while(T--){
		n=readint(); m=readint(); k=readint();
		chkmin(k,m-1);
		for(int i=1;i<=n;i++) a[i]=readint();
		ll l=1,r=1000000000,ret=0;
		while(l<=r){
			ll mid=(l+r)/2;
			for(int i=1;i<=n;i++) b[i]=a[i]>=mid;
			bool can=0;
			for(int i=0;i<=k;i++){
				bool fl=0;
				for(int j=0;j<=m-k-1;j++){
					if(!b[i+j+1]&&!b[n-(k-i)-(m-k-1-j)]){
						fl=1;
						break;
					}
				}
				if(!fl){
					can=1;
					break;
				}
			}
			if(can) ret=mid,l=mid+1;
			else r=mid-1;
		}
		printf("%lld\n",ret);
	}
	return 0;
}