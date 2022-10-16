#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=1111111,mod=998244353;
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
int n,m,mt,x,y,g,a[maxn],b[maxn],cnt[maxn],at[maxn],tx[maxn];
ll k,sum,ans;
inline int gcd(int x,int y){return y?gcd(y,x%y):x;}
inline int exgcd(int a,int b,int &x,int &y){
	if(!b){x=1;y=0;return a;}
	int d=exgcd(b,a%b,y,x);
	y-=a/b*x;
	return d;
}
bool check(ll mid){
//	printf("check %lld\n",mid);
	ll tot=0;
	FOR(i,0,n-1){
		if(i>=mid) break;
		int r=(mid-1-i)/n;
//		printf("i=%d,r=%d\n",i,r);
		tot+=r+1;
		if(tx[i]<=r) tot--;
//		i+k*n;
	}
//	printf("tot=%lld\n",tot);
	return tot>=k;
} 
int main(){
	n=read();m=read();k=read();
	FOR(i,0,n-1) a[i]=read();
	MEM(at,-1);
	FOR(i,0,m-1) b[i]=read(),at[b[i]]=i;//,printf("set %d to %d\n",b[i],i);
	g=exgcd(n,m,x,y);
	mt=m/g;
	FOR(i,0,g-1){
		for(int j=i;j<n;j+=g) cnt[a[j]]++;
		for(int j=i;j<m;j+=g) sum+=n/g-cnt[b[j]];
		for(int j=i;j<n;j+=g) cnt[a[j]]--;
	}
//	printf("sum=%lld\n",sum);
	k--;
	ans=1ll*n/g*m*(k/sum);
	k%=sum;
	k++;
	FOR(i,0,n-1){
		tx[i]=1e9;
		if(~at[a[i]]){
			int tmp=(at[a[i]]-i+m)%m;
//			printf("tmp=%d,a[i]=%d,at=%d\n",tmp,a[i],at[a[i]]);
			if(tmp%g==0){
				tx[i]=(1ll*x*(tmp/g)%mt+mt)%mt;
//				printf("x=%d,y=%d,tx=%d\n",x,y,tx);
			}
//			if(tmp=k*n+k2*m,k<=r) tot--;
		}
	}
	ll l=0,r=1ll*n/g*m;
	while(l<r){
		ll mid=(l+r)>>1;
		if(check(mid)) r=mid;
		else l=mid+1;
	}
//	printf("l=%lld\n",l);
	printf("%lld\n",ans+l);
}
/*
3 6 9
4 6 2
4 1 3 6 5 2

  . . . .     . . . .  
4 6 2 4 6 2 4 6 2 4 6 2
4 1 3 6 5 2 4 1 3 6 5 2
*/