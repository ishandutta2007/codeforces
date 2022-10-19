#include<bits/stdc++.h>
using namespace std;

int t,a,b,c;
int main(){
	cin>>t;
	while (t--){
		cin>>a>>b>>c;
		if (2*b<=c){
			cout<<3*b<<endl;
		}
		else{
			b-=c/2;
			if (2*a<=b){
				cout<<3*a+c/2*3<<endl;
			}
			else{
				cout<<b/2*3+c/2*3<<endl;
			}
		}
	}
}