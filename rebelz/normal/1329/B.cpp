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

int n,cys;
ll d[35],b[35];

int main(){
	int T=readint();
	while(T--){
		n=readint(); cys=readint();
		int m=1,l=0;
		while((m<<1)<=n) m<<=1,l++;
		for(int i=0;i<l;i++) b[i]=1<<i;
		b[l]=n-m+1;
		memset(d,0,sizeof(d));
		d[0]=1;
		ll ans=1;
		for(int i=1;i<=l+1;i++){
			for(int j=0;j<i;j++) d[i]=(d[i]+d[j]*b[i-1])%cys;
			ans=(ans+d[i])%cys;
		}
		printf("%lld\n",(ans+cys-1)%cys);
	}
	return 0;
}