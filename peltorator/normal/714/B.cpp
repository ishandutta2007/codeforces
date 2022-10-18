#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <cstdio>
#include <math.h>
#include <set>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> a;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        bool ok = true;
        for (int j = 0; j < a.size(); j++)
            if (a[j] == k)
                ok = false;
        if (ok)
        {
            a.push_back(k);
            if (a.size() > 3)
            {
                cout << "NO";
                return 0;
            }
        }
    }
    sort(a.begin(), a.end());
    if (a.size() < 3)
    {
        cout << "YES";
        return 0;
    }
    if (a[2] - a[1] == a[1] - a[0])
        cout << "YES";
    else
        cout << "NO";
    return 0;
}