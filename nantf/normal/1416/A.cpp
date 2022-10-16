#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=500050,mod=998244353;
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
int n,a[maxn],ans[maxn];
vector<int> v[maxn];
void solve(){
	n=read();
	FOR(i,1,n) a[i]=read();
	FOR(i,1,n) ans[i]=1e9,v[i].clear();
	FOR(i,1,n) v[a[i]].PB(i);
	FOR(i,1,n) if(!v[i].empty()){
		int x=max(v[i].front(),n-v[i].back()+1);
		FOR(j,0,(int)v[i].size()-2) x=max(x,v[i][j+1]-v[i][j]);
		ans[x]=min(ans[x],i);
	}
	FOR(i,2,n) ans[i]=min(ans[i],ans[i-1]);
	FOR(i,1,n) printf("%d ",ans[i]==1e9?-1:ans[i]);
	puts("");
}
int main(){
	int T=read();
	while(T--) solve();
}