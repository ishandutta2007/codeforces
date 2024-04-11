#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=100010,mod=998244353;
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
int t,n,k,a[maxn],pre[maxn],pre2[maxn],mn[maxn*8],pre3[maxn],pre4[maxn];
void build(int o,int l,int r){
	mn[o]=1e9;
	if(l==r) return;
	int mid=(l+r)>>1;
	build(lson);build(rson);
}
void update(int o,int l,int r,int p,int v){
	mn[o]=min(mn[o],v);
	if(l==r) return;
	int mid=(l+r)>>1;
	if(mid>=p) update(lson,p,v);
	else update(rson,p,v);
}
int query(int o,int l,int r,int ql,int qr){
	if(l>=ql && r<=qr) return mn[o];
	int mid=(l+r)>>1,ans=1e9;
	if(mid>=ql) ans=min(ans,query(lson,ql,qr));
	if(mid<qr) ans=min(ans,query(rson,ql,qr));
	return ans; 
}
int main(){
	t=read();
	while(t--){
		n=read();k=read();
		FOR(i,1,n){
			a[i]=read();
			if(a[i]==k) a[i]=0;
			else if(a[i]>k) a[i]=1;
			else a[i]=-1;
			pre[i]=pre[i-1]+a[i];
			pre2[i]=pre2[i-1]+(a[i]==1?1:-1);
			pre3[i]=pre3[i-1]+(a[i]==-1?-1:1);
			pre4[i]=pre4[i-1]+(a[i]==1?-1:1);
		}
		if(n==1){puts(a[1]?"NO":"YES");continue;}
		bool flag=false;
		FOR(i,1,n) if(!a[i]) flag=true;
		if(!flag){puts("NO");continue;}
		int lst=0;
		flag=false;
		build(1,-n,n);
		FOR(i,1,n){
			if(!a[i]){
				FOR(j,lst,i-2) update(1,-n,n,pre3[j],pre4[j]);
				lst=i;
			}
			if(query(1,-n,n,-n,pre3[i]-1)<=pre4[i]) flag=true;
			if(!a[i]) update(1,-n,n,pre3[i-1],pre4[i-1]);
		}
		if(flag){puts("YES");continue;}
		flag=false;
		int at1=n+1,at2=0,mn=1e9,mx=-1e9; 
		FOR(i,1,n){
			if(pre2[i]-mn>0 && at1==n+1) at1=i;
			mn=min(mn,pre2[i-1]);
		}
		ROF(i,n,1){
			if(mx-pre2[i-1]>0 && !at2) at2=i;
			mx=max(mx,pre2[i]);
		}
		FOR(i,at1+1,n) if(!a[i]) flag=true;
		FOR(i,1,at2-1) if(!a[i]) flag=true;
		puts(flag?"YES":"NO");
	}
}