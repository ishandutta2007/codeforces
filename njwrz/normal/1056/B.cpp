#include<iostream>
using namespace std;
int main(){
	long long n,m,t=0,i,j,ans,s;
	cin>>n>>m;
	for(i=1;i<=m;i++){
		for(j=1;j<=m;j++){
			t+=((i*i+j*j)%m==0);
		} 
	}
	ans=(n/m)*(n/m)*t;
	t=n%m;s=n/m;
	for(i=1;i<=t;i++){
		for(j=1;j<=m;j++){
			if((i*i+j*j)%m==0){
				ans+=s*2;
			}
		} 
	}
	for(i=1;i<=t;i++){
		for(j=1;j<=t;j++){
			if((i*i+j*j)%m==0)ans++;
		}
	}
	cout<<ans;
	return 0;
}