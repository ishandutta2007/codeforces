#include <iostream>
using namespace std;
int main()
{
 	int minn=100000000;
 	int num[105];
 	int n;
 	cin>>n;
 	for(int i=0;i<n;i++)cin>>num[i];
 	for(int i=0;i<n;i++)
 	{
	 		int nn=num[i]*15;
	 		for(int j=1;j<=num[i];j++){int x;cin>>x;nn+=5*x;}
	 		if(minn>nn)minn=nn;
	 }
	 cout<<minn;
	 return 0;
}