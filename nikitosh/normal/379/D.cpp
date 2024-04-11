#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<set>
#include<map>
#include<cstring>
#include<string>
#include<cstdlib>
#include<ctime>
#include<cassert>

using namespace std;

#define FNAME ""
#define FILE 0

#define pb push_back
#define mp make_pair
#define LL long long
#define ULL unsigned long long
#define LD long double

#ifdef WIN32
	#define I64 "%I64d"
#else
	#define I64 "%lld"
#endif

long long k, x, n, m, boo1, boo2, boo3, boo4, k1, k2, k3, k4, q1, q2, a, b, x1, boo_k1, boo_k2, boo_l1, boo_l2, boo_m1, boo_m2, n1, m1;

int main()
{
	#if (FILE == 1)
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout);
	#endif
	scanf("%I64d%I64d%I64d%I64d", &k, &x, &n, &m);
	boo1 = 1;
	boo2 = 1;
	boo3 = 2;
	boo4 = 2;
	k1 = 1;
	k2 = 0;
	k3 = 0;
	k4 = 1;
    for (long long i = 2; i < k; i++)
	{
		long long s;
		q1 = k1 + k3;
		q2 = k2 + k4;
	    s = boo_m2;
	    boo_m2 = boo_m1 + boo_m2;
	    boo_m1 = s;
	    s = boo_k2;
	    boo_k2 = boo_k1 + boo_k2;
	    boo_k1 = s;
	    s = boo_l2;
	    boo_l2 = boo_l1 + boo_l2;
	    boo_l1 = s;
	    if (boo2 == 1 && boo3 == 2)
	    	boo_m2++;
	    if (boo2 == 2 && boo3 == 1)
	    	boo_l2++;
	    if (boo2 == 2 && boo3 == 2)
	    	boo_k2++;
        swap(boo1, boo3);
        boo2 = boo4;
        k1 = k3;
	    k2 = k4;
		k3 = q1;
		k4 = q2;
	}
	a = k3;
	b = k4;
	//printf("%I64d %I64d %I64d %I64d %I64d\n", a, b, boo_m2, boo_l2, boo_k2);
	for (long long i1 = 0; i1 < 2; i1++)
		for (long long i2 = 0; i2 < 2; i2++)
			for (long long i3 = 0; i3 < 2; i3++)
			{
				x1 = x;
				x1 -= (boo_m2 * i1 + boo_l2 * i2 + boo_k2 * i3);
				if (x1 < 0)
					continue;
				n1 = n;
				m1 = m;
				if (i2)
					n1--;
				if (i1)
					n1--;
				if (i2 | i3)
					m1--;
				if (i1 | i3)
					m1--;
				if (n1 < 0 || m1 < 0)
					continue;
				n1 /= 2;
				m1 /= 2;
                for (long long i = 0; i <= n1; i++)
					for (long long j = 0; j <= m1; j++)
						if (i * a + j * b == x1)
						{
							long long it = 0;
							if (i2) 
							{
								printf("C");
								it++;
							}
							for (long long g = 0; g < i; g++)
							{
								printf("AC");
								it += 2;
							}
							if (i1)
							{
								for (long long g = it + 1; g < n; g++)
									printf("B");
								printf("A");
							}
							else
							{
								for (long long g = it; g < n; g++)
									printf("B");
							}
							puts("");
							it = 0;
							if (i1 | i3) 
							{
								printf("C");
								it++;
							}
							for (long long g = 0; g < j; g++)
							{
								printf("AC");
								it += 2;
							}
							if (i2 | i3)
							{
								for (long long g = it + 1; g < m; g++)
									printf("B");
								printf("A");
							}
							else
							{
								for (long long g = it; g < m; g++)
									printf("B");
							}
							puts("");
							return 0;
						}
			}
	puts("Happy new year!");		
	return 0;
}