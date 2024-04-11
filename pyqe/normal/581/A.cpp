#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
	long long a,b;
	
	cin>>a>>b;
	cout<<min(a,b)<<" "<<abs(a-b)/2<<endl;
}