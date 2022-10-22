#include<bits/stdc++.h>
using namespace std;
long long fj(long long n,long long i){
	if(n==0)return 0;
	return n/i+fj(n/i,i); 
}
int main(){
	long long n,m,i,ans=1000000000000000000,l,j;
	cin>>n>>m;
	for(i=2;i*i<=m;i++){
		if(m%i==0){
			l=0;
			while(m%i==0){
				l++;m/=i;
			}
			ans=min(ans,fj(n,i)/l);
		}
	}
	if(m!=1){
		ans=min(ans,fj(n,m));
	}
	cout<<ans;
	return 0;
}