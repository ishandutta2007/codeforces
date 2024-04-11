#include<iostream>
using namespace std;
long long a,b,ans;
void divide(long long a,long long b)
{
	if(!b)return;
	ans+=a/b;
	divide(b,a%b);
}
int main()
{
	cin>>a>>b;
	divide(a,b);
	cout<<ans;
	return 0;
}