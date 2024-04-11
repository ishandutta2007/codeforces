#include <iostream>
#include <algorithm>
using namespace std;
int n,m,a,b;
int main()
{
	cin>>n>>m>>a>>b;
	int t=n/m;
	cout<<min(min(t*b+(n%m)*a,(t+1)*b),n*a);
	return 0;
}