#include<bits/stdc++.h>
using namespace std;
const int maxn=155555;
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
inline int read(){
	int x=0,f=0;char ch=getchar();
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
int t,n;
int main(){
	t=read();
	while(t--){
		n=read();
		int ans=0;
		if(n&1){
			if(n<9){puts("-1");continue;}
			if(n==9){puts("1");continue;}
			n-=9;ans++;
		}
		if(n<=3){puts("-1");continue;}
		printf("%d\n",(n>>2)+ans);
	}
}