#include<bits/stdc++.h>
using namespace std;
int main(){
	int a[3],s[3]={0,1,2};
	cin>>a[0];
	a[1]=a[0]+1;a[2]=a[0]+2;
	a[0]%=4;a[1]%=4;a[2]%=4;
	int i;
	for(i=0;i<3;i++){
		if(a[i]==1){
			cout<<s[i]<<" "<<'A';return 0;
		}
	}
	for(i=0;i<3;i++){
		if(a[i]==3){
			cout<<s[i]<<" "<<'B';return 0;
		}
	}
	for(i=0;i<3;i++){
		if(a[i]==2){
			cout<<s[i]<<" "<<'C';return 0;
		}
	}
	for(i=0;i<3;i++){
		if(a[i]==0){
			cout<<s[i]<<" "<<'D';return 0;
		}
	}
	return 0;
}