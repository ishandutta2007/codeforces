#include<bits/stdc++.h>
using namespace std;

int x,y,z;
inline char calc()
{
	int a=x-y+z,b=x-y-z;
	if (a>0&&b>0) return '+';
	if (a<0&&b<0) return '-';
	if (a==0&&b==0) return '0';
	return '?';
}

int main()
{
	scanf("%d%d%d",&x,&y,&z);
	putchar(calc());

    return 0;
}