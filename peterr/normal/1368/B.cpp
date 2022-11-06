#include <bits/stdc++.h>

using namespace std;

int freq[10];

int main()
{
    long long k;
    cin >> k;
    fill(freq, freq + 10, 1);
    int ind = 0;
    string s = "codeforces";
    int n = (int) s.length();
    long long ways = 1;
    while (ways < k)
    {
        ways /= freq[ind];
        freq[ind]++;
        ways *= freq[ind];
        ind++;
        if (ind == n)
            ind = 0;
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < freq[i]; j++)
            cout << s[i];
    cout << "\n";
    return 0;
}