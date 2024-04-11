#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,k,a[200001],i,sum;
	cin>>n>>k;
	sum=k;
	fill(a,a+200001,1);
	for(i=0;i<k;i++){
		while(sum+a[i]<=n){
			sum+=a[i];
			a[i]*=2;
		}
	}
	if(sum==n){
		cout<<"YES"<<"\n";
		for(i=0;i<k;i++)cout<<a[i]<<" ";
	}else cout<<"NO";
	return 0;
}