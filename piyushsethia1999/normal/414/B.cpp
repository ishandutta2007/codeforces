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
	#endif
	ll n, k;
	cin >> n >> k;
	ll A[n+1][k+1] = {{0}};
	for (int i = 0; i <= n; ++i)
	{
		A[i][1] = 1;
	}
	for (int i = 2; i <= k; ++i)
	{
		for (int j = n; j >= 1; --j)
		{
			for (int k = j; k <= n; k += j)
			{
				A[j][i] = (A[j][i] + A[k][i-1]) % 1000000007;
			}
		}
	}
	// for (int i = 1; i <= n; ++i)
	// {
	// 	for (int j = 1; j <= k; ++j)
	// 	{
	// 		cout<<A[i][j]<<" ";
	// 	}
	// 	cout<<"\n";
	// }
	A[0][k] = 0;
	for (int i = 1; i <= n ; ++i)
	{
		A[0][k] = (A[0][k] + A[i][k])%1000000007;
	}
	cout<<A[0][k];
}