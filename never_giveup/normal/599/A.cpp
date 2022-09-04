#include <bits/stdc++.h>

using namespace std;

int main()
{
    //ifstream cin("a.in");
    //ofstream cout("a.out");
    ios::sync_with_stdio(0);
    long long a, b, c;
    cin >> a >> b >> c;
    cout << min(2 * a + 2 * b, min(2 * min(a, b) + 2 * c, a + b + c));
}