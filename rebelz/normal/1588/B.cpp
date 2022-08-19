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

ll readint(){
	ll x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n;

ll ask(int l,int r){
	printf("? %d %d\n",l,r);
	fflush(stdout);
	return readint();
}

void solve(int l,int r,ll val){
	int mid=(l+r)/2;
	ll lf=ask(l,mid);
	if(!lf) solve(mid,r,val);
	else if(lf==val) solve(l,mid,val);
	else{
		ll rg=ask(mid+1,r);
		ll tl=ask(l,mid-1),tr=ask(mid,r);
		ll x=tr-rg,y=lf-tl+1;
		if(rg==1ll*x*(x-1)/2){
			ll rem=lf-1ll*y*(y-1)/2;
			ll res=sqrt(2*rem);
			while(1ll*res*(res-1)/2<rem) res++;
			if(!res) res++;
			printf("! %d %d %d\n",mid-y-res+1,mid-y+1,mid+x);
		}
		else{
			ll rem=rg-1ll*x*(x-1)/2;
			ll res=sqrt(2*rem);
			while(1ll*res*(res-1)/2<rem) res++;
			if(!res) res++;
			printf("! %d %d %d\n",mid-y+1,mid+x+1,mid+x+res);
		}
		fflush(stdout);
		return;
	}
}

int main(){
	int T=readint();
	while(T--){
		n=readint();
		solve(1,n,ask(1,n));
	}
	return 0;
}