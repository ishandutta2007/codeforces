#include <bits/stdc++.h>
using namespace std;
 
const int N = 5005;
 
int n, ans[N], f[N][N];
char s[N];
 
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    scanf("%s",s+1);
    n = strlen(s+1);
    for (int len = 1; len <= n; len++)
        for (int i = 1; i <= n + 1 - len; i++)
        {
            int j = i + len - 1;
            if (s[i] == s[j] && (len <= 2 || f[i + 1][j - 1] > 0))
                ans[f[i][j] = f[i][i + len / 2 - 1] + 1]++;
        }
    for (int i = n - 1; i >= 1; i--)
        ans[i] += ans[i + 1];
    for (int i = 1; i <= n; i++)
        cout<<ans[i]<<' ';
}