#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=200020;
#define MP make_pair
#define PB push_back
#define lson o<<1,l,mid
#define rson o<<1|1,mid+1,r
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
inline ll read(){
	char ch=getchar();ll x=0,f=0;
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
inline int rnd(int l,int r){return uniform_int_distribution<int>(l,r+1)(rng);}
int n,ans,pl;
ll a[maxn],pr[maxn];
inline ll calc(ll x){
	ll s=0;
	FOR(i,1,n){
		if(a[i]<x) s+=x-a[i]%x;
		else s+=min(a[i]%x,x-a[i]%x);
	}
	return s;
}
void fac(ll x){
	for(int i=2;1ll*i*i<=x;i++) if(x%i==0){
		pr[++pl]=i;
		while(x%i==0) x/=i;
	}
	if(x>1) pr[++pl]=x;
}
int main(){
	ans=n=read();
	FOR(i,1,n) a[i]=read();
	FOR(_,1,20){
		int x=rnd(1,n);
		pl=0;
		fac(a[x]-1);fac(a[x]);fac(a[x]+1);
		FOR(i,1,pl) ans=min((ll)ans,calc(pr[i]));
	}
	printf("%d\n",ans);
}
// yet another shit problem, shit solution