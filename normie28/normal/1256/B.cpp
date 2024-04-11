#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,i,x,j;
		cin>>n;
		int a[n],swp[n]={0};
		for(i=0;i<n;i++)
		cin>>a[i];
		for(i=n-2;i>=0;i--){
			for(j=i;j<n-1;j++){
				if(a[j]>a[j+1] && swp[j]==0){
					swap(a[j],a[j+1]);
					swp[j]=1;
				}
			}
		}
		for(i=0;i<n;i++)
		cout<<a[i]<<" ";
		cout<<"\n";
	}
	return 0;
}