#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=555555,mod=998244353;
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
int n,lim=1,ans[maxn][2],al;
void work(int l,int r){
	if(l==r) return;
	int mid=(l+r)>>1;
	work(l,mid);work(mid+1,r);
	FOR(i,l,mid) ans[++al][0]=i,ans[al][1]=mid+i-l+1;
}
int main(){
	n=read();
	while(lim<=n) lim<<=1;
	lim>>=1;
	work(1,lim);work(n-lim+1,n);
	printf("%d\n",al);
	FOR(i,1,al) printf("%d %d\n",ans[i][0],ans[i][1]);
}