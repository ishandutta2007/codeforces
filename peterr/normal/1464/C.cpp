#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1E5;
const int MAXC = 27;
int freq[MAXC];
int twopow[MAXC];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    twopow[0] = 1;
    for (int i = 1; i < MAXC; i++)
    {
        twopow[i] = twopow[i - 1] * 2;
    }
    int n;
    long long t;
    string s;
    cin >> n >> t >> s;
    long long sum = twopow[s[n - 1] - 'a'] - twopow[s[n - 2] - 'a'];
    for (int i = 0; i < n - 2; i++)
    {
        freq[s[i] - 'a']++;
        sum += twopow[s[i] - 'a'];
    }
    int ptr = MAXC - 1;
    while (ptr >= 0 && sum > t)
    {
        while (freq[ptr] && twopow[ptr + 1] + t <= sum)
        {
            freq[ptr]--;
            sum -= twopow[ptr + 1];
        }
        ptr--;
    }
    if (sum == t)
        cout << "Yes\n";
    else
        cout << "No\n";
    return 0;
}