#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

char c[100000];

int main()
{
    //ifstream cin("a.in");
    //ofstream cout("a.out");
    ios::sync_with_stdio(0);
    int n, t, r = 0;
    string a, b;
    cin >> n >> t >> a >> b;
    int kol = 0;
    for (int i = 0; i < n; i++)
        if (a[i] != b[i])
            kol++;
        else
            kol += 2, r++;
    if (kol / 2 < n - t){
        cout << -1;
        return 0;
    }
    t = n - t;
    int x = t, y = t, xa = max(0, t - r), ya = xa;
    for (int i = 0;  i < n; i++)
        if (a[i] == b[i])
            if (x > 0 && y > 0)
                c[i] = a[i], x--, y--;
            else
                if (a[i] == 'a')
                    c[i] = 'b';
                else
                    c[i] = 'a';
        else
        if (xa > 0)
            c[i] = a[i], xa--;
        else
        if (ya > 0)
            c[i] = b[i], ya--;
        else
        if (a[i] == 'a' || b[i] == 'a')
            if (a[i] == 'b' || b[i] == 'b')
                c[i] = 'c';
            else
                c[i] = 'b';
        else
            c[i] = 'a';
    for (int i = 0; i < n; i++)
        cout << c[i];
}