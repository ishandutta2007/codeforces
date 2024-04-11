#include <bits/stdc++.h>
using namespace std;
void voi(){
	string a,b;
	cin>>a>>b;
	int ans=0,t;
	for(int i=b.size()-1;i>=0;i--){
		if(b[i]=='1'){
			t=b.size()-i;break;
		}
	}
	for(int i=a.size()-t;i>=0;i--){
		if(a[i]=='1'){
			cout<<a.size()-i-t<<'\n';return ;
		}
	}
}
int main(){
	int n,i;
	cin>>n;
	for(i=0;i<n;i++)voi();
	return 0;
}