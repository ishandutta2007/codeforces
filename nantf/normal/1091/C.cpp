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
inline int read(){
	char ch=getchar();int x=0,f=0;
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
int n,m;
ll ans[100010];
int main(){
	n=read();
	ans[1]=1ll*n*(n+1)/2;
	ans[m=2]=1;
	for(int i=2;i*i<=n;i++)
		if(n%i==0){
			int t=(n-1)/i;
			ans[++m]=1ll*t*(t+1)/2*i+t+1;
			t=(n-1)/(n/i);
			ans[++m]=1ll*t*(t+1)/2*(n/i)+t+1;
		}
	sort(ans+1,ans+m+1);int sz=unique(ans+1,ans+m+1)-ans-1;
	FOR(i,1,sz) printf("%I64d ",ans[i]);
}