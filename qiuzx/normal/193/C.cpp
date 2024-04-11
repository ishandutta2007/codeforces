#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 998244353
#define INF63 1061109567
#define INF127 9187201950435737471
#define UINF 18446744073709551615
#define F first
#define S second
#define ll long long
using namespace std;
ll a,b,c,d,e,f,c1,c2,c3,c4,c5,c6,c7;
string s1,s2,s3,s4;
int main(){
	ll i;
	cin>>a>>b>>c>>d>>e>>f;
	if((e+f-b-a)%2!=0||(d+f-a-c)%2!=0||(c+b-f)%2!=0||(a+c-e)%2!=0||(b+a-d)%2!=0||(e-b+d-c)%2!=0)
	{
		puts("-1");
		return 0;
	}
	c1=(e+f-b-a)/2;
	c2=(d+f-a-c)/2;
	c3=(e-b+d-c)/2;
	c4=(c+b-f)/2;
	c5=(a+c-e)/2;
	c6=(b+a-d)/2;
	for(c7=0;c7<=1000000;c7++)
	{
		if(c1>=0&&c2>=0&&c3>=0&&c4>=0&&c5>=0&&c6>=0)
		{
			break;
		}
		c1++;
		c2++;
		c3++;
		c4--;
		c5--;
		c6--;
	}
	if(c7>1000000)
	{
		puts("-1");
		return 0;
	}
	for(i=0;i<c1;i++)
	{
		s1+='a';
		s2+='a';
		s3+='a';
		s4+='b';
	}
	for(i=0;i<c2;i++)
	{
		s1+='a';
		s2+='a';
		s3+='b';
		s4+='a';
	}
	for(i=0;i<c3;i++)
	{
		s1+='a';
		s2+='b';
		s3+='a';
		s4+='a';
	}
	for(i=0;i<c4;i++)
	{
		s1+='a';
		s2+='a';
		s3+='b';
		s4+='b';
	}
	for(i=0;i<c5;i++)
	{
		s1+='a';
		s2+='b';
		s3+='a';
		s4+='b';
	}
	for(i=0;i<c6;i++)
	{
		s1+='a';
		s2+='b';
		s3+='b';
		s4+='a';
	}
	for(i=0;i<c7;i++)
	{
		s1+='a';
		s2+='b';
		s3+='b';
		s4+='b';
	}
	cout<<(c1+c2+c3+c4+c5+c6+c7)<<endl<<s1<<endl<<s2<<endl<<s3<<endl<<s4<<endl;
	return 0;
}
/*
1	0	0	0	0	0	-1	0.5e+0.5f-0.5b-0.5a
0	1	0	0	0	0	-1	0.5d+0.5f-0.5a-0.5c
0	0	1	0	0	0	-1	0.5e-0.5b+0.5d-0.5c
0	0	0	1	0	0	1	0.5c+0.5b-0.5f
0	0	0	0	1	0	1	0.5a+0.5c-0.5e
0	0	0	0	0	1	1	0.5b+0.5a-0.5d
*/