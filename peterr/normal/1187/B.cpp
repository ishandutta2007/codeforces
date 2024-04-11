#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2 * 1E5;
int occ[MAXN][26];
int freq[26];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    string s;
    cin >> n >> s >> m;
    for (int i = 0; i < n; i++)
    {
        char c = s[i];
        int num = freq[c - 'a'] + 1;
        occ[num][c - 'a'] = i;
        freq[c - 'a']++;
    }
    while (m--)
    {
        fill(freq, freq + 26, 0);
        string t;
        cin >> t;
        int ans = 0;
        for (int i = 0; i < t.length(); i++)
        {
            int key = t[i] - 'a';
            ans = max(ans, occ[freq[key] + 1][key]);
            freq[key]++;
        }
        cout << (ans + 1) << endl;
    }
    return 0;
}