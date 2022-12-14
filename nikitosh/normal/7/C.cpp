#include<cstdio>
#include<algorithm>
#include<cmath>

using namespace std;

long long A, B, C, g, x, y;

long long gcd (long long a, long long b, long long & x, long long & y) 
{
	if (a == 0) 
	{
		x = 0; 
		y = 1;
		return b;
	}
	long long x1, y1;
	long long d = gcd (b % a, a, x1, y1);
	x = y1 - (b / a) * x1;
	y = x1;
	return d;
}
int main()
{
	scanf("%I64d%I64d%I64d", &A, &B, &C);
	if (A == 0)
	{
		if (C % B != 0)
		{
			puts("-1");
			return 0;
		}
		printf("0 %I64d\n", -C / B);
		return 0;
	}
	if (B == 0)
	{
		if (C % A != 0)
		{
			puts("-1");
			return 0;
		}
		printf("%I64d 0\n", -C / A);
		return 0;
	}
	if (A < 0 && B < 0)
	{
		A *= -1;
		B *= -1;
		C *= -1;
	}
	if (A < 0 && B > 0)
	{
		A *= -1;
		B *= -1;
		C *= -1;
	}
	g = gcd(A, abs(B), x, y);
	if (C % g != 0)
	{
		puts("-1");
		return 0;
	}
	if (A > 0 && B > 0)
	{
		printf("%I64d %I64d\n", -x * (C / g), -y * (C / g));
		return 0;
	}
	if (A > 0 && B < 0)
	{
		printf("%I64d %I64d\n", -x * (C / g), y * (C / g));		
	}
	return 0;
}