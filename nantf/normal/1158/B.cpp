#include<bits/stdc++.h>
using namespace std;
const int maxn=100010,mod=998244353;
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
int n,k;
int main(){
	n=read();k=read();
	int a=(n-k)/2,cnt=n;
	while(cnt>=a+1){
		FOR(i,1,a) putchar('0');
		putchar('1');
		cnt-=a+1;
	}
	FOR(i,1,cnt) putchar('0');
}
// ZZ AK UOI