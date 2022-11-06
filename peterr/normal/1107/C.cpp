#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2E5;
int hits[MAXN];
vector<vector<int>> vec;

int main()
{
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> hits[i];
    }
    string s;
    cin >> s;
    int ptr = 0;
    while (ptr < (int) s.length())
    {
        vector<int> v;
        int j = ptr;
        while (j < (int) s.length() && s[j] == s[ptr])
        {
            v.push_back(hits[j]);
            j++;
        }
        sort(v.rbegin(), v.rend());
        vec.push_back(v);
        ptr = j;
    }
    long long ans = 0;
    for (vector<int> v : vec)
    {
        for (int i = 0; i < min(k, (int) v.size()); i++)
        {
            ans += v[i];
        }
    }
    cout << ans << endl;
    return 0;
}