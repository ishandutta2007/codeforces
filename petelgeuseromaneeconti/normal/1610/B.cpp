#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
const int N=200005;
int T,a[N];
int main(){
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		rep(i,1,n)scanf("%d",&a[i]);
		int l=1,r=n;
		while(l<=r&&a[l]==a[r])++l,--r;
		if(l>r){
			puts("YES");
			continue;
		}
		auto chk=[&](int x){
			l=1,r=n;
			while(1){
				while(l<=r&&a[l]==a[r]){
					++l,--r;
				}
				if(l>r)return 1;
				if(a[l]==x)++l;
				else if(a[r]==x)--r;
				else return 0;
			}
		};
		if(chk(a[l])||chk(a[r])){
			puts("YES");
		}else{
			puts("NO");
		}
	}
	return 0;
}