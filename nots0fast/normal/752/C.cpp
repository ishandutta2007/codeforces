#include <iostream>
#include <vector>
#include <math.h>
#include <string>
using namespace std;
typedef long long int lli;
#define for_(z,v) for(int i=z; i<v; i++)
#define for__(z,v) for(int j=z; j<v; j++)
typedef long long int lli;
void inita (int &a, int &b , int &c ,int &d)
{
	a= 0;
	b=a;
	c=a;
	d=a;
}
int main()
{
	int up = 0, right = 0,left = 0,down = 0;
	int n;
	cin>>n;
	string a;
	cin>>a;
	int say = 0;
	for_(0,n)
	{
		if(a[i]=='U')
		{
			if(down>0)
			{
				++say;
				inita(up,right,down,left);
			}
			++up;
		}
		else if(a[i]=='D')
		{
			if(up>0)
			{
				++say;
				inita(up,right,down,left);
			}
			++down;
		}
		else if(a[i]=='R')
		{
			if(left>0)
			{
				++say;
				inita(up,right,down,left);
			}
			++right;
		}
		else if(a[i]=='L')
		{
			if(right>0)
			{
				++say;
				inita(up,right,down,left);
			}
			++left;
		}
	}
	cout<<++say;
}