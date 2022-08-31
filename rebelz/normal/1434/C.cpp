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

ll a,b,c,d;

int main(){
	int T=readint();
	while(T--){
		a=readint(); b=readint(); c=readint(); d=readint();
		if(a>b*c){
			printf("-1\n");
			continue;
		}
		if(c<d) printf("%lld\n",a);
		else{
			ll ts=(a-1)/b;
			ts=ts/d*d;
			ll k=ts/d;
			ll ans=(k+1)*a;
			ans-=k*(k+1)/2*b*d;
			printf("%lld\n",ans);
		}
	}
	return 0;
}