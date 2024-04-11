#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=400040,mod=998244353;
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
int n,I,pr=1,a[maxn],ans=1e9,pre[maxn];
int main(){
	n=read();I=read();
	FOR(i,1,n) a[i]=read();
	sort(a+1,a+n+1);
	I=I*8/n;
	while(I && pr<=n) I--,pr*=2;
	pr=min(pr,n);
	pre[1]=1;
	FOR(i,2,n) pre[i]=pre[i-1]+(a[i]!=a[i-1]);
	FOR(i,1,n){
		int x=lower_bound(pre+1,pre+n+1,pre[i]+pr)-pre-1;
		ans=min(ans,i-1+n-x);
	}
	printf("%d\n",ans);
}