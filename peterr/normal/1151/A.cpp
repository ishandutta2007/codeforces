#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    string s;
    cin >> n >> s;
    int best = 200;
    for (int i = 0; i + 3 < n; i++)
    {
        int cost = 0;
        cost += min(s[i] - 'A', 26 - (s[i] - 'A'));
        cost += min(abs(s[i+1] - 'C'), 26 - abs(s[i+1] - 'C'));
        cost += min(abs(s[i+2] - 'T'), 26 - abs(s[i+2] - 'T'));
        cost += min(abs(s[i+3] - 'G'), 26 - abs(s[i+3] - 'G'));
        best = min(best, cost);
    }
    cout << best;
    return 0;
}