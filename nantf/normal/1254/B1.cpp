#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=1000100;
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
int n;
ll pre[maxn],ans=1e18;
ll calc(ll x){
	ll s=0;
	FOR(i,1,n-1) s+=min(pre[i]%x,x-pre[i]%x);
	return s;
}
int main(){
	n=read();
	FOR(i,1,n) pre[i]=pre[i-1]+read();
	ll x=pre[n];
	int sq=sqrt(x);
	FOR(i,2,sq) if(x%i==0){
		ans=min(ans,calc(i));
		while(x%i==0) x/=i;
	}
	if(x>1) ans=min(ans,calc(x));
	printf("%lld\n",ans==1e18?-1ll:ans);
}