#include<bits/stdc++.h>
using namespace std;
const int maxn=500050,mod=1000000007;
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
inline int read(){
	int x=0,f=0;char ch=getchar();
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
struct item{
	int v,id;
	bool operator<(const item &i)const{return v<i.v;}
}it[maxn];
int n,a[maxn],b1[maxn],b2[maxn],ans;
void update(int *b,int p,int v){
	for(int i=p;i<=n;i+=i&-i) b[i]=(b[i]+v)%mod;
}
int query(int *b,int p){
	int s=0;
	for(int i=p;i;i-=i&-i) s=(s+b[i])%mod;
	return s;
}
int calc(int p){
	return (1ll*query(b1,p)*(n-p+1)+1ll*(query(b2,n)-query(b2,p)+mod)%mod*p)%mod;
}
int main(){
	n=read();
	FOR(i,1,n){
		a[i]=read();
		update(b1,i,1ll*a[i]*i%mod);
		update(b2,i,1ll*a[i]*(n-i+1)%mod);
		it[i]=(item){a[i],i};
	}
	sort(it+1,it+n+1);
	FOR(i,1,n){
		int p=it[i].id;
		ans=(ans+calc(p))%mod;
		update(b1,p,mod-1ll*a[p]*p%mod);
		update(b2,p,mod-1ll*a[p]*(n-p+1)%mod);
		a[p]=0;
	}
	printf("%d\n",ans);
}