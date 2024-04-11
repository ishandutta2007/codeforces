#include<cstdio>
#include<algorithm>
#include<cmath>

using namespace std;

long long n, m, a, b, A[200000], B[200000], L[200000], p, q, l;
long double d1, d2, d3, min1 = 1000000000;

long double dist (long long x1, long long y1, long long x2, long long y2)
{
	return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%I64d%I64d%I64d%I64d", &n, &m, &a, &b);
	for (int i = 0; i < n; i++)
		scanf("%I64d", &A[i]);
	for (int i = 0; i < m; i++)
		scanf("%I64d", &B[i]);
	for (int i = 0; i < m; i++)
		scanf("%I64d", &L[i]);
	for (int i = 0; i < m; i++)
	{
		l = upper_bound(A, A + n, (a * B[i]) / b) - A;
		//printf("i = %I64d l = %I64d\n", i, l);
		d1 = dist(0, 0, a, A[l]);	
		d2 = dist(a, A[l], b, B[i]);
		d3 = L[i];
		if (d1 + d2 + d3 < min1)
		{
			min1 = d1 + d2 + d3;
			p = l;
			q = i;	
		}
		//printf("%.10lf\n", d1 + d2 + d3);
		if (l >= 1)
		{
			d1 = dist(0, 0, a, A[l - 1]);	
			d2 = dist(a, A[l - 1], b, B[i]);
			d3 = L[i];
			if (d1 + d2 + d3 < min1)
			{
				min1 = d1 + d2 + d3;
				p = l - 1;
				q = i;	
			}
			//printf("%.10lf\n", d1 + d2 + d3);
	  }
	  if (l >= 2)
	  {
		  d1 = dist(0, 0, a, A[l - 2]);	
			d2 = dist(a, A[l - 2], b, B[i]);
			d3 = L[i];
			if (d1 + d2 + d3 < min1)
			{
				min1 = d1 + d2 + d3;
				p = l - 2;
				q = i;	
			}
			//printf("%.10lf\n", d1 + d2 + d3);
	  }
	}
	printf("%I64d %I64d\n", p + 1, q + 1);
	return 0;
}