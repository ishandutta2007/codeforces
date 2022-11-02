#include<bits/stdc++.h>
using namespace std;
int T,n,a[105];
int f[250];
int main(){
	cin>>T;
	while(T--){
		scanf("%d",&n);
		memset(f,0,sizeof(f));
		f[0]=1;
		int S=0;
		for(int i=1;i<=n;i++)scanf("%d",&a[i]),S+=a[i];
		for(int i=1;i<=n;i++){
			for(int k=200;k>=a[i];k--){
				f[k]|=f[k-a[i]];
			}
		}
		if(S%2==1){
			puts("NO");
		}
		else{
			if(f[S/2])puts("YES");
			else puts("NO");
		}
	}
	return 0;
}