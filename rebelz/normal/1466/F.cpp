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

const int cys=1000000007;
int n,m;
int f[500005];
bool fl[500005];

int getf(int x){return x==f[x]?x:f[x]=getf(f[x]);}

ll qpow(ll x,ll p){
	ll ret=1;
	for(;p;p>>=1,x=x*x%cys) if(p&1) ret=ret*x%cys;
	return ret;
}

int main(){
	n=readint(); m=readint();
	for(int i=1;i<=m;i++) f[i]=i;
	int x,y;
	vector<int> ans;
	for(int i=1;i<=n;i++){
		x=readint();
		if(x==1){
			x=readint();
			int fx=getf(x);
			if(!fl[fx]) ans.pb(i),fl[fx]=1;
		}
		else{
			x=readint(); y=readint();
			int fx=getf(x),fy=getf(y);
			if(fx!=fy&&(!fl[fx]||!fl[fy])) ans.pb(i),f[fy]=fx,fl[fx]|=fl[fy];
		}
	}
	printf("%lld %d\n",qpow(2,ans.size()),ans.size());
	for(auto r:ans) printf("%d ",r);
	printf("\n");
	return 0;
}