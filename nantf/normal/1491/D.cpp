#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=100010,mod=998244353;
#define PB push_back
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
int x,y,a[maxn],al,b[maxn],bl;
void solve(){
	x=read();y=read();
	if(x>y) return puts("NO"),void();
	if(x==y) return puts("YES"),void();
	al=bl=0;
	FOR(i,0,29) if((x>>i)&1) a[++al]=i;
	FOR(i,0,29) if((y>>i)&1) b[++bl]=i;
	if(al<bl) return puts("NO"),void();
	ROF(i,al,1){
		int j=bl-(al-i);
		if(a[i]>b[j]) return puts("NO"),void();
		if(a[i]==b[j]) continue;
		FOR(k,1,j-1) if(a[k]>b[k]) return puts("NO"),void();
		puts("YES");
		break;
	}
}
int main(){
	int T=read();
	while(T--) solve();
}