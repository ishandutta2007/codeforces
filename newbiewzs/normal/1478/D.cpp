#include<bits/stdc++.h>
#define int long long
using namespace std;
int T;
const int N=2e5+5;
int a[N],n,m;
int gcd(int x,int y){
	if(!y)return x;
	else return gcd(y,x%y);
}
signed main(){
	cin>>T;
	while(T--){
		scanf("%lld%lld",&n,&m);
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
		}
		sort(a+1,a+n+1);
		int G=0;
		bool flag=0;
		for(int i=2;i<=n;i++){
			G=gcd(G,a[i]-a[i-1]);
			if((m-a[i])%G==0 or (m-a[i-1])%G==0){
				flag=1;
				puts("YES");
				break;
			}
		}
		if(!flag)puts("NO");
	}
	return 0;
} 
/*
1
4
40 56 48 40 80 56 80 48
*/