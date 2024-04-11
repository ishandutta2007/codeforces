#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int main()
{
	long long n,m,i,j,x,y,z,max,count,sen,a[101];
	char c;
	string s;
	cin>>n>>m;
	count=0;max=0;
	for (i=1;i<=n;i++) {cin>>a[i]; count+=a[i]; if (a[i]>max) max=a[i];}
	sen=max*n;
	while (sen<(count+m)) sen+=n;
	cout<<sen/n<<' '<<max+m;
}