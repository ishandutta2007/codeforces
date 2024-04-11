#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=3e5+55;
int T,n;
char a[N];
int b[N];
int f[N][2],s[N][2];
signed main(){
	cin>>T;
	while(T--){
		cin>>n;
		scanf("%s",a+1);
		for(int i=1;i<=n;i++){
			if(a[i]=='L')f[i][0]=f[i-1][1]+1;
			else f[i][1]=f[i-1][0]+1;
		}
		for(int i=n;i>=1;i--){
			if(a[i]=='L')s[i][0]=s[i+1][1]+1;
			else s[i][1]=s[i+1][0]+1; 
		}
		int ans=0;
		for(int i=0;i<=n;i++){
			ans=0;
			ans=f[i][0]+s[i+1][1]+1;
			printf("%lld ",ans);
		}
		for(int i=1;i<=n;i++)s[i][0]=s[i][1]=f[i][0]=f[i][1]=0;
		puts("");
	} 
	return 0;
}