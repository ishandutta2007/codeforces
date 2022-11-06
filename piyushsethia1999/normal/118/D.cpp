#include<bits/stdc++.h>
#define ll long long int
#define ul unsigned long long int
#define pb push_back
#define mp make_pair
#define ii pair<int,int>
#define vi vector<int>
#define iii pair<int,pair<int,int>>
#define mod 100000000

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	/*#ifndef ONLINE_JUDGE
	freopen("/home/piyush/Documents/input.txt", "r", stdin);
	freopen("/home/piyush/Documents/output.txt", "w", stdout);
	#endif/**/
	ll n1, n2, k2, k1;
	cin >> n1 >> n2 >> k1 >> k2;
	ll A[n1+1][n2+1][3] = {0};
	ll till1, till2;
	cin >> n1 >> n2 >> k1 >> k2;
	for (int i = 0; i <= n1; ++i)
	{
		for (int j = 0; j <= n2; ++j)
		{
			A[i][j][1] = 0;
			A[i][j][2] = 0;
		}
	}
	A[0][0][1] = 1;
	A[0][0][2] = 1;
	for (ll i = 0; i <= n1; ++i)
	{
		for (ll j = 0; j <= n2; ++j)
		{
			till1 = min(k1, i);
			till2 = min(k2, j);
			for (ll k = 1; k <= till1; ++k)
			{
				A[i][j][2] = (A[i][j][2] + A[i-k][j][1])%mod;
			}
			for (ll k = 1; k <= till2; ++k)
			{
				A[i][j][1] = (A[i][j][1] + A[i][j-k][2])%mod;
			}
		}
	}
	cout<<(A[n1][n2][1]+A[n1][n2][2])%mod;
}