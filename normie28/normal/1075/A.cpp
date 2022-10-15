#include <iostream>
#include <string>
using namespace std;
int main()
{
	long long x,y,n,w,b;
	cin>>n;cin>>x;cin>>y;
	if (x>y) w=x-1; else w=y-1;
	if (x>y) b=n-y; else b=n-x;
	if (w<=b) cout<<"White"; else cout<<"Black";
}