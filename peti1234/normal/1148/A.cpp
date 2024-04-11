#include <bits/stdc++.h>

using namespace std;
long long a, b, c;
int main()
{
    cin >> a >> b >> c;
    cout << 2*(min(a, b)+c)+(a!=b) << "\n";
    return 0;
}