#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,i,x,tem=0;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>x;
		if(x%2==0)
		{
			tem++;
		}
	}
	cout<<min(tem,n-tem)<<endl;
	return 0;
}