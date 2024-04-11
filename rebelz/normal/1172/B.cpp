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

const int cys=998244353;
int n;
int du[200005];
ll fac[200005];

int main(){
	n=readint();
	fac[0]=1;
	for(int i=1;i<=n;i++) fac[i]=fac[i-1]*i%cys;
	for(int i=1;i<=n-1;i++) du[readint()]++,du[readint()]++;
	ll ans=1;
	for(int i=1;i<=n;i++) ans=ans*fac[du[i]]%cys;
	cout<<ans*n%cys<<endl;
	return 0;
}