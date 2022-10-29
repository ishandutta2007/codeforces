#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
using namespace std;
const int N=1e5+9;
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int a[4];
		rep(i,0,4)scanf("%d",&a[i]);
		sort(a,a+4);
		printf("%lld\n",1ll*a[0]*a[2]);
	}
}