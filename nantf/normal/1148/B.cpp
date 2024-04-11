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
int n,m,ta,tb,k,a[maxn],b[maxn],ans;
int main(){
	n=read();m=read();ta=read();tb=read();k=read();
	if(k>=min(n,m)) return puts("-1"),0;
	FOR(i,1,n) a[i]=read()+ta;
	FOR(i,1,m) b[i]=read();
	sort(a+1,a+n+1);sort(b+1,b+m+1);
	FOR(i,1,k+1){
		int p=lower_bound(b+1,b+m+1,a[i])-b;
		if(p+k-i+1>m) return puts("-1"),0;
		ans=max(ans,b[p+k-i+1]+tb);
	}
	printf("%d\n",ans);
}