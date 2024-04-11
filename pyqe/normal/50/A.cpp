#include <iostream>

using namespace std;

int main()
{
	long long m,n;
	
	cin>>m>>n;
	cout<<(m*n-m*n%2)/2<<endl;
}