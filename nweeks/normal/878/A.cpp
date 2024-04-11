#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())

typedef	long long ll;
const int MAXB = 10;

array<bool,2> f[MAXB];

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int n;
	cin >> n;
	for (int i(0); i < MAXB; ++i)
	{
		f[i][0] = false;
		f[i][1] = true;
	}

	for (int i(0); i < n; ++i)
	{
		char op;
		int arg;
		cin >> op >> arg;
		for (int p(0); p < MAXB; ++p)
		{
			int bit = !!((1<<p)&arg);
			for (int b(0); b < 2; ++b)
			{
				if (op == '|')
					f[p][b] = f[p][b]|bit;
				else if (op == '&')
					f[p][b] = f[p][b] & bit;
				else
					f[p][b] = f[p][b] ^ bit;
			}
		}
	}
	
	cout << 2 << endl;
	cout << "| ";
	int arg(0);
	for (int p(0); p < MAXB; ++p)
		if (f[p][0] == f[p][1])
			arg += (1<<p);
	cout << arg << endl;
	arg=0;
	cout << "^ ";
	for (int p(0); p < MAXB; ++p)
		if (f[p][1] == 0)
			arg += (1<<p);
	cout << arg << endl;
}