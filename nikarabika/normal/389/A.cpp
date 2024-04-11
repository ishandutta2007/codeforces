#include <iostream>

using namespace std;

int gcd(int a, int b)
{
	if(b==1) return 1;
	else if(b==0) return a;
	return gcd(b, a%b);
}


int main()
{
	int count, result;
	cin>>count;
	int number[count];
	for(int i=0; i<count; i++)
	{
		cin>>number[i];
	}
	result=number[0];
	for(int i=1; i<count; i++)
	{
		result=gcd(result, number[i]);
	}
	cout<<count*result;
	return 0;
}