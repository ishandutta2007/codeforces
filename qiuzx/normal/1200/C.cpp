#include <bits/stdc++.h>
using namespace std;
long long n,m,q,a1,b1,a2,b2,p1,p2,x;
int main(){
	cin>>n>>m>>q;
	x=__gcd(n,m);
	p1=n/x;
	p2=m/x;
	while(q--)
	{
		cin>>a1>>b1>>a2>>b2;
		b1--;
		b2--;
		if(a1==1)
		{
			b1/=p1;
		}
		else
		{
			b1/=p2;
		}
		if(a2==1)
		{
			b2/=p1;
		}
		else
		{
			b2/=p2;
		}
		if(b1==b2)
		{
			cout<<"YES"<<endl;
		}
		else
		{
			cout<<"NO"<<endl;
		}
	}
	return 0;
}