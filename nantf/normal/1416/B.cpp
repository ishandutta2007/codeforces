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
inline int qmo(int x){return x+(x>>31?mod:0);}
int n,a[maxn],x,ans[maxn][3],al;
inline void work(int i,int j,int x){
	ans[++al][0]=i;ans[al][1]=j;ans[al][2]=x;
	a[i]-=i*x;a[j]+=i*x;
}
void solve(){
	n=read();
	x=0;
	FOR(i,1,n) x+=a[i]=read();
	if(x%n) return puts("-1"),void();
	x/=n;
	al=0;
	FOR(i,2,n){
		if(a[i]%i) work(1,i,i-a[i]%i);
		work(i,1,a[i]/i);
	}
	FOR(i,2,n) work(1,i,x-a[i]);
	printf("%d\n",al);
	FOR(i,1,al) printf("%d %d %d\n",ans[i][0],ans[i][1],ans[i][2]);
}
int main(){
	int T=read();
	while(T--) solve();
}