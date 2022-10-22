#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
template<typename T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<typename T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
const int N=1000005;
int T,n,a[N];
int calc(int r,int b){
	return (r>>(b+1)<<b)+(r>>b&1?(r&((1<<b)-1))+1:0);
}
int main(){
	rd(T);
	while(T--){
		int l,r;
		scanf("%d%d",&l,&r);
		int ans=0;
		per(i,30,0){
			ans=max(ans,calc(r,i)-calc(l-1,i));
		}
		printf("%d\n",r-l+1-ans);
	}
	return 0;
}