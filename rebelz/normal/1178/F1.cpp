#include<bits/stdc++.h>

#define mp make_pair
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

struct Hash{
	size_t operator()(const pii x)const{return x.fi*501+x.se;}
};

const int cys=998244353;
int n,m;
int a[505],b[505];
ll d[505][505];

ll mod(ll x){return x>=cys?x-cys:x;}

ll dp(int l,int r,int x){
	if(l>r) return 1;
	if(d[l][r]) return d[l][r];
	while(b[x]<l||b[x]>r) x++;
	ll now1=0,now2=0;
	for(int i=l;i<=b[x];i++) now1=mod(now1+dp(l,i-1,x+1)*dp(i,b[x]-1,x+1)%cys);
	for(int i=b[x];i<=r;i++) now2=mod(now2+dp(b[x]+1,i,x+1)*dp(i+1,r,x+1)%cys);
	d[l][r]=now1*now2%cys;
	return d[l][r];
}

int main(){
	n=readint(); m=readint();
	for(int i=1;i<=m;i++) a[i]=readint(),b[a[i]]=i;
	cout<<dp(1,m,1)<<endl;
	return 0;
}