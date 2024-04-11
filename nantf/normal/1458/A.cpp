#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=222222,mod=998244353;
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
inline int qmo(int x){return x+(x>>31?mod:0);}
int n,m;
ll a[maxn],b[maxn],g;
ll gcd(ll x,ll y){return y?gcd(y,x%y):x;}
int main(){
	n=read();m=read();
	FOR(i,1,n) a[i]=read();
	FOR(i,1,m) b[i]=read();
	sort(a+1,a+n+1);
	FOR(i,2,n) g=gcd(a[i]-a[1],g);
	FOR(i,1,m) printf("%lld ",gcd(g,a[1]+b[i]));
}