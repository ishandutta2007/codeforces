#include <bits/stdc++.h>

using namespace std;

int main()
{
    int w;
    cin >> w;
    while (w--) {
        int x;
        cin >> x;
        cout << (__builtin_popcount(x)==1 ? x+(x==1 ? 2 : 1) : (x & -x)) << "\n";
    }
    return 0;
}