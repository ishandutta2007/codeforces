#include<bits/stdc++.h>
using namespace std;
int T,a,b;
int main(){
	cin>>T;
	while(T--){
		cin>>a>>b;
		int mb=b;
		if(a>b)mb=ceil(1.0*a/b)*b;
		int g=ceil(1.0*mb/a);
		cout<<g<<endl;
	} 
	return 0;
}