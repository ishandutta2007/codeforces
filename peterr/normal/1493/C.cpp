#include <bits/stdc++.h>

using namespace std;

int freq[26];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        string s;
        cin >> n >> k >> s;
        if (n % k != 0)
        {
            cout << "-1\n";
            continue;
        }
        fill(freq, freq + 26, 0);
        for (char ch : s)
        {
            freq[ch - 'a']++;
        }
        bool same = true;
        int cost = 0;
        for (int i = 0; i < 26; i++)
        {
            if (freq[i] % k != 0)
                same = false;
            cost += (k - freq[i] % k) % k;
        }
        if (same)
        {
            cout << s << "\n";
            continue;
        }
        for (int i = n - 1; i >= 0; i--)
        {
            int key = s[i] - 'a';
            cost -= (k - freq[key] % k) % k;
            freq[key]--;
            cost += (k - freq[key] % k) % k;
            bool found = false;
            for (int j = s[i] - 'a' + 1; j < 26; j++)
            {
                int totalCost = cost + (freq[j] % k ? -1 : k - 1);
                if (totalCost + i >= n)
                    continue;
                freq[j]++;
                found = true;
                cout << s.substr(0, i);
                cout << (char) ('a' + j);
                for (int z = 0; z < n - i - totalCost - 1; z++)
                    cout << 'a';
                for (int z = 0; z < 26; z++)
                {
                    while (freq[z] % k)
                    {
                        freq[z]++;
                        cout << (char) ('a' + z);
                    }
                }
                cout << "\n";
                //cout << "the freq was " << freq[2] << endl;
                break;
            }
            if (found)
                break;
        }
    }
    return 0;
}