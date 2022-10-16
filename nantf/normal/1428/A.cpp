#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=100010,mod=998244353;
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
void solve(){
	int x1=read(),y1=read(),x2=read(),y2=read();
	if(x1==x2 && y1==y2) puts("0");
	else if(x1==x2) printf("%d\n",abs(y1-y2));
	else if(y1==y2) printf("%d\n",abs(x1-x2));
	else printf("%d\n",abs(x1-x2)+abs(y1-y2)+2);
}
int main(){
	int T=read();
	while(T--) solve();
}