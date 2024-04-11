// A.cpp:   .

//#include "stdafx.h"
#include <iostream>
//#include <cstdlib>
#include <cstdio>
using namespace std;

int main()
{
	int n, k, q, *t, i, p, d, j, *u;
	cin >> n >> k >> q;
	t = new int[n + 1];
	*t = 0;
	u = new int[k];
	for (i = 1; i <= n; ++i)
		scanf("%d", t + i);
	for (i = 0; i < k; ++i)
		u[i] = 0;
	for (i = 0; i < q; ++i)
	{
		scanf("%d%d", &p, &d);
		if (p == 1)
		{
			for (j = 0; j < k; ++j)
			if (t[d] > t[u[j]])
			{
				p = d;
				d = u[j];
				u[j] = p;
			}
		}
		else
		{
			for (j = 0; j < k; ++j)
			if (u[j] == d)
				p = 0;
			if (p == 0)
				cout << "YES\n";
			else
				cout << "NO\n";
		}
	}
	//system("pause");
    return 0;
}