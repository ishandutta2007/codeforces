#include<iostream>
using namespace std;
int main(){
	int n,i,t=0,x[100001];
	double a[100001];
	cin>>n;
	for(i=0;i<n;i++){
		cin>>a[i];x[i]=int(a[i]);t+=x[i];
	} 
	for(i=0;i<n;i++){
		if(a[i]>0&&1.0*x[i]!=a[i]&&t<0){
			t++;
			cout<< x[i]+1;
		}else if(a[i]<0&&1.0*x[i]!=a[i]&&t>0){
			t--;
			cout<< x[i]-1;
		}else cout<<x[i];
		cout<<endl;
	} 
	return 0;
}