#include <bits/stdc++.h>

using namespace std;

int main()
{
    //ifstream cin("a.in");
    //ofstream cout("a.out");
    ios::sync_with_stdio(0);
    int n;
    cin >> n;
    int a[50], b[50];
    for (int i = 0; i < n; i++)
        a[i] = 0, b[i] = 0;
    for (int i = 0; i < n * n; i++){
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        if (a[x] == 0 && b[y] == 0)
            a[x] = 1, b[y] = 1, cout << i + 1 << ' ';
    }
}