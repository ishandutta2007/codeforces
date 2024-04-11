#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2E5;
int freq[MAXN + 1];
int c[MAXN + 1];
int amt[MAXN + 1];
vector<int> rooms[MAXN];

bool check(int x, int k)
{
    fill(amt, amt + x, 0);
    int ptr = 0;
    for (int i = k; i >= 1; i--)
    {
        if (i < k && c[i] > c[i + 1])
            ptr = 0;
        for (int j = 0; j < freq[i]; j++)
        {
            while (ptr < x && amt[ptr] >= c[i])
                ptr++;
            if (ptr < x)
                amt[ptr]++;
            else
                return false;
        }
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        freq[x]++;
    }
    for (int i = 1; i <= k; i++)
        cin >> c[i];
    int ans = 0;
    for (int jump = n / 2 + 1; jump > 0; jump /= 2)
    {
        while (ans + jump <= n && !check(ans + jump, k))
            ans += jump;
    }
    ans++;
    cout << ans << "\n";
    fill(amt, amt + ans, 0);
    int ptr = 0;
    for (int i = k; i >= 1; i--)
    {
        if (i < k && c[i] > c[i + 1])
            ptr = 0;
        for (int j = 0; j < freq[i]; j++)
        {
            while (ptr < ans && amt[ptr] >= c[i])
                ptr++;
            amt[ptr]++;
            rooms[ptr].push_back(i);
        }
    }
    for (int i = 0; i < ans; i++)
    {
        int s = (int) rooms[i].size();
        cout << s << " ";
        for (int j = 0; j < s; j++)
            cout << rooms[i][j] << " \n"[j == s - 1];
    }
    return 0;
}