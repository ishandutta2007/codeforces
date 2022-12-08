#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    cout << min(n, m) << " " << (max(n, m) - min(n, m)) / 2;
}