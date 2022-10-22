#include <bits/stdc++.h>
using namespace std;
int vis[2000005];
int main(){
	vis[1]=1;
	for(int i=2;i<=2000000;i++){
		if(!vis[i]){
			for(int j=i*2;j<=2000000;j+=i){
				vis[j]=1;
			}
		}
	}
	long long n,x,t;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>x;
		t=sqrt(x);
		if(!vis[t]&&t*t==x){
			cout<<"YES\n";
		}else cout<<"NO\n";
	}
	return 0;
}