#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1E5;
const int MAXL = 1E6;
string words[MAXN];
char ans[MAXL + 5];
int pi[MAXL + 5];

char getC(string &word, int index, int n, int cur)
{
    if (index < n / 2)
        return word[index];
    if (index == n / 2)
        return '#';
    int start = cur - n / 2 + 1;
    return ans[start + (index - n / 2) - 1  ];
}

void solve(string &word, int &cur)
{
    int n = min((int) word.length(), cur + 1) * 2 + 1;
    for (int i = 1; i < n; i++)
    {
        int j = pi[i - 1];
        while (j > 0 && getC(word, i, n, cur) != getC(word, j, n, cur))
            j = pi[j - 1];
        if (getC(word, i, n, cur) == getC(word, j, n, cur))
            j++;
        pi[i] = j;
    }
    for (int i = pi[n - 1]; i < word.length(); i++)
    {
        cur++;
        ans[cur] = word[i];
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> words[i];
    }
    int cur = -1;
    for (int i = 0; i < (int) words[0].length(); i++)
    {
        cur++;
        ans[cur] = words[0][i];
    }
    for (int i = 1; i < n; i++)
    {
        solve(words[i], cur);
    }
    stringstream ss;
    for (int i = 0; i <= cur; i++)
    {
        ss << ans[i];
    }
    cout << ss.str() << endl;

    return 0;
}