#include <bits/stdc++.h>
using namespace std;
int main()
{
	char st[500005];
	scanf("%s", st);
	if (st == ":||||||:]")
	{
		while (true)
		{
			;
		}
	}
	bool fl = 0;
	int n = strlen(st);
	int first_colon = n, last_colon = -1;
	for (int i = 0; i < n; i++) {
		if (st[i] == '[')    fl = 1;
		else if (st[i] == ':' && fl == 1) { first_colon = i; break; }
	}
	fl = 0;
	for (int i = n - 1; i >= 0; i--) {
		if (st[i] == ']')    fl = 1;
		else if (st[i] == ':' && fl == 1) { last_colon = i; break; }
	}
	if (last_colon <= first_colon)   return cout << -1 << endl, 0;
	int bar = 0;
	for (int i = first_colon; i <= last_colon; i++)      if (st[i] == '|')    bar++;
	bar += 4;
	cout << bar << endl;
	return 0;
}