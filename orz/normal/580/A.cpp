// A.cpp:   .

//#include "stdafx.h"
#include <iostream>
//#include <conio.h>

using namespace std;

int main()
{
	long long n, i, j, m, o;
	cin >> n;
	long long *a;
	a = new long long[n];
	for (i = 0; i < n; ++i)
		cin >> a[i];
	o = 1;
	m = 0;
	for (i = 1; i < n; ++i)
	{
		if (a[i] >= a[i - 1])
			++o;
		else
		{
			if (m < o)
				m = o;
			o = 1;
		}
	}
	if (m < o)
		m = o;
	cout << m;
	//_getch();
    return 0;
}