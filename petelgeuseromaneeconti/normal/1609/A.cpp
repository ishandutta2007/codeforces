#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
using LL=long long;
template<typename T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<typename T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
const int N=1000005;
int T,n;
LL a[N];
int main(){
	rd(T);
	while(T--){
		rd(n);
		LL pw=1;
		rep(i,1,n){
			rd(a[i]);
			while(a[i]%2==0){
				a[i]/=2;
				pw*=2;
			}
		}
		*max_element(a+1,a+1+n)*=pw;
		LL ans=0;
		rep(i,1,n)ans+=a[i];
		pt(ans,'\n');
	}
	return 0;
}