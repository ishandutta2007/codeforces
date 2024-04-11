#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
using namespace std;

long long occ1[1000000],occ2[1000000];

int slow(long long h1,long long a1,long long x1,long long y1,long long h2,long long a2,long long x2,long long y2,long long M)
{
	int a = h1;
	int b = h2;
	for(int t=1;t<=M*M;t++)
	{
		a = (x1*a+y1)%M;
		b = (x2*b+y2)%M;
		if((a==a1)&&(b==a2))
			return t;
	}
	return -1;
}

int main()
{
	long long h1,a1,x1,y1,h2,a2,x2,y2;
	long long M;
	cin >> M >> h1 >> a1 >> x1 >> y1 >> h2 >> a2 >> x2 >> y2;
//	cout << slow(h1,a1,x1,y1,h2,a2,x2,y2,M) << endl;
	long long c = h1;
	bool seen = 0;
	long long s11 = 0;
	long long s12 = 0;
	int i;
	for(i=1;i<=M;i++)
	{
		c = (x1*c + y1)%M;
		if(c == a1)
		{
			s11 = i;
			break;
		}
	}
	if(c != a1)
	{
		cout << -1 << endl;
		return 0;
	}
	for(i++;i<=2*M+5;i++)
	{
		c = (x1*c + y1)%M;
		if(c == a1)
		{
			s12 = i;
			break;
		}
	}
	c = h2;
	long long s21 = 0;
	long long s22 = 0;
	for(i=1;i<=M;i++)
	{
		c = (x2*c + y2)%M;
		if(c == a2)
		{
			s21 = i;
			break;
		}
	}
	if(c != a2)
	{
		cout << -1 << endl;
		return 0;
	}
	for(i++;i<=2*M+5;i++)
	{
		c = (x2*c + y2)%M;
		if(c == a2)
		{
			s22 = i;
			break;
		}
	}

	if((s11==s21)||(s11==s22))
	{
		cout << s11 << endl;
		return 0;
	}
	if(s21==s12)
	{
		cout << s21 << endl;
		return 0;
	}
	if((s12==0)||(s22==0))
	{
		cout << -1 << endl;
		return 0;
	}

	for(int t=0;t<=M;t++)
	{
		if((s11+(s12-s11)*t)%(s22-s21) == s21%(s22-s21))
		{
			if((s11+(s12-s11)*t) >= s21)
			{
				cout << s11+(s12-s11)*t << endl;
				return 0;
			}
		}
	}
	cout << -1 << endl;
	return 0;
}