#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int t;
int rmqi[200010][23] , rmqa[200010][23];
int n;
int a[200010];
int b[200010];

int main()
{
	ios::sync_with_stdio(false);
	cin >> t;
	while(t--)
	{
		cin >> n;
		for(int i = 1; i <= n; i++)
		{
			cin >> a[i];
			rmqi[i][0] = a[i];
		}
		for(int i = 1; i <= n; i++)
			b[i] = a[n - i + 1];
		for(int i = 1; i <= n; i++)
			rmqa[i][0] = b[i];
		for(int j = 1; (1 << j) <= n; j++)
			for(int i = 1; i + (1 << j) - 1 <= n; i++)
				rmqi[i][j] = min(rmqi[i][j - 1] , rmqi[i + (1 << j - 1)][j - 1]);
		for(int j = 1; (1 << j) <= n; j++)
			for(int i = 1; i + (1 << j) - 1 <= n; i++)
				rmqa[i][j] = max(rmqa[i][j - 1] , rmqa[i + (1 << j - 1)][j - 1]);
		int ttt = 0;
		for(int i = 0; i <= 20; i++)
			if((1 << i) <= n)
				ttt = i;
		int max1 = 0;
		int x = -1 , y , z;
		for(int i = 1; i <= n - 2; i++)
		{
			max1 = max(max1 , a[i]);
			int s1 = i + 1 , minn = 0x3f3f3f3f;
			for(int j = ttt; j >= 0; j--)
				if((1 << j) + s1 - 1 <= n && min(minn , rmqi[s1][j]) >= max1)
				{
					minn = min(minn , rmqi[s1][j]);
					s1 += (1 << j);
				}
			int s2 = i + 1;
			minn = 0x3f3f3f3f;
			for(int j = ttt; j >= 0; j--)
				if((1 << j) + s2 - 1 <= n && min(minn , rmqi[s2][j]) > max1)
				{
					minn = min(minn , rmqi[s2][j]);
					s2 += (1 << j);
				}
			int s3 = 1 , maxn = 0;
			for(int j = ttt; j >= 0; j--)
				if((1 << j) + s3 - 1 <= n && max(maxn , rmqa[s3][j]) <= max1)
				{
					maxn = max(maxn , rmqa[s3][j]);
					s3 += (1 << j);
				}
			int s4 = 1;
			maxn = 0;
			for(int j = ttt; j >= 0; j--)
				if((1 << j) + s4 - 1 <= n && max(maxn , rmqa[s4][j]) < max1)
				{
					maxn = max(maxn , rmqa[s4][j]);
					s4 += (1 << j);
				}
			s1--;
			s3--;
			s3 = n - s3 + 1;
			s4 = n - s4 + 1;
			s3 = max(s3 , i + 1); 
			if(s2 > s1)
				continue;
			if(s3 > s4)
				continue;
			if(s2 == s1)
			{
				if(s3 <= s2 + 1 && s2 + 1 <= s4)
				{
					x = i;
					y = s2 - i;
					z = n - y - x;
					break; 
				}
				continue;
			}
			if(s3 == s4)
			{
				if(s2 <= s3 - 1 && s3 - 1 <= s1)
				{
					x = i;
					z = n - s3 + 1;
					y = n - x - z;
					break;
				}
				continue;
			}
			if(s2 <= s3 && s4 <= s1)
			{
				x = i;
				y = s3 - i;
				z = n - x - y;
				break;
			}
			if(s3 <= s2 && s1 <= s4)
			{
				x = i;
				y = s2 - i;
				z = n - x - y;
				break;
			}
			if(s3 < s1)
			{
				x = i;
				y = s3 - i;
				z = n - x - y;
				break;
			}
			if(s1 + 1 == s3 || s1 == s3)
			{
				x = i;
				y = s1 - i;
				z = n - x - y;
				break;
			}
		}
		if(x == -1)
			cout << "NO" << endl;
		else
		{
			cout << "YES" << endl;
			cout << x << " " << y << " " << z << endl;
		}
	}
	return 0;
}