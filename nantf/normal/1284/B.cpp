#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=1000100;
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
int n,l,a[maxn],s[maxn],t[maxn],m,cnt[maxn];
ll ans;
int main(){
	n=read();
	FOR(i,1,n){
		l=read();
		FOR(j,1,l) a[j]=read();
		bool flag=false;
		FOR(j,2,l) flag|=a[j-1]<a[j];
		if(!flag) cnt[a[1]]++,t[++m]=a[l];
	}
	FOR(i,1,1000000) cnt[i]+=cnt[i-1];
	ans=1ll*n*n;
	FOR(i,1,m) ans-=cnt[t[i]];
	printf("%lld\n",ans);
}