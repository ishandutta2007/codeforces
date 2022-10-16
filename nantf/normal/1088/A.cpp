#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=100010;
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
int main(){
	int x=read();
	FOR(i,1,x) FOR(j,1,x) if(i*j>x && i%j==0) return printf("%d %d\n",i,j),0;
	puts("-1");
}