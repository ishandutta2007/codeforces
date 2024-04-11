#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,x;
map<long long,int>ma; 
signed main(){
	cin>>T;
	for(int i=1;i<=60;i++){
		ma[(1ll<<i)]=1;
	}
	while(T--){
		
		scanf("%lld",&x);
		if(x%2==1){
			puts("YES");
		}
		else{
			if(ma[x]){
				puts("NO");
			}
			else puts("YES");
		}
	}
	return 0;
}