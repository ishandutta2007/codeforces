#include<bits/stdc++.h>
#define int long long
using namespace std;

int T;
int gcd(int a,int b)
{
	return b==0?a:gcd(b,a%b);
}

signed main()
{
	cin>>T;
	while(T--)
	{
		int a,b,c;
		cin>>a>>b>>c;
		int kkk=gcd(a,b);
		a/=kkk,b/=kkk;
		if (a<b)
			swap(a,b);
		int k=a/b;
		if (a-b*k>=2)
			k++;
		if (b==1)
			k--;
		if (k<c)
			cout<<"OBEY"<<endl;
		else
			cout<<"REBEL"<<endl;
	}
	return 0;
}