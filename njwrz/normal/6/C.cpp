#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,a[100001],i,l,r,l1,r1;
	cin>>n;
	for(i=0;i<n;i++)cin>>a[i];
	l=0;r=n-1;l1=0;r1=0;
	for(i=0;i<n;i++){
		if(r1<l1){
			r1+=a[r];r--;
		}else{
			l1+=a[l];l++;
		}
	}
	cout<<l<<" "<<n-r-1; 
	return 0;
}