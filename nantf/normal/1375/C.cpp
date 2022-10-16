#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=300030;
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
int n,a[maxn];
void solve(){
	n=read();
	FOR(i,1,n) a[i]=read();
	FOR(i,1,n) if(a[i]>=a[1] && a[i]<=a[n]) return puts("YES"),void();
	puts("NO");
}
int main(){
	int T=read();
	while(T--) solve();
}