#include <iostream>
using namespace std;
int main()
{
	int t;
	cin>>t;
	int ans[t];
	for (int i=0; i<t; i++){
		int n=0;
		int a,b;
		cin>>a>>b;
		//while (a%b!=0){
		//	a+=1;
		//	n+=1;
		//} 
		if (a%b!=0)
			ans[i]=b-(a%b);
		else
			ans[i] = 0;
	}
	for (int i=0; i<t; i++){
		cout<<ans[i]<<endl;
	}
}