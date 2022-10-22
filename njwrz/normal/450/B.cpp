#include <bits/stdc++.h>
using namespace std;
int a[10];
int main(){
	int k;
	cin>>a[1]>>a[2]>>k;
	if(k%6==0){
		k=6;
	}else k=k%6;
	while(a[1]<0)a[1]+=1000000007;
	while(a[2]<0)a[2]+=1000000007;
	for(int i=3;i<=k;i++){
		a[i]=a[i-1]-a[i-2];
		a[i]=a[i]%1000000007;
		while(a[i]<0)a[i]+=1000000007;
	}
	cout<<a[k];
	return 0;
}