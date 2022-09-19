#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    long long n, m;
    cin >> n >> m;
    cout << (m==1 ? n-1 : n*(m-1)) << "\n";
    return 0;
}