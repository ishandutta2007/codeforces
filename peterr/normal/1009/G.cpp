#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1E5;
const int MAXC = 6;
int freq[MAXC];
int bal[1 << MAXC];
int bits[MAXN];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    int m;
    cin >> s >> m;
    int n = (int) s.length();
    for (char ch : s)
    {
        freq[ch - 'a']++;
    }
    for (int i = 0; i < (1 << MAXC); i++)
    {
        for (int j = 0; j < MAXC; j++)
        {
            if (!(i & (1 << j)))
                continue;
            bal[i] += freq[j];
        }
    }
    bool valid = true;
    bal[(1 << MAXC) - 1] -= n - m;
    fill(bits, bits + n, (1 << MAXC) - 1);
    for (int i = 0; i < m; i++)
    {
        int pos;
        string t;
        cin >> pos >> t;
        int mask = 0;
        for (char ch : t)
        {
            mask |= 1 << (ch - 'a');
        }
        for (int j = 0; j < (1 << MAXC); j++)
        {
            if ((j & mask) != mask)
                continue;
            bal[j]--;
            if (bal[j] < 0)
                valid = false;
        }
        bits[pos - 1] = mask;
    }
    if (!valid)
    {
        cout << "Impossible\n";
        return 0;
    }
    stringstream ss;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < (1 << MAXC); j++)
        {
            if ((j & bits[i]) == bits[i])
                bal[j]++;
        }
        int key = 0;
        while (1)
        {
            bool good = true;
            for (int k = 0; k < (1 << MAXC); k++)
            {
                if (!(k & (1 << key)))
                    continue;
                bal[k]--;
                if (bal[k] < 0)
                    good = false;
            }
            if ((bits[i] & (1 << key)) && good)
                break;
            for (int k = 0; k < (1 << MAXC); k++)
            {
                if (!(k & (1 << key)))
                    continue;
                bal[k]++;
            }
            key++;
        }
        ss << (char) ('a' + key);
    }
    cout << ss.str() << "\n";
    return 0;
}