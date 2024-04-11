#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int T,n;
int s[N],f[N];
int read(){
	
}
int main(){
//	freopen("data.in","r",stdin);
	cin>>T;
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d",&s[i]);
		}
		for(int i=1;i<=n;i++){
			scanf("%d",&f[i]);
		}
		cout<<f[1]-s[1]<<" ";
		for(int i=2;i<=n;i++){
			if(s[i]>f[i-1]){
				cout<<f[i]-s[i]<<" ";
			}
			else{
				cout<<f[i]-f[i-1]<<" ";
			}
		}
		cout<<'\n';
	}
	return 0;
}