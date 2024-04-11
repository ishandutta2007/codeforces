#include<bits/stdc++.h>
using namespace std;
const int maxn=200020,mod=998244353;
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
int main(){
	n=read();
	FOR(i,1,n) a[i]=read();
	sort(a+1,a+n+1);
	int cur=1;
	FOR(i,1,n){
		while(cur<=n && a[cur]<i) cur++;
		if(cur>n) return printf("%d\n",i-1),0;
		cur++;
	}
	printf("%d\n",n);
}