#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair

using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
	#ifdef PIYUSH_AASHIRWAAD
		I_O;
	#else
	#define print(...) 0
	#endif
	int n, m;
	cin >> n >> m;
	if(n*m == 2)
	{
		cout << 0 << "\n";
		cout << "1 1\n";
		cout << n << " " << m << "\n";
		cout << "1 1\n";
	}
	else if(n == 1) {
		cout << 1 << "\n";
		cout << 1 << " " << m << " " << 1 << " " << 1 << "\n";
		for (int i = 1; i <= m; ++i)
			cout << 1 << " " << i << "\n";
		cout << 1 << " " << 1;
	}
	else if(m == 1)
	{
		cout << 1 << "\n";
		cout << n << " " << 1 << " " << 1 << " " << 1 << "\n";
		for (int i = 1; i <= n; ++i)
			cout << i << " " << 1 << "\n";
		cout << 1 << " " << 1;
	}
	else if((n & 1) == 0)
	{
		cout << 0 << "\n";
		cout << "1 1\n";
		for (int i = 1; i <= n ; ++i)
		{
			if(i & 1)
				for (int j = 2; j <= m; ++j)
					cout << i << " " << j << "\n";
			else
				for (int j = m; j >= 2; --j)
					cout << i << " " << j << "\n";
		}
		for (int j = n; j >= 1 ; --j)
			cout << j << " " << 1 << "\n";
	}
	else if((m & 1) == 0)
	{
		cout << 0 << "\n";
		cout << "1 1\n";
		for (int i = 1; i <= m ; ++i)
		{
			if(i & 1)
				for (int j = 2; j <= n; ++j)
					cout << j << " " << i << "\n";
			else
				for (int j = n; j >= 2; --j)
					cout << j << " " << i << "\n";
		}
		for (int j = m; j >= 1 ; --j)
			cout << 1 << " " << j << "\n";
	}
	else
	{
		cout << 1 << "\n";
		cout << n << " " << m << " 1 "<< m << "\n";
		cout << "1 1\n";
		for (int i = 1; i <= m ; ++i)
		{
			if(i & 1)
				for (int j = 2; j <= n; ++j)
					cout << j << " " << i << "\n";
			else
				for (int j = n; j >= 2; --j)
					cout << j << " " << i << "\n";
		}
		for (int j = m; j >= 1 ; --j)
			cout << 1 << " " << j << "\n";
	}
}