#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=111111,mod=998244353;
#define MP make_pair
#define PB push_back
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
inline ll read(){
	char ch=getchar();ll x=0,f=0;
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
inline int qpow(int a,int b){
	int ans=1;
	for(;b;b>>=1,a=1ll*a*a%mod) if(b&1) ans=1ll*ans*a%mod;
	return ans;
}
int n,m,l[maxn],r[maxn],k,lim[maxn],a[maxn],q[maxn],hd,rr;
ll t,suf[maxn];
bool fill(int x,int y){
	ROF(i,m,1) a[i]=max(lim[i],a[i+1]);
	a[1]=max(a[1],y);
	bool flag=false;
	FOR(i,1,x) if(~lim[i]){
		flag=true;
		if(lim[i]!=a[1]) return false;
	}
	FOR(i,1,x) a[i]=a[1];
	fuck:
	ll res=t;
	FOR(i,1,m) res-=a[i];
	if(res<0) return false;
	int lst=m+1;
	ROF(i,m,x) if(~lim[i] || i==x){
		int len=(lst-i-1);
		if(1ll*len*(a[i]-a[i+1])<res){
			res-=1ll*len*(a[i]-a[i+1]);
			ROF(j,lst-1,i+1) a[j]+=a[i]-a[i+1];
		}
		else{
			ROF(j,lst-1,i+1) a[j]+=res/len+(j-i<=res%len);
			res=0;
		}
		lst=i;
	}
	if(res){
		if(flag) return false;
		FOR(i,1,m+1) if(~lim[i] || i==m+1){
			int len=i-1;
			if(1ll*len*(n-a[1])<res) return false;
			FOR(j,1,i-1) a[j]+=res/len+(j<=res%len);
			break;
		}
	}
	if(a[1]==a[x]) return true;
	FOR(i,1,x) a[i]=a[1];
	ROF(i,m,x+1) a[i]=max(lim[i],a[i+1]);
	goto fuck;
}
inline double at(int x,int y){
	return 1.0*(suf[y+1]-suf[x+1])/(x-y);
}
bool check(int x,int y){
	if(!fill(x,y)) return false;
	ROF(i,m,1) suf[i]=suf[i+1]+a[i];
	hd=1;rr=0;
	ROF(i,m,0){
		while(hd<rr && at(i,q[rr-1])<=at(q[rr],q[rr-1])) rr--;
		q[++rr]=i;
	}
	ll s1=t,s2=0;
	FOR(i,1,n) s1-=r[i];
	FOR(i,0,n){
		if(i) s1+=r[i],s2+=l[i];
		while(hd<rr && at(q[hd],q[hd+1])<=i) hd++;
		if(1ll*i*q[hd]+suf[q[hd]+1]<max(s1,s2)) return false;
	}
	return true;
}
int main(){
	n=read();m=read();
	FOR(i,1,n) l[i]=read(),r[i]=read();
	k=read();
	FOR(i,1,m) lim[i]=-1;
	while(k--){
		int x=read(),y=read();
		lim[x]=y;
	}
	t=read();
	sort(l+1,l+n+1,greater<int>());
	sort(r+1,r+n+1,greater<int>());
	int L=0,R=m;
	while(L<R){
		int mid=(L+R+1)>>1;
		if(check(mid,0)) L=mid;
		else R=mid-1;
	}
	if(!L) return puts("-1 -1"),0;
	int x=L;L=0;R=n;
	while(L<R){
		int mid=(L+R+1)>>1;
		if(check(x,mid)) L=mid;
		else R=mid-1;
	}
	printf("%d %d\n",x,L);
}