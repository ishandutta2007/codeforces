#include <iostream>
using namespace std;
int main(){
	int n,m=0,bm=0;
	cin>>n;
	for (int i=0; i<n; i++){
		int a,b;
		cin>>a>>b;
		m-=a;
		m+=b;
		if (m>bm){
			bm=m;
		}
	}
	cout<<bm;
}