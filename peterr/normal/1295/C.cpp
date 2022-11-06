#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1E5;
int nextOcc[26][MAXN];

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        string s, t;
        cin >> s >> t;
        int n = (int) s.length();
        for (int i = 0; i < 26; i++)
            nextOcc[i][n - 1] = n;
        nextOcc[s[n - 1] - 'a'][n - 1] = n - 1;
        for (int i = n - 2; i >= 0; i--)
        {
            for (int j = 0; j < 26; j++)
                nextOcc[j][i] = nextOcc[j][i + 1];
            nextOcc[s[i] - 'a'][i] = i;
        }
        int ans = 0;
        int ptr = 0;
        bool valid = true;
        while (ptr < (int) t.length())
        {
            int ind = 0;
            if (nextOcc[t[ptr] - 'a'][ind] == n)
            {
                valid = false;
                break;
            }
            while (ptr < (int) t.length() && ind < n && nextOcc[t[ptr] - 'a'][ind] < n)
            {
                ind = nextOcc[t[ptr] - 'a'][ind] + 1;
                ptr++;
            }
            ans++;
        }
        if (valid)
            cout << ans << endl;
        else
            cout << -1 << endl;
    }
    return 0;
}