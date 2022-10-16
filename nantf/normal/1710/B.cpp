#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=666666,mod=998244353;
#define fi first
#define se second
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
inline int qpow(int a,int b){
	int ans=1;
	for(;b;b>>=1,a=1ll*a*a%mod) if(b&1) ans=1ll*ans*a%mod;
	return ans;
}
int n,x[maxn],p[maxn],tmp[maxn],tl;
ll m,d1[maxn],d2[maxn],w[maxn],pre[maxn],suf[maxn];
inline int find(int x){
	return lower_bound(tmp+1,tmp+tl+1,x)-tmp;
}
void clear(){
	FOR(i,0,tl+1) d1[i]=d2[i]=w[i]=pre[i]=suf[i]=tmp[i]=0;
	tl=0;
}
void solve(){
	n=read();m=read();
	FOR(i,1,n){
		x[i]=read();p[i]=read();
		tmp[++tl]=x[i];
		tmp[++tl]=x[i]-p[i];
		tmp[++tl]=x[i]+p[i];
	}
	sort(tmp+1,tmp+tl+1);
	tl=unique(tmp+1,tmp+tl+1)-tmp-1;
	FOR(i,1,n){
		int l=find(x[i]-p[i]),at=find(x[i]),r=find(x[i]+p[i]);
		// l~at += pos-(x[i]-p[i])
		// at+1~r += (p[i]+x[i])-pos
		d1[l]++;d1[at+1]--;
		d2[l]-=x[i]-p[i];d2[at+1]+=x[i]-p[i];
		d1[at+1]--;d1[r+1]++;
		d2[at+1]+=x[i]+p[i];d2[r+1]-=x[i]+p[i]; 
	}
	pre[0]=-1e18;
	FOR(i,1,tl){
		d1[i]+=d1[i-1],d2[i]+=d2[i-1]; 
		w[i]=1ll*d1[i]*tmp[i]+d2[i];
		w[i]=w[i]>m?w[i]-m:-1e18;
		pre[i]=max(w[i],pre[i-1]+tmp[i]-tmp[i-1]);
	}
	suf[tl+1]=-1e18;
	ROF(i,tl,1) suf[i]=max(w[i],suf[i+1]+tmp[i+1]-tmp[i]);
	FOR(i,1,n){
		int at=find(x[i]);
		putchar(max(pre[at],suf[at])<=p[i]?'1':'0');
	}
	puts("");
	clear();
}
int main(){
	int T=read();
	while(T--) solve();
}