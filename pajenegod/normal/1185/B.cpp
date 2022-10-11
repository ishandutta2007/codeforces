#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int cas = 0; cas < n; ++cas)
    {
        bool failed = false;
        string A,B;
        cin >> A >> B;
        
        int n = A.size();
        int m = B.size();

        int lasti = 0;
        int lastj = 0;
        while (lasti < n && lastj < m)
        {
            if (A[lasti] != B[lastj])
            {
                failed = true;
                break;
            }
            char c = A[lasti];
            int i = lasti;
            while (i<n && A[i] == c)
                ++i;

            int j = lastj;
            while (j<m && B[j] == c)
                ++j;
            
            if (i - lasti > j - lastj)
            {
                failed = true;
                break;
            }
            lasti = i;
            lastj = j;
        }

        if (lasti < n || lastj < m)
            failed = true;
        
        if (failed)
            cout << "NO\n";
        else
            cout << "YES\n";

    }
}