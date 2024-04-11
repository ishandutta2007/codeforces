#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
const int N=200005;
int T,n,a[N];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		rep(i,1,n)scanf("%d",&a[i]);
		if(a[1]==n){
			reverse(a+1,a+1+n);
			rep(i,1,n)printf("%d%c",a[i],i==n?'\n':' ');
		}else if(a[n]==n){
			reverse(a+1,a+1+n);
			rep(i,1,n)printf("%d%c",a[i],i==n?'\n':' ');
		}else{
			puts("-1");
		}
	}
	return 0;
}