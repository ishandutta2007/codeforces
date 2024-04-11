#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <bitset>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    vector <int> a(n);
    bool f = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] == 1)
            f = 1;
    }
    if (!f)
        cout << 0;
    else
    {
        int kol = 0;
        int i = 0;
        for (; a[i] == 0; i++) {}
        int j = n - 1;
        for (; a[j] == 0; j--) {}
        for (int w = i; w <= j;)
            if (a[w] == 1)
            {
                kol++;
                w++;
            }
            else
            {
                int kol1 = 0;
                for (; a[w] == 0; kol1++, w++) {}
                if (kol1 == 1)
                    kol++;
            }
        cout << kol;
    }
    return 0;
}