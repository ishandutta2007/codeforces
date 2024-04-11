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

ll readint(){
	ll x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

ll k,d,t;

int main(){
	k=readint(); d=readint(); t=readint();
	ll x=(k-1)/d+1;
	ll tmp=k*2+(x*d-k);
	ll p=(2*t)/tmp;
	ll ans=p*(x*d);
	ll rem=(2*t)-tmp*p;
	if(rem<=k*2) printf("%.10Lf\n",(long double)ans+(long double)rem/2);
	else printf("%lld\n",ans+k+rem-k*2);
	return 0;
}