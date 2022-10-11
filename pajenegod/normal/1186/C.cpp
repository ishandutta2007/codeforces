#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    string a, b;
    cin >> a >> b;

    int n = a.size();
    int m = b.size();

    vector<int> A;
    for (auto c : a)
        if (c == '0')
            A.push_back(0);
        else
            A.push_back(1);

    vector<int> B;
    for (auto c : b)
        if (c == '0')
            B.push_back(0);
        else
            B.push_back(1);

    int xorsum = 0;
    for (int i = 0; i < m; ++i)
        xorsum ^= A[i]^B[i];

    int ways = xorsum == 0;
    for (int i = m; i < n; ++i)
    {
        xorsum ^= A[i] ^ A[i - m];
        ways += xorsum == 0;
    }
    cout << ways;
}