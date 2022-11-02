#include <iostream>
using namespace std;
int main(){
	int a,b,c;
	cin>>a>>b>>c;
	if (a>=b and a>=c){
		if (a-b-c<0){
			cout<<0;
			return 0;
		}
		else{
			cout<<a-b-c+1;
			return 0;
		}
	}
	if ((b>=a and b>=c) or (b==c)){
		if (b-a-c<0){
			cout<<0;
			return 0;
		}
		else{
			cout<<b-a-c+1;
			return 0;
		}
	}
	if (c>=a and c>=b){
		if (c-a-b<0){
			cout<<0;
			return 0;
		}
		else{
			cout<<c-a-b+1;
			return 0;
		}
	}
}