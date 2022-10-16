#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=200020,mod=998244353;
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
int n,m,q,fa[maxn*2],cnt;
int getfa(int x){
	return x==fa[x]?x:fa[x]=getfa(fa[x]); 
}
int main(){
	n=read();m=read();q=read();
	cnt=n+m;
	FOR(i,1,n+m) fa[i]=i;
	while(q--){
		int x=read(),y=read()+n;
		x=getfa(x);y=getfa(y);
		if(x!=y) fa[x]=y,cnt--;
	}
	printf("%d\n",cnt-1);
}