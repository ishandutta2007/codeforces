#include<iostream>
using namespace std;
int main(){
	int n,i;
	string x;
	cin>>n>>x;
	int s=0;
	for(i=0;i<n;i++){
		if(x[i]=='1'){
			s++;
		}else s--;
	}
	if(s==0){
		cout<<2<<endl;
		cout<<x[0]<<" "<<x.substr(1,n-1);
	}else{
		cout<<1<<endl<<x; 
	}
	return 0;
}