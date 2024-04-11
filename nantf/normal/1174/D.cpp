#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=333333;
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
int n,x,lim,ans[maxn],al;
bool vis[maxn];
int main(){
	n=read();x=read();
	lim=1<<n;
	FOR(i,1,lim-1){
		if(vis[i^x] || i==x) continue;
		vis[i]=true;
		ans[++al]=i;
	}
	printf("%d\n",al);
	FOR(i,1,al) printf("%d ",ans[i]^ans[i-1]);
}