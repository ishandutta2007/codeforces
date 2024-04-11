#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=300030,mod=998244353;
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
int T,n,a[maxn],tot,cnt[maxn],fa[maxn],now;
ll ans;
map<int,int> ch[maxn];
int main(){
	T=read();
	while(T--){
		n=read();
		FOR(i,1,n) a[i]=read();
		now=tot=1;ans=0;cnt[1]=1;
		FOR(i,1,n){
			if(ch[fa[now]][a[i]]==now) now=fa[now];
			else{
				if(!ch[now][a[i]]) ch[now][a[i]]=++tot,fa[tot]=now;
				now=ch[now][a[i]];
			}
			ans+=cnt[now];
			cnt[now]++;
		}
		FOR(i,1,tot) cnt[i]=0,ch[i].clear();
		printf("%lld\n",ans);
	}
}