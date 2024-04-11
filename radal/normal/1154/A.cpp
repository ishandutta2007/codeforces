#include <iostream>
#include <algorithm>
using namespace std;
int main(){
	string aa;
	long long int a=0,b=0,c=0,d=0;
	for (int i=0; i<4; i++){
		int s;
		cin>>s;
		if (s>a){
			d=c;
			c=b;
			b=a;
			a=s;
		}
		else{
			if (s>b){
				d=c;
				c=b;
				b=s;
			}
			else{
				if (s>c){
					d=c;
					c=s;
				}
				else{
					d=s;
				}
			}
		}
	}
	cout<<a-b<<' '<<a-c<<' '<<a-d;
	
}