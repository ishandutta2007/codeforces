#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define x first
#define y second

using namespace std;

typedef long long ll;

const int INF = (int) 1e9;

int pref[10], suf[10], tim[10];

int main()
{
 	//freopen("input.txt", "r", stdin);
 	//freopen("output.txt", "w", stdout);
 	ios_base::sync_with_stdio(0); cin.tie(0);
 	int test;
 	cin >> test;
 	for (int rep = 1; rep <= test; rep++)
 	{
 	 	int k;
 	 	cin >> k;
 	 	for (int i = 1; i <= 7; i++) cin >> tim[i];
 	 	for (int i = 1; i <= 7; i++) pref[i] = pref[i - 1] + tim[i];
 	 	for (int i = 7; i >= 1; i--) suf[i] = suf[i + 1] + tim[i];

 	 	int ans = INF;
 	 	for (int i = 1; i <= 7; i++)
 	 		for (int j = i; j <= 7; j++)
 	 			if (pref[j] - pref[i - 1] == k) ans = min(ans, j - i + 1);
 	 	
 	 	for (int i = 1; i <= 7; i++)
 	 		for (int j = 1; j <= 7; j++)
 	 		{
 	 		 	int rem = k - suf[i] - pref[j];
 	 		 	if (rem >= 0 && rem % pref[7] == 0) ans = min(ans, 8 - i + j + rem / pref[7] * 7);
 	 		}
 	 	cout << ans << '\n';
 	}
 	return 0;
}