#include <bits/stdc++.h>

using namespace std;

const int MAXN = 50;
int freq[MAXN + 1];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        freq[x]++;
    }
    for (int i = 1; i <= MAXN; i++)
    {
        if (freq[i] > 0)
        {
            if (freq[i] <= n / 2)
                cout << "Alice" << endl;
            else
                cout << "Bob" << endl;
            break;
        }
    }
    return 0;
}