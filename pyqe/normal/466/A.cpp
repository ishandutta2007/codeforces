#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	long long n,m,a,b,z;
	
	cin>>n>>m>>a>>b;
	z=min(min(n*a,n/m*b+(n%m)*a),((n-1)/m+1)*b);
	cout<<z<<'\n';
}