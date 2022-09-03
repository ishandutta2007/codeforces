#include <iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	for(int k=-n/2;k<=n/2;k++)
	{
		int i;
		if(k<0)i=-k;else i=k;
		for(int j=1;j<=i;j++)cout<<"*";
		for(int j=i+1;j<n-i+1;j++)cout<<"D";
		for(int j=1;j<=i;j++)cout<<"*";
		cout<<endl;
	}
	return 0;
}