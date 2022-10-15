#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
double a,b,c,d,e,f,g,h; int t,t1;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	for (t1=0;t1<t;t1++)
	{
	cin>>a>>b;
	if (b==0) cout<<1;
	else
	if (a==0) cout<<fixed<<setprecision(8)<<double(1)/2;
	else
	if (a>=4*b)
	{
		cout<<fixed<<setprecision(8)<<(a*b*2-(b*b*2))/(a*b*2);
	}
	else
	{
		cout<<fixed<<setprecision(8)<<(a*b+(a*a/8))/(a*b*2);
	}
	cout<<endl;
	}
}