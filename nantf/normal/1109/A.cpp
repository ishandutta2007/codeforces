#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=300030;
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
inline int read(){
	char ch=getchar();int x=0,f=0;
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
int n,a[maxn],s[maxn],cnt[1111111][2];
ll ans;
int main(){
	n=read();
	FOR(i,1,n) a[i]=read(),s[i]=s[i-1]^a[i];
	cnt[0][0]=1;
	FOR(i,1,n){
		ans+=cnt[s[i]][i&1];
		cnt[s[i]][i&1]++;
	}
	printf("%I64d\n",ans);
}