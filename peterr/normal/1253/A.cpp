#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100000;
int a[MAXN];
int b[MAXN];

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
        }
        int ptr = 0;
        while (ptr < n && a[ptr] == b[ptr])
            ptr++;
        bool valid = true;
        int k = ptr < n ? max(b[ptr] - a[ptr], 0) : 0;
        while (ptr < n)
        {
            if (b[ptr] == a[ptr] + k)
            {
                ptr++;
            }
            else if (a[ptr] == b[ptr])
            {
                break;
            }
            else
            {
                valid = false;
                break;
            }
        }
        while (ptr < n)
        {
            if (a[ptr] != b[ptr])
                valid = false;
            ptr++;
        }
        if (valid)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}