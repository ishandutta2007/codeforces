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
int n,x,y,cnt;
ll ans=1e18;
char s[maxn];
int main(){
	n=read();x=read();y=read();
	scanf("%s",s+1);
	FOR(i,1,n) if(s[i]=='0' && (i==1 || s[i-1]=='1')) cnt++;
	if(!cnt) return puts("0"),0;
	FOR(i,0,cnt-1) ans=min(ans,1ll*y*(cnt-i)+1ll*x*i);
	cout<<ans<<endl;
}