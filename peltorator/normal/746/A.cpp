#include <bits/stdc++.h>

typedef long long ll;
using namespace std;



int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    b /= 2;
    c /= 4;
    cout << min(a, min(b, c)) * 7;
    return 0;
}