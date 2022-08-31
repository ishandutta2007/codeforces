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
ll n,m;
ll f[100005];

ll mod(ll x){return x>=cys?x-cys:x;}

int main(){
	n=readint(); m=readint();
	f[0]=f[1]=1;
	for(int i=2;i<=max(n,m);i++) f[i]=mod(f[i-1]+f[i-2]);
	cout<<(2*f[n]+2*f[m]+cys-2)%cys<<endl;
	return 0;
}