#include <bits/stdc++.h>
using namespace std;
int main(){
	int i,m,n,j,t,l;
	int a[25]={1,1,1,5,1,21,1,85,73,341,89,1365,1,5461,4681,21845,
	1,87381,1,349525,299593,1398101,178481,5592405,1082401};
	cin>>m;
	for(i=0;i<m;i++){
		cin>>n;
		t=1;l=-1;
		while(t-1<n){
			t*=2;l++;
		}
		if(t!=n+1){
			cout<<t-1;
		} else{
			cout<<a[l];
		}
		cout<<endl;
	} 
	return 0;
}