#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=100010,mod=998244353;
#define PB push_back
#define MP make_pair
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
int n,a[maxn],fa[maxn];
void work(int i){
//	printf("work(%d)\n",i);
	if(i!=n) fa[i]=fa[i+1];
	ROF(j,i-1,1) if(a[j]==1) fa[j]=fa[i];
	else break;
}
void solve(){
	n=read();
	FOR(i,1,n) a[i]=read();
	FOR(i,1,n) fa[i]=i;
	FOR(i,1,n) if(a[i]==1) work(i);
	ll ans=0;
	FOR(i,1,n){
		ans+=max(0,a[i]-max(1,n-i));
		a[i]=min(a[i],n-i);
		while(a[i]>1){
			int cur=i;
//			printf("start from %d\n",i);
			while(true){
				int to=cur+a[cur];
				if(a[cur]==2) work(cur);
				a[cur]=max(1,a[cur]-1);
				if(to>n) break;
				cur=fa[to];
//				printf("at %d\n",cur);
			}
			ans++;
		}
	}
	printf("%lld\n",ans);
}
int main(){
	int T=read();
	while(T--) solve();
}