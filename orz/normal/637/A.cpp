// A.cpp:   .

//#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <map>

using namespace std;

int main()
{
	int i, n, a, b, c;
	cin >> n;
	map <int, pair <int, int> > m;
	for (i = 0; i < n; ++i)
	{
		cin >> a;
		auto t = m.find(a);
		if (t != m.end())
		{
			b = t->second.first;
			m.erase(t);
			m.insert(pair <int, pair <int, int> >(a, pair <int, int>(b + 1, i)));
		}
		else
		{
			m.insert(pair <int, pair <int, int> >(a, pair <int, int>(1, i)));
		}
	}
	a = -1; b = -1, c = n;
	for (auto t = m.begin(); t != m.end(); ++t)
	{
		if ((t->second.first > b) || ((t->second.first == b) && (t->second.second < c)))
		{
			a = t->first;
			b = t->second.first;
			c = t->second.second;
		}
	}
	cout << a;
	//system("pause");
    return 0;
}