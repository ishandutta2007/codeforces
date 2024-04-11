#include <bits/stdc++.h>
using namespace std;
long long n,a,ans;
long long fact(long long x)
{
	long long i,res=0;
	for(i=1;i*i<=x;i++)
	{
		if(x%i==0)
		{
			if(i*i==x)
			{
				res+=1;
			}
			else
			{
				res+=2;
			}
		}
	}
	return res;
}
int main(){
	long long i;
	cin>>n>>ans;
	for(i=1;i<n;i++)
	{
		cin>>a;
		ans=__gcd(ans,a);
	}
	cout<<fact(ans)<<endl;
	return 0;
}