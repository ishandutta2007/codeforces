#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

short int a[110][110];

int k1[30011] , k2[30011] , k3[30011] , k4[30011] , cnt , k5[30011] , k6[30011]; 
int k[7][30011]; 

int main()
{
	ios::sync_with_stdio(false);
	int t; 
	cin >> t;
	while(t--)
	{
		cnt = 0;
		int n , m;
		cin >> n >> m;
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= m; j++)
			{
				char c;
				cin >> c;
				a[i][j] = c - '0';
			}
		for(int i = 1; i < n - 1 ; i++)
		{
			for(int j = 1; j < m; j++)
				if(a[i][j] == 1)
				{
					++cnt;
					k[1][cnt] = i , k[2][cnt] = j , k[3][cnt] = i , k[4][cnt] = j + 1 , k[5][cnt] = i + 1 , k[6][cnt] = j;
					a[i][j] = !a[i][j];
					a[i][j + 1] = !a[i][j + 1];
					a[i + 1][j] = !a[i + 1][j];
				}
			if(a[i][m] == 1)
			{
				++cnt; 
				k[1][cnt] = i , k[2][cnt] = m , k[3][cnt] = i + 1 , k[4][cnt] = m - 1 , k[5][cnt] = i + 1 , k[6][cnt] = m;
				a[i][m] = !a[i][m];
				a[i + 1][m - 1] = !a[i + 1][m - 1];
				a[i + 1][m] = !a[i + 1][m];
			}
		}
		for(int i = 1; i < m; i++)
			if(a[n - 1][i] || a[n][i])
			{
				if(a[n - 1][i] && a[n][i])
				{
					++cnt;
					a[n - 1][i] = !a[n - 1][i];
					a[n - 1][i + 1] = !a[n - 1][i + 1];
					a[n][i] = !a[n][i];
					k[1][cnt] = n - 1 , k[2][cnt] = i , k[3][cnt] = n - 1 , k[4][cnt] = i + 1 , k[5][cnt] = n , k[6][cnt] = i;
				}
				else if(a[n - 1][i])
				{
					a[n - 1][i] = !a[n - 1][i];
					a[n - 1][i + 1] = !a[n - 1][i + 1];
					a[n][i + 1] = !a[n][i + 1];
					++cnt;
					k[1][cnt] = n - 1 , k[2][cnt] = i , k[3][cnt] = n - 1 , k[4][cnt] = i + 1 , k[5][cnt] = n , k[6][cnt] = i + 1;
				}
				else if(a[n][i])
				{
					a[n][i] = !a[n][i];
					a[n - 1][i + 1] = !a[n - 1][i + 1];
					a[n][i + 1] = !a[n][i + 1];
					++cnt;
					k[1][cnt] = n , k[2][cnt] = i , k[3][cnt] = n - 1 , k[4][cnt] = i + 1 , k[5][cnt] = n , k[6][cnt] = i + 1;
				}
			}
		if(a[n - 1][m] && a[n][m])
		{
			a[n - 1][m] = a[n][m] = 0;
			++cnt;
			k[1][cnt] = n - 1 , k[2][cnt] = m - 1 , k[3][cnt] = n , k[4][cnt] = m - 1 , k[5][cnt] = n , k[6][cnt] = m;
			++cnt;
			k[1][cnt] = n - 1 , k[2][cnt] = m - 1 , k[3][cnt] = n - 1, k[4][cnt] = m , k[5][cnt] = n , k[6][cnt] = m - 1;
		}
		if(a[n - 1][m])
		{
			a[n - 1][m] = 0;
			++cnt;
			k[1][cnt] = n - 1 , k[2][cnt] = m - 1 , k[3][cnt] = n - 1, k[4][cnt] = m , k[5][cnt] = n , k[6][cnt] = m - 1;
			++cnt;
			k[1][cnt] = n - 1 , k[2][cnt] = m - 1 , k[3][cnt] = n - 1 , k[4][cnt] = m , k[5][cnt] = n , k[6][cnt] = m;
			++cnt;
			k[1][cnt] = n - 1 , k[2][cnt] = m , k[3][cnt] = n , k[4][cnt] = m - 1 , k[5][cnt] = n , k[6][cnt] = m;
		}
		if(a[n][m])
		{
			a[n][m] = 0;
			++cnt;
			k[1][cnt] = n - 1 , k[2][cnt] = m - 1 , k[3][cnt] = n , k[4][cnt] = m - 1 , k[5][cnt] = n , k[6][cnt] = m;
			++cnt;
			k[1][cnt] = n - 1 , k[2][cnt] = m - 1 , k[3][cnt] = n - 1 , k[4][cnt] = m , k[5][cnt] = n , k[6][cnt] = m;
			++cnt;
			k[1][cnt] = n - 1 , k[2][cnt] = m , k[3][cnt] = n , k[4][cnt] = m - 1 , k[5][cnt] = n , k[6][cnt] = m;
		}
		cout << cnt << endl;
		for(int i = 1; i <= cnt; i++ , cout << endl)
			for(int j = 1; j <= 6; j++)
				cout << k[j][i] << " ";
	}
	return 0;
}