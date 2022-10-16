#include <iostream>
using namespace std;
int main()
{
	int a , n;
	cin>>n>>a;
	if(a%2==0)
	{
		a=n+1-a;
	}
	int time = (a+1)/2;
	cout<<time<<endl;
}