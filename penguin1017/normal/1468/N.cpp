#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
using namespace std;
const int N=1e5+9;
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int c[4],a[6];
		rep(i,1,4)scanf("%d",&c[i]);
		rep(i,1,6)scanf("%d",&a[i]);
		int ok=0;
		rep(i,1,4)if(c[i]<a[i])ok=1;
		else c[i]-=a[i];
		if(ok){
			puts("NO");
			continue;
		}
		int sum=a[4]-min(a[4],c[1])+a[5]-min(a[5],c[2]);
		if(sum<=c[3])puts("YES");
		else puts("NO"); 
	}
}