#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int t , n , k;
int cnt1[28] , cnt2[28];

int main()
{
	ios::sync_with_stdio(false); 
	cin >> t;
	while(t--)
	{
		cin >> n >> k;
		memset(cnt1 , 0 , sizeof cnt1);
		memset(cnt2 , 0 , sizeof cnt2);
		for(int i = 1; i <= n; i++)
		{
			char c;
			cin >> c;
			cnt1[int(c - 'a')]++;
		}
		for(int i = 1; i <= n; i++)
		{
			char c;
			cin >> c;
			cnt2[int(c - 'a')]++;
		}
		int flag = true;
		for(int i = 0; i < 26; i++)
		{
			if(cnt1[i] < cnt2[i])
			{
				flag = false;
				break;
			}
			else if(cnt1[i] > cnt2[i])
			{
				if((cnt1[i] - cnt2[i]) % k != 0)
				{
					flag = false;
					break;
				}
				else
					cnt1[i + 1] += cnt1[i] - cnt2[i];
			}
		}
		if(cnt1[26]>0)
			flag = false;
		if(flag)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}