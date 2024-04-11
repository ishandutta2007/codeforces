#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#define LL long long
#define mid (l+r>>1)
#define M 400020
using namespace std;
LL read(){
	LL nm=0,fh=1;char cw=getchar();
	for(;!isdigit(cw);cw=getchar()) if(cw=='-') fh=-fh;
	for(;isdigit(cw);cw=getchar()) nm=nm*10+(cw-'0');
	return nm*fh;
}
LL p[M],t1,t2,n,ans,minn,maxn;
void write(LL x){
	if(x<0){putchar('-');return write(-x);}
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	n=read(),n<<=1;
	for(LL i=1;i<=n;i++) p[i]=read();
	sort(p+1,p+n+1),ans=(p[n]-p[1])*(p[n]-p[1]),n>>=1;
	for(LL i=1;i<=n;i++){
		t1=p[i+n-1]-p[i];
		if(i>1) minn=p[1];
		else minn=p[i+n];
		t2=p[n<<1]-minn;
		ans=min(ans,t1*t2);
	}
	write(ans),putchar('\n');
	return 0;
}