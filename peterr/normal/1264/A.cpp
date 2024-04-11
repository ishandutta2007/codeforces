#include <bits/stdc++.h>

using namespace std;

const int MAXN = 4E5;
int p[MAXN];

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> p[i];
        int g, s, b;
        vector<int> freq;
        for (int i = 0; i < n; )
        {
            int cnt = 0;
            int j = i;
            while (j < n && p[j] == p[i])
            {
                j++;
                cnt++;
            }
            freq.push_back(cnt);
            i = j;
        }
        int suf = 0;
        while (!freq.empty() && suf < (n + 1) / 2)
        {
            suf += freq[freq.size() - 1];
            freq.pop_back();
        }
        if (freq.empty())
        {
            cout << 0 << " " << 0 << " " << 0 << endl;
            continue;
        }
        g = freq[0];
        int ptr = 1;
        s = b = 0;
        while (ptr < (int) freq.size() && s <= g)
        {
            s += freq[ptr++];
        }
        while (ptr < (int) (freq.size()))
        {
            b += freq[ptr++];
        }
        if (s > g && b > g)
        {
            cout << g << " " << s << " " << b << endl;
        }
        else
        {
            cout << 0 << " " << 0 << " " << 0 << endl;
        }
    }
    return 0;
}