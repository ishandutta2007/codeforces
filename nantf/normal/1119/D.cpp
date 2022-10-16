#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=100010;
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
struct query{
	ll k;
	int id;
	bool operator<(const query &q)const{
		return k<q.k;
	}
}ask[maxn];
struct item{
	ll val;
	int lft;
	bool operator<(const item &i)const{
		return val<i.val;
	}
}dif[maxn];
int n,q,mn[maxn],mx[maxn],fa[maxn],cnt;
ll s[maxn],ans[maxn],sum;
int getfa(int x){
	return x==fa[x]?x:fa[x]=getfa(fa[x]);
}
int main(){
	n=read();
	FOR(i,1,n) s[i]=read();
	sort(s+1,s+n+1);
	FOR(i,1,n-1) dif[i]=(item){s[i+1]-s[i],i};
	sort(dif+1,dif+n);
	q=read();
	FOR(i,1,q){
		ll l=read(),r=read();
		ask[i]=(query){r-l,i};
	}
	sort(ask+1,ask+q+1);
	FOR(i,1,n) mn[i]=mx[i]=fa[i]=i,sum++;
	int cur=1;
	cnt=n;
	FOR(i,1,q){
		while(cur<=n-1 && dif[cur].val<=ask[i].k){
			int l=dif[cur].lft;
			int u=getfa(l),v=getfa(l+1);
			sum+=s[mn[v]];
			sum-=s[mx[u]];
			sum--;
			fa[u]=v;
			mn[v]=mn[u];
			cnt--;
			cur++;
		}
		ans[ask[i].id]=sum+cnt*ask[i].k;
	}
	FOR(i,1,q) cout<<ans[i]<<" ";
}