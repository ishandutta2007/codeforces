#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int main()
{
	long long n,m,i,j,x,y,z,mm,count,sen;
	char c;
	string s;
	cin>>n;
	count=0;
	for (i=1;i<=n;i++) {cin>>c; if (c=='8') count++;}
	if (count<=(n/11)) cout<<count; else cout<<n/11;
}