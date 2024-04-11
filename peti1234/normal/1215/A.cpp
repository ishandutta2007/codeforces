#include <bits/stdc++.h>

using namespace std;
int a1, a2, k1, k2, n;
int main()
{
    cin >> a1 >> a2 >> k1 >> k2 >> n;
    cout << max(0, n-a1*(k1-1)-a2*(k2-1)) << " ";
    if (k1>k2) {
        swap(k1, k2);
        swap(a1, a2);
    }
    int db=0;
    while (a1 && n>=k1) {
        n-=k1, a1--, db++;
    }
    while (a2 && n>=k2) {
        n-=k2, a2--, db++;
    }
    cout << db << "\n";
    return 0;
}