#include<bits/stdc++.h>
using namespace std;
const int maxn=100100;
#define lson o<<1,l,mid
#define rson o<<1|1,mid+1,r
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
inline int read(){
	char ch=getchar();int x=0,f=0;
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
int t,n,a[maxn];
int main(){
	t=read();
	while(t--){
		n=read();
		FOR(i,1,n) a[i]=read();
		sort(a+1,a+n+1);
		printf("%d\n",min(a[n-1]-1,n-2));
	}
}