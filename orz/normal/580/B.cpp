// B.cpp:   .

//#include "stdafx.h"
#include <iostream>
//#include <conio.h>
#include <algorithm>

using namespace std;

struct fr
{
	long long dr, de;
	bool operator <(const fr& y) const
	{
		return (de < y.de);
	}
};
int main()
{
	long long n, d, s, ms, l, r;
	fr f[100000];
	cin >> n >> d;
	for (l = 0; l < n; ++l)
		cin >> (f + l)->de >> (f + l)->dr;
	sort(f, f + n);
	r = 0; s = 0;
	while ((r < n) && (f[r].de - f[0].de < d))
		s += f[r++].dr;
	ms = s;
	l = 0;
	while (r < n)
	{
		s += f[r].dr;
		while (f[r].de - f[l].de >= d)
			s -= f[l++].dr;
		if (s>ms)
			ms = s;
		++r;
	}
	cout << ms;
	//_getch();
    return 0;
}

/*
4 5
75 5
0 100
150 20
75 1
*/