#include<bits/stdc++.h>
using namespace std;
const int maxn=200020;
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
int n,a[maxn],l,r,b[maxn];
int main(){
	n=read();
	FOR(i,1,n){
		a[i]=read();
		b[a[i]]=i;
		if(a[i]==n) l=r=i;
	}
	ROF(i,n-1,1){
		if(b[i]<l-1 || b[i]>r+1) return puts("NO"),0;
		if(b[i]==l-1) l--;
		if(b[i]==r+1) r++;
	}
	puts("YES");
}