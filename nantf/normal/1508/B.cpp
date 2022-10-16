#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=100010,mod=998244353;
const ll INF=2e18;
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
int n,ans[maxn],al;
ll k,f[maxn];
void solve(){
	n=read();k=read();
	f[0]=1;f[1]=1;
	FOR(i,2,n){
		f[i]=0;
		ROF(j,i-1,0){
			f[i]+=f[j];
			if(f[i]>=INF){f[i]=INF;break;}
		}
	}
	if(k>f[n]) return puts("-1"),void();
	int res=n,cur=0;
	al=0;
	while(res){
		FOR(i,1,res){
			if(k>f[res-i]) k-=f[res-i];
			else{
				cur+=i;
				FOR(j,0,i-1) ans[++al]=cur-j;
				res-=i;
				break;
			}
		}
	}
	FOR(i,1,al) printf("%d ",ans[i]);
	puts("");
}
int main(){
	int T=read();
	while(T--) solve();
}