#include <iostream>
#include <string>
#include <cmath>
using namespace std; 
int main()
{
	int64_t n,m,i,j,x,y,z,mm,count,sen,a[100001];
	float r;
	string s;
	char c;
	count=0;
	cin>>n;
	for (i=1;i<=n;i++)
{
	sen=1;
	cin>>x;
	y=0;
	while(x>0){ z=pow(10,(sen-1)*2);  z%=998244353;
	y+=(x%10)*11*z;  y%=998244353;
	x/=10;
	sen++;
}
//	cout<<y<<endl;
	y*=n; y%=998244353;
	count+=y; count%=998244353;
}
	cout<<count;
}