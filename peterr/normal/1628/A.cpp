#include <bits/stdc++.h>
 
using namespace std;

const int MAXN = 2E5;
vector<int> freq[MAXN + 2];
int a[MAXN];

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
		for (int i = 0; i <= n + 1; i++)
		{
			freq[i].clear();
		}
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		for (int i = n - 1; i >= 0; i--)
		{
			freq[a[i]].push_back(i);
		}
		int ptr = 0;
		int mex = 0;
		while (freq[mex].size())
			mex++;
		vector<int> ans;
		while (ptr < n)
		{
			//cout << "iter " << ptr << " " << mex << "\n";
			ans.push_back(mex);
			if (mex)
			{
				int pos = freq[0].back();
				for (int i = 1; i < mex; i++)
				{
					pos = max(pos, freq[i].back());
				}
				while (ptr <= pos)
				{
					freq[a[ptr]].pop_back();
					if (freq[a[ptr]].empty())
						mex = min(mex, a[ptr]);
					ptr++;
				}
			}
			else
			{
				freq[a[ptr]].pop_back();
				if (freq[a[ptr]].empty())
					mex = min(mex, a[ptr]);
				ptr++;
			}
		}	
		cout << ans.size() << "\n";
		for (int x : ans)
			cout << x << " ";
		cout << "\n";
	}
	return 0;
}