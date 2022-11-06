#include <bits/stdc++.h>
 
using namespace std;

const int MAXN = 2E5;
int a[MAXN];
int b[MAXN];
int freq[MAXN + 1];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		for (int i = 0; i < n; i++)
		{
			cin >> b[i];
		}
		bool ans = true;
		int ptr1 = n - 1;
		int ptr2 = n - 1;
		fill(freq + 1, freq + n + 1, 0);
		while (ptr2 >= 0)
		{
			//cout << ptr2 << endl;
			int cur = b[ptr2];
			int len = 0;
			while (ptr2 >= 0 && b[ptr2] == cur)
			{
				len++;
				ptr2--;
			}
			while (a[ptr1] != cur && freq[a[ptr1]])
			{
				freq[a[ptr1]]--;
				ptr1--;
			}
			if (a[ptr1] != cur)
			{
				ans = false;
				break;
			}
			freq[cur] += len;
		}
		cout << (ans ? "YES" : "NO") << "\n";
	}
	return 0;
}