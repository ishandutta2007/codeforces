#include <bits/stdc++.h>

using namespace std;
int n, m;
int main()
{
    cin >> n >> m;
    for (int i=1; ; i++) {
        if (i==n+1) i=1;
        if (m<i) break;
        m-=i;
    }
    cout << m << "\n";
    return 0;
}