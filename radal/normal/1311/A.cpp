#include <iostream>
using namespace std;
int main()
{
	int t;
	cin>>t;
	int ans[t];
	for (int i=0; i<t; i++){
		int a,b;
		cin>>a>>b;
		if (a == b){
			ans[i]=0;
		}
		if ((a > b && a%2 == b%2) || (a < b && a%2 != b%2)){
			ans[i] = 1;
		}
		if (not((a > b && a%2 == b%2) || (a < b && a%2 != b%2)) and a!=b){
			ans[i] = 2;
		}
	}
	for (int i=0; i<t; i++){
		cout<<ans[i]<<endl;
	}
	
}