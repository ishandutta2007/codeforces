#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
	return x*f;
}
int n,q,b[35],c[35];
int main(){
	n=read(), q=read();
	for(int i=1,x;i<=n;++i)
		++b[31-__builtin_clz(read())];
	for(int j=0;j<=30;++j) c[j]=b[j];
	for(int i=1;i<=q;++i){
		int A=0,x=read();
		for(int j=0;j<=30;++j) b[j]=c[j];
		int j=30;
		while(~j) A+=min(b[j],x>>j), x-=min(b[j],x>>j)<<j, --j;
		if(!x) printf("%d\n",A);
		else puts("-1");
	}
}