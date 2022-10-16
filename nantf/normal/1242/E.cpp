#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=333333,mod=998244353;
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
int n,a[maxn],q[maxn],h=1,r,tot;
PII p[maxn];
vector<int> v[maxn];
map<PII,bool> vis;
int main(){
	n=read();
	FOR(i,1,n) a[i]=read(),p[i]=MP(a[i],i);
	sort(p+1,p+n+1);
	int sz=p[n].first;
	FOR(i,1,sz) v[p[n].second].PB(q[++r]=++tot);
	FOR(i,1,sz-1) vis[MP(i,i+1)]=vis[MP(i+1,i)]=true;
	vis[MP(1,sz)]=vis[MP(sz,1)]=true;
	ROF(ii,n-1,1){
		int i=p[ii].second,res=ii==1?3:p[ii-1].first,x=0;
		if((r-h+1)+a[i]-2*(a[i]-1)>=res) x=a[i]-1;
		else x=((r-h+1)+a[i]-res)/2;
		if(x==a[i]-1 && vis[MP(q[r],q[r-x+1])]) q[++r]=q[h],h++;
		ROF(j,r,r-x+1) v[i].PB(q[j]);
		int tmp=q[r];
		r-=x;
		v[i].PB(q[r]);
		FOR(j,1,a[i]-x-1) v[i].PB(q[++r]=++tot);
		q[++r]=tmp; 
		FOR(j,0,a[i]-2) vis[MP(v[i][j],v[i][j+1])]=vis[MP(v[i][j+1],v[i][j])]=true;
		vis[MP(v[i][0],v[i][a[i]-1])]=vis[MP(v[i][a[i]-1],v[i][0])]=true;
//		FOR(j,1,tp) printf("%d ",stk[j]);
//		puts("now");
	}
	printf("%d\n",tot);
	FOR(i,1,n){
		FOR(j,0,a[i]-1) printf("%d ",v[i][j]);
		puts("");
	}
}