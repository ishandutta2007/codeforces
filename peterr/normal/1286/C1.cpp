#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100;
string s[MAXN * (MAXN + 1) / 2];
int freq[MAXN + 1][26];
pair<int, int> sud1[MAXN + 1];
pair<int, int> sud2[MAXN + 1];
int cnt[26];
char ans[MAXN + 1];

int calc(int l, int r)
{
    int len = r - l + 1;
    return len * (len + 1) / 2;
}

int query(int l, int r)
{
    cout << "? " << l << " " << r << endl;
    cout.flush();
    for (int i = 0; i < calc(l, r); i++)
    {
        cin >> s[i];
    }
    return calc(l, r);
}

void process(int len, pair<int, int> sud[MAXN + 1])
{
    for (int i = 1; i <= MAXN; i++)
        fill(freq[i], freq[i] + 26, 0);
    int n = 0;
    for (int i = 0; i < len; i++)
    {
        string t = s[i];
        int m = (int) t.length();
        n = max(n, m);
        for (int j = 0; j < m; j++)
        {
            freq[m][t[j] - 'a']++;
        }
    }
    fill(cnt, cnt + 26, 0);
    if (n % 2 != 0)
    {
        int half = (n + 1) / 2;
        for (int j = 0; j < 26; j++)
        {
            if (freq[half][j] - freq[half - 1][j] == 1)
            {
                sud[half].first = sud[half].second = j;
                cnt[j]++;
            }
        }
    }
    for (int i = n / 2; i > 1; i--)
    {
        bool flag = false;
        for (int j = 0; j < 26; j++)
        {
            if (freq[i][j] - freq[i - 1][j] - cnt[j] == 1)
            {
                if (!flag)
                {
                    flag = true;
                    sud[i].first = j;
                }
                else
                {
                    sud[i].second = j;
                }
            }
            else if (freq[i][j] - freq[i - 1][j] - cnt[j] == 2)
            {
                sud[i].first = sud[i].second = j;
            }
        }
        cnt[sud[i].first]++;
        cnt[sud[i].second]++;
    }
    bool ff = false;
    for (int j = 1; j <= 26; j++)
    {
        if (freq[n][j] - cnt[j] == 1)
        {
            if (!ff)
            {
                sud[1].first = j;
                ff = true;
            }
            else
            {
                sud[1].second = j;
            }
        }
        else if (freq[n][j] - cnt[j] == 2)
        {
            sud[1].first = sud[1].second = j;
        }
    }
}

char resolve(char prev, int x, bool bot, int n)
{
    int ind = 1;
    if (bot)
    {
        ind = x;
    }
    else
    {
        ind = n - x;
    }
    int key = prev - 'a';
    pair<int, int> sud[MAXN + 1] = bot ? sud1 : sud2;
    if (key == sud[ind].first)
    {
        return (char) (sud[ind].second + 'a');
    }
    return (char) (sud[ind].first + 'a');
}

int main()
{
    int n;
    cin >> n;
    if (n <= 3)
    {
        string theans = "";
        for (int i = 1; i <= n; i++)
        {
            query(i, i);
            theans += s[0];
        }
        cout << "! " << theans << endl;
        cout.flush();
    }
    else
    {
        int len = query(1, n);
        process(len, sud1);
        len = query(1, n - 1);
        process(len, sud2);
        /*
        for (int i = 1; i <= n / 2 + 1; i++)
        {
            cout << i << " " << sud2[i].first << " " << sud2[i].second << endl;
        }*/
        query(n, n);
        int left = 1;
        int right = n - 1;
        char prev = s[0][0];
        ans[n] = prev;
        while (left <= right)
        {
            ans[left] = resolve(prev, left, true, n);
            prev = ans[left];
            left++;
            if (left <= right)
            {
                ans[right] = resolve(prev, right, false, n);
                prev = ans[right];
                right--;
            }
        }
        stringstream ss;
        ss << "! ";
        for (int i = 1; i <= n; i++)
            ss << ans[i];
        cout << ss.str() << endl;
        cout.flush();
    }
    return 0;
}