#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
using LL=long long;
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		LL a,b,x;
		scanf("%lld%lld%lld",&a,&b,&x);
		while(1){
			if(x==a||x==b){
				puts("YES");
				break;
			}
			if(a<b)swap(a,b);
			if(b==0){
				puts("NO");
				break;
			}
			if(x<=a&&a%b==x%b){
				puts("YES");
				break;
			}
			a%=b;
		}
	}
	return 0;
}