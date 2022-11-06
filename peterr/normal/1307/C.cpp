#include <bits/stdc++.h>

using namespace std;

int freq[26];

int main()
{
    string s;
    cin >> s;
    int n = (int) s.length();
    for (int i = 0; i < n; i++)
    {
        freq[s[i] - 'a']++;
    }
    long long ans = 0;
    for (int i = 0; i < 26; i++)
        ans = max(ans, (long long) freq[i]);
    for (int i = 0; i < 26; i++)
    {
        for (int j = 0; j < 26; j++)
        {
            long long localAns = 0;
            int prev = 0;
            for (int k = 0; k < n; k++)
            {
                if (s[k] - 'a' == j)
                    localAns += prev;
                if (s[k] - 'a' == i)
                    prev++;
            }
            ans = max(ans, localAns);
        }
    }
    cout << ans << endl;
    return 0;
}