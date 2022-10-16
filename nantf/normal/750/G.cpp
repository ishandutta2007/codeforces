#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=100010,mod=998244353;
#define lson o<<1,l,mid
#define rson o<<1|1,mid+1,r
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
inline int read(){
	int x=0,f=0;char ch=getchar();
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
ll n,f[55][111][2];
int bitcnt(ll x){
	int c=0;
	for(;x;x&=x-1) c++;
	return c;
}
ll solve1(){
	ll ans=0;
	FOR(i,1,50){
		ll x=n/((1ll<<i)-1);
		if(!x) break;
		ll res=n-x*((1ll<<i)-1);
		FOR(j,0,i-1) if((res+j)%2==0 && bitcnt(res+j)==j) ans++;
	}
	return ans;
}
ll solve2(){
	ll ans=0;
	FOR(l,2,50) FOR(r,2,50){
		ll x=(n-(1ll<<(r-1))+1)/((1ll<<l)+(1ll<<r)-3);
		if(!x) break;
//		printf("x=%lld\n",x);
		ll res=n-(1ll<<(r-1))+1-x*((1ll<<l)+(1ll<<r)-3);
		FOR(cnt,0,l+r-4) if((res+cnt)%2==0){
//			printf("l=%d,r=%d,cnt=%d,res+cnt=%d\n",l,r,cnt,res+cnt);
			FOR(i,0,max(l,r)) FOR(j,0,min(cnt,2*i)) f[i][j][0]=f[i][j][1]=0;
			f[0][0][0]=1;
			FOR(i,1,max(l,r)+1) FOR(j,0,min(cnt,2*(i-1))){
				FOR(k,0,1) FOR(a,0,1) FOR(b,0,1){
					if(i>=l-1 && a==1) continue;
					if(i>=r-1 && b==1) continue;
					if((k+a+b)%2==((res+cnt)>>i)%2) f[i][j+a+b][(k+a+b)/2]+=f[i-1][j][k];
				}
//				printf("f[%d][%d][0]=%lld,f[%d][%d][1]=%lld\n",i-1,j,f[i-1][j][0],i-1,j,f[i-1][j][1]);
			}
			ans+=f[max(l,r)][cnt][0];
		}
	}
	return ans;
}
int main(){
	scanf("%lld",&n);
	printf("%lld\n",solve1()+solve2());
}