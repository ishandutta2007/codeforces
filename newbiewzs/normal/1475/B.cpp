#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,x;
int f[5555555];
signed main(){
	cin>>T;
	for(int i=0;i*2020<=1555555;i++){
		for(int k=0;k*2021+i*2020<=1555555;k++){
			f[i*2020+k*2021]=1;
		}
	}
	while(T--){
		
		scanf("%lld",&x);
		if(f[x]){
			puts("YES");
		}
		else{
			puts("NO");
		}
	}
	return 0;
}