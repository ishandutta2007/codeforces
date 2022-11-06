#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100;
string q[MAXN * (MAXN + 1) / 2];
int freq[MAXN + 1][26];
int ans[MAXN + 1];
int cnt[26];
pair<int, int> poss[MAXN + 1];

int query(int l, int r)
{
    cout << "? " << l << " " << r << endl;
    cout.flush();
    int len = r - l + 1;
    for (int i = 0; i < len * (len + 1) / 2; i++)
    {
        cin >> q[i];
    }
    return len * (len + 1) / 2;
}

void printAns(int n)
{
    cout << "! ";
    for (int i = 1; i <= n; i++)
        cout << (char) (ans[i] + 'a');
    cout << endl;
    cout.flush();
}

int main()
{
    int n;
    cin >> n;
    if (n <= 3)
    {
        for (int i = 1; i <= n; i++)
        {
            query(i, i);
            ans[i] = q[0][0] - 'a';
        }
        printAns(n);
    }
    else
    {
        int len = query(1, n);
        for (int i = 0; i < len; i++)
        {
            string t = q[i];
            int m = (int) t.length();
            for (int j = 0; j < m; j++)
            {
                freq[m][t[j] - 'a']++;
            }
        }
        for (int i = (n + 1) / 2; i > 1; i--)
        {
            bool flag = false;
            for (int j = 0; j < 26; j++)
            {
                if (freq[i][j] - freq[i - 1][j] - cnt[j] == 2)
                {
                    poss[i].first = poss[i].second = j;
                }
                else if (freq[i][j] - freq[i - 1][j] - cnt[j] == 1)
                {
                    if (!flag)
                    {
                        flag = true;
                        poss[i].first = j;
                    }
                    else
                    {
                        poss[i].second = j;
                    }
                }
            }
            cnt[poss[i].first]++;
            if (n % 2 == 0 || i != (n + 1) / 2)
            {
                cnt[poss[i].second]++;
            }
            //cout << i << " " << poss[i].first << " " << poss[i].second << endl;
        }
        if (n % 2 != 0)
            poss[(n + 1) / 2].second = poss[(n + 1) / 2].first;
        bool flag2 = false;
        for (int i = 0; i < 26; i++)
        {
            if (freq[1][i] - cnt[i] == 2)
                poss[1].first = poss[1].second = i;
            else if (freq[1][i] - cnt[i] == 1)
            {
                if (!flag2)
                {
                    flag2 = true;
                    poss[1].first = i;
                }
                else
                    poss[1].second = i;
            }
        }
        //cout << 1 << " " << poss[1].first << " " << poss[1].second << endl;
        for (int i = 1; i <= n; i++)
            fill(freq[i], freq[i] + 26, 0);
        len = query(1, (n + 1) / 2);
        for (int i = 0; i < len; i++)
        {
            string t = q[i];
            int m = (int) t.length();
            for (int j = 0; j < m; j++)
                freq[m][t[j] - 'a']++;
        }
        len = query(2, (n + 1) / 2);
        for (int i = 0; i < len; i++)
        {
            string t = q[i];
            int m = (int) t.length();
            for (int j = 0; j < m; j++)
                freq[m][t[j] - 'a']--;
        }
        for (int i = 1; i <= (n + 1) / 2; i++)
        {
            for (int j = 0; j < 26; j++)
            {
                if (freq[i][j])
                {
                    ans[i] = j;
                    for (int k = i + 1; k <= (n + 1) / 2; k++)
                        freq[k][j]--;
                }
            }
        }
        for (int i = 0; 1 + i < n - i; i++)
        {
            if (ans[i + 1] == poss[i + 1].first)
                ans[n - i] = poss[i + 1].second;
            else
                ans[n - i] = poss[i + 1].first;
        }
        printAns(n);
    }
    return 0;
}