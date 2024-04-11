#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=200020;
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
int n,p[maxn],cnt;
ll sum[maxn];
int main(){
	n=read();
	for(int i=1,j=n+1;i<=n;i++,j++){
		if(i%2==0) p[i]=++cnt,p[j]=++cnt;
		else p[j]=++cnt,p[i]=++cnt;
	}
	FOR(i,1,n) sum[n]+=p[i];
	FOR(i,n+1,2*n) sum[i]=sum[i-1]+p[i]-p[i-n];
	sum[1]=sum[2*n]+p[1]-p[n+1];
	FOR(i,2,n-1) sum[i]=sum[i-1]+p[i]-p[i+n];
	sort(sum+1,sum+2*n+1);
	if(sum[2*n]-sum[1]>1) return puts("NO"),0;
	puts("YES");
	FOR(i,1,2*n) printf("%d ",p[i]);
}