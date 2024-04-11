#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 1000007
#define INF63 1061109567
#define INF127 9187201950435737471
#define UINF 18446744073709551615
#define F first
#define S second
#define ll long long
using namespace std;
int main(){
	ll t,a,b,c,d,x,y,x1,x2,y1,y2,mx,ta;
	bool flag1,flag2;
	cin>>t;
	while(t--)
	{
		cin>>a>>b>>c>>d>>x>>y>>x1>>y1>>x2>>y2;
		if(x2-x1==0)
		{
			if(a||b)
			{
				cout<<"No"<<endl;
				continue;
			}
		}
		if(y2-y1==0)
		{
			if(c||d)
			{
				cout<<"No"<<endl;
				continue;
			}
		}
		mx=x2-x1;
		ta=x-x1;
		ta=a-ta;
		if(ta>b||abs(ta-b)>mx)
		{
			flag1=false;
		}
		else
		{
			flag1=true;
		}
		ta=x2-x;
		ta=b-ta;
		if(ta>a||abs(ta-a)>mx)
		{
			flag1|=false;
		}
		else
		{
			flag1=true;
		}
		mx=y2-y1;
		ta=y-y1;
		ta=c-ta;
		if(ta>d||abs(ta-d)>mx)
		{
			flag2=false;
		}
		else
		{
			flag2=true;
		}
		ta=y2-y;
		ta=d-ta;
		if(ta>c||abs(ta-c)>mx)
		{
			flag2|=false;
		}
		else
		{
			flag2=true;
		}
		if(flag1&&flag2)
		{
			cout<<"Yes"<<endl;
		}
		else
		{
			cout<<"No"<<endl;
		}
	}
	return 0;
}